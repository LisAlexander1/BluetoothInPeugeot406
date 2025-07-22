#include <Arduino.h>
#include <button/button.h>

#define NEXT_OUTPUT_PIN 6
#define PREV_OUTPUT_PIN 2
#define PAUSE_OUTPUT_PIN 10

#define NEXT_INPUT_PIN 7  // white-brown
#define PREV_INPUT_PIN 8  // brown
#define PAUSE_INPUT_PIN 9 // white-dark green

#define MOTOR_PIN 12 // dark green

Button nextButton = Button(NEXT_INPUT_PIN, NEXT_OUTPUT_PIN, {100, 100}, {100, 100}, "Next");
Button prevButton = Button(PREV_INPUT_PIN, PREV_OUTPUT_PIN, {100, 100}, {0, 100}, "Prev");
Button pauseButton = Button(PAUSE_INPUT_PIN, PAUSE_OUTPUT_PIN, {100, 100}, {0, 100}, "Pause");

void setup()
{
  
  nextButton.init();
  prevButton.init();
  pauseButton.init();
  Serial.begin(9600);

}

void loop()
{
  nextButton.tick();
  prevButton.tick();
  pauseButton.tick();
  // Serial.print("7:");
  // Serial.print(digitalRead(7)? 1 : 0);
  // Serial.print(",8:");
  // Serial.print(digitalRead(8)? 3 : 2);
  // Serial.print(",9:");
  // Serial.print(digitalRead(9)? 5 : 4);
  // Serial.println();
}
