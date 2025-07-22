#include "button.h"

Button::Button(
    uint8_t buttonPin,
    uint8_t controlPin,
    SignalFormat buttonSignal,
    SignalFormat controlSignal,
    char* name) : buttonPin(buttonPin), controlPin(controlPin), buttonSignal(buttonSignal), controlSignal(controlSignal), name(name)
{
    controlTimer = new Timer(controlSignal.duration, controlSignal.startDelay);
    buttonTimer = new Timer(buttonSignal.duration, buttonSignal.startDelay);
    delayTimer = new Timer(1000);
}

void Button::tick()
{
    if (!prevButtonState && !isOutput && delayTimer->isExpired() && digitalRead(buttonPin) )
    {
        controlTimer->start();
        buttonTimer->start();
        delayTimer->start();
        isOutput = true;
        pinMode(buttonPin, OUTPUT);
        Serial.println(name);
    }

    if (isOutput)
    {

        if (!buttonTimer->isNotStarted() && !buttonTimer->isExpired())
        {
            digitalWrite(buttonPin, HIGH);
        }
        else if (buttonTimer->isExpired())
        {
            isOutput = false;
            pinMode(buttonPin, INPUT);
        }
        else
        {
            digitalWrite(buttonPin, LOW);
        }
    }

    if (controlTimer->isExpired() || controlTimer->isNotStarted())
        digitalWrite(controlPin, HIGH);
    else
        digitalWrite(controlPin, LOW);

    prevButtonState = digitalRead(buttonPin);
}


void Button::click()
{
    controlTimer->start();
    buttonTimer->start();
    isOutput = true;
}

void Button::init()
{
    pinMode(buttonPin, INPUT);
    pinMode(controlPin, OUTPUT);
    digitalWrite(controlPin, HIGH);
}

Button::~Button()
{
}
