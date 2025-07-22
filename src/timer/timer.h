#include "Arduino.h"

class Timer
{
private:
    unsigned long start_millis;
    unsigned long time;
    unsigned long start_delay;
public:
    Timer(unsigned long time, unsigned long start_delay = 0);
    void start();
    bool isExpired();
    bool isNotStarted();
    ~Timer();
};


