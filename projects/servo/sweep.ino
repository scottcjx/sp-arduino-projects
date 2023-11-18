#include <Servo.h>

#define LED_PIN 13
#define BTN_PIN 2
#define SRV_PIN 9

#define MOVEFAST_DELAY 5
#define MOVEFAST_STEPS 5
#define MOVESLOW_DELAY 10
#define MOVESLOW_STEPS 1

Servo myservo;
int pos = 0;

void setup() 
{
  myservo.attach(SRV_PIN);

  // move servo to 20 deg (fast)
  for (; pos < 20; pos += MOVEFAST_STEPS)
  {
    myservo.write(pos);
    delay(MOVEFAST_DELAY);
  }
}

void loop()
{
  // Move Slowly from 20deg -> 150deg -> 20deg

  // Move from 20 degrees to 150 degrees slowly
  for (; pos < 150; pos += MOVESLOW_STEPS)
  {
    myservo.write(pos);
    delay(MOVESLOW_DELAY);
  }

  // Move from 150 degrees to 20 degrees slowly
  for (; pos > 20; pos -= MOVESLOW_STEPS)
  {
    myservo.write(pos);
    delay(MOVESLOW_DELAY);
  }

  // Move Fast from 20deg -> 150deg -> 20deg
  // Move from 20 degrees to 150 degrees quickly
  for (; pos < 150; pos += MOVEFAST_STEPS)
  {
    myservo.write(pos);
    delay(MOVEFAST_DELAY);
  }

  // Move from 150 degrees to 20 degrees quickly
  for (; pos > 20; pos -= MOVEFAST_STEPS)
  {
    myservo.write(pos);
    delay(MOVEFAST_DELAY);
  }
}