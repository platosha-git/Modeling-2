#include <iostream>
#include <vector>
#include <random>
#include "generator.h"

using namespace std;

Generator::Generator() :
    generator(rd()),
    a(0), b(0),
    mu(0), sigma(0)
{

}

void Generator::setEvenDistribution(float _a, float _b)
{
    a = _a;
    b = _b;
}

void Generator::setNormalDistribution(double _mu, double _sigma)
{
    mu = _mu;
    sigma = _sigma;
}

double Generator::even()
{
    uniform_real_distribution<double> distribution(a, b);
    double num = distribution(generator);

    return num;
}

double Generator::normal()
{
    mt19937 gen{rd()};
    normal_distribution<> d{mu, sigma};
    return d(gen);
}

void add_event(vector<vector<double>> &events, vector<double> event)
{
    size_t i = 0;
    while (i < events.size() && events[i][0] < event[0]) {
        i++;
    }

    if (0 < i  && i < events.size()) {
        events.insert(events.begin() + i - 1, event);
    }
    else {
        events.insert(events.begin() + i, event);
    }
}

int Generator::eventTime(int total_tasks, int repeat)
{
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 100);

    int processed_tasks = 0;
    int cur_queue_len = 0, max_queue_len = 0;

    vector<vector<double>> events = {{even(), 'g'}};
    bool free = true, process_flag = false;

    while (processed_tasks < total_tasks) {
        vector<double> event = events[0];
        events.erase(events.begin());
        if (event[1] == 'g') {
            cur_queue_len++;
            if (cur_queue_len > max_queue_len) {
                max_queue_len = cur_queue_len;
            }
            add_event(events, {event[0] + even(), 'g'});
            if (free) {
                process_flag = true;
            }
        }

        else if (event[1] == 'p') {
            processed_tasks++;

            if (uni(rng) <= repeat) {
                cur_queue_len++;
            }
            process_flag = true;
        }

        if (process_flag) {
            if (cur_queue_len > 0) {
                cur_queue_len--;
                add_event(events, {event[0] + normal(), 'p'});
                free = false;
            }
            else {
                free = true;
            }
            process_flag = false;
        }
    }

    return max_queue_len;
}

int Generator::stepTime(int total_tasks, int repeat, double step)
{
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 100);

    int processed_tasks = 0;
    double t_curr = step;
    float t_gen = normal();

    double t_gen_prev = 0, t_proc = 0;
    int cur_queue_len = 0, max_queue_len = 0;
    bool free = true;

    while (processed_tasks < total_tasks) {
        if (t_curr > t_gen) {
            cur_queue_len++;
            if (cur_queue_len > max_queue_len) {
                max_queue_len = cur_queue_len;
            }
            t_gen_prev = t_gen;
            t_gen += normal();
        }

        if (t_curr > t_proc) {
            if (cur_queue_len > 0) {
                bool was_free = free;
                if (free) {
                    free = false;
                }
                else {
                    processed_tasks++;
                    if (uni(rng) <= repeat) {
                        cur_queue_len++;
                    }
                }
                cur_queue_len--;
                if (was_free) {
                    t_proc = t_gen_prev + normal();
                }
                else {
                    t_proc += normal();
                }
            }
            else {
                free = true;
            }
        }
        t_curr += step;
    }

    return max_queue_len;
}
