#include <Arduino.h>
#include <timer/timer.h>

struct SignalFormat
{
    uint16_t startDelay;
    uint16_t duration;
};

class Button
{
private:
    Timer* controlTimer;
    Timer* buttonTimer;

    uint8_t buttonPin;
    uint8_t controlPin;
    SignalFormat buttonSignal;
    SignalFormat controlSignal;

    bool isOutput = false;
    bool prevButtonState = false;

public:
    Button(uint8_t buttonPin, uint8_t controlPin, SignalFormat buttonSignal, SignalFormat controlSignal);
    void init();
    void tick();
    void click();
    ~Button();
};
