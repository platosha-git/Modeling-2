#include "computer.h"

using namespace std;

Computer::Computer(default_random_engine *re, vector<int> *_queue) :
    gnt(re),
    queue(_queue), maxLen(0),
    time(0), timer(0),
    busy(false)
{

}

void Computer::setTime(const double _time)
{
    time = _time;
}

bool Computer::serveClient(double dt)
{
    timer -= dt;

    if (queue->size() > maxLen) {
        maxLen = queue->size();
    }

    if (busy && timer <= 0) {
        busy = false;
        return true;
    }

    if (!busy && (*queue).size() != 0) {
        (*queue).erase((*queue).begin());
        timer = time;
        busy = true;
        return false;
    }

    return false;
}
