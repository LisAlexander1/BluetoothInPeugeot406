#include "timer.h"

Timer::Timer(unsigned long time, unsigned long start_delay): time(time), start_delay(start_delay)
{
}

void Timer::start()
{
    start_millis = millis();
}
bool Timer::isExpired()
{
    return (millis() - start_millis > start_delay + time);
}

bool Timer::isNotStarted()
{
    return (millis() - start_millis < start_delay);
}


Timer::~Timer()
{
}