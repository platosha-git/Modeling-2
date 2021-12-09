#include <iostream>
#include <vector>
#include <random>
#include "generator.h"

using namespace std;

Generator::Generator(const int numMsg, const int numRepeat) :
    numMessages(numMsg), perRepeat(numRepeat),
    generator(rd()),
    a(0), b(0),
    lambda(0)
{

}

void Generator::setEvenDistribution(float _a, float _b)
{
    a = _a;
    b = _b;
}

void Generator::setPoissonDistribution(float _lambda)
{
    lambda = _lambda;
}

double Generator::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(generator);
    return num;
}

int Generator::poisson()
{
    poisson_distribution<int> dist(lambda);
    int num = dist(generator);
    return num;
}

void addMessage(vector<vector<double>> &queue, vector<double> event)
{
    size_t i = 0;
    while (i < queue.size() && queue[i][0] < event[0]) {
        i++;
    }

    if (0 < i  && i < queue.size()) {
        queue.insert(queue.begin() + i - 1, event);
    }
    else {
        queue.insert(queue.begin() + i, event);
    }
}

int Generator::eventTime()
{
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 100);

    int processedMsg = 0;
    int curLen = 0, maxLen = 0;

    vector<vector<double>> queue = {{even(), 'g'}};
    bool waiting = true, processing = false;

    while (processedMsg < numMessages) {
        vector<double> event = queue[0];
        queue.erase(queue.begin());

        if (event[1] == 'g') {
            curLen++;
            if (curLen > maxLen) {
                maxLen = curLen;
            }

            addMessage(queue, {event[0] + even(), 'g'});
            if (waiting) {
                processing = true;
            }
        }

        else if (event[1] == 'p') {
            processedMsg++;

            if (uni(rng) <= perRepeat) {
                curLen++;
            }
            processing = true;
        }

        if (processing) {
            if (curLen > 0) {
                curLen--;
                addMessage(queue, {event[0] + poisson(), 'p'});
                waiting = false;
            }
            else {
                waiting = true;
            }
            processing = false;
        }
    }

    return maxLen;
}

int Generator::iterTime(double step)
{
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 100);

    int processed_tasks = 0;
    double t_curr = step;
    float t_gen = poisson();

    double t_gen_prev = 0, t_proc = 0;
    int cur_queue_len = 0, max_queue_len = 0;
    bool free = true;

    while (processed_tasks < numMessages) {
        if (t_curr > t_gen) {
            cur_queue_len++;
            if (cur_queue_len > max_queue_len) {
                max_queue_len = cur_queue_len;
            }
            t_gen_prev = t_gen;
            t_gen += poisson();
        }

        if (t_curr > t_proc) {
            if (cur_queue_len > 0) {
                bool was_free = free;
                if (free) {
                    free = false;
                }
                else {
                    processed_tasks++;
                    if (uni(rng) <= perRepeat) {
                        cur_queue_len++;
                    }
                }
                cur_queue_len--;
                if (was_free) {
                    t_proc = t_gen_prev + poisson();
                }
                else {
                    t_proc += poisson();
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
