#include "button.h"

Button::Button(
    uint8_t buttonPin,
    uint8_t controlPin,
    SignalFormat buttonSignal,
    SignalFormat controlSignal) : buttonPin(buttonPin), controlPin(controlPin), buttonSignal(buttonSignal), controlSignal(controlSignal)
{
    controlTimer = new Timer(controlSignal.duration, controlSignal.startDelay);
    buttonTimer = new Timer(buttonSignal.duration, buttonSignal.startDelay);
}

void Button::tick()
{
    // Serial.println(digitalRead(buttonPin));
    if (!prevButtonState && !isOutput && digitalRead(buttonPin))
    {
        Serial.println("Next");
        controlTimer->start();
        buttonTimer->start();
        isOutput = true;
        pinMode(buttonPin, OUTPUT);
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
