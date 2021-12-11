#include "computer.h"

using namespace std;

Computer::Computer(default_random_engine *re, vector<int> *_queue) :
    gnt(re),
    queue(_queue),
    time(0), endTime(0),
    busy(false)
{

}

void Computer::setTime(const double _time)
{
    time = _time;
}

bool Computer::updateTime(double dt)
{
    endTime -= dt;

    if (busy && endTime <= 0) {
        busy = false;
        return true;
    }

    if (!busy && (*queue).size() != 0) {
        (*queue).erase((*queue).begin());
        endTime = time;
        busy = true;
    }

    return false;
}
