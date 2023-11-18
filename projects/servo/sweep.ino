#include <Servo.h>

#define LED_PIN 13
#define BTN_PIN 2
#define SRV_PIN 9

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() 
{
  myservo.attach(SRV_PIN);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  // Move from 20 degrees to 150 degrees slowly
  for (pos = 20; pos <= 150; pos += 1)
  {
    myservo.write(pos);     // tell servo to go to position in variable 'pos'
    delay(10);              // waits 10ms for the servo to reach the position
  }

  // Move from 150 degrees to 20 degrees slowly
  for (pos = 150; pos >= 20; pos -= 1)
  {
    myservo.write(pos);     // tell servo to go to position in variable 'pos'
    delay(10);              // waits 10ms for the servo to reach the position
  }

  // Move from 20 degrees to 150 degrees rapidly
  for (pos = 20; pos <= 150; pos += 5)
  {
    myservo.write(pos);     // tell servo to go to position in variable 'pos'
    delay(5);               // waits 5ms for the servo to reach the position
  }
}