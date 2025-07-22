#include <Arduino.h>
#include <button/button.h>

#define NEXT_OUTPUT_PIN 6
#define PREV_OUTPUT_PIN 2
#define PAUSE_OUTPUT_PIN 10

#define NEXT_INPUT_PIN 7  // white-brown
#define PREV_INPUT_PIN 8  // brown
#define PAUSE_INPUT_PIN 9 // white-dark green

#define MOTOR_PIN 12 // dark green

Button nextButton = Button(NEXT_INPUT_PIN, NEXT_OUTPUT_PIN, {100, 100}, {100, 100});
// Button prevButton = Button(NEXT_INPUT_PIN, NEXT_OUTPUT_PIN, {100, 100}, {0, 100});
// Button pauseButton = Button(NEXT_INPUT_PIN, NEXT_OUTPUT_PIN, {100, 100}, {0, 100});

void setup()
{
  nextButton.init();
  // prevButton.init();
  // pauseButton.init();
  Serial.begin(9600);
}

void loop()
{
  nextButton.tick();
  // prevButton.tick();
  // pauseButton.tick();
}
