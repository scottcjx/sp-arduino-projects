# Projects

## Content
1. [Blink](#Blink)
2. [Make Some Noise](#Make-Some-Noise)
3. [Servo](#Servo)

### Blink
``` c
#define LED_PIN 13
#define BTN_PIN 2

#define BLINK_TIMES 5           
#define BLINK_DELAY 500         // smaller number faster

void setup()
{
    // Start serial connection
    Serial.begin(9600);
    // Configure pin 2 as an input and enable the internal pull-up resistor
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    // Read the pushbutton value into a variable 
    int sensorVal = digitalRead(BTN_PIN);

    // Print out the value of the pushbutton Serial.
    println(sensorVal);
    // Keep in mind the pull-up means the pushbutton's logic is inverted. 
    // It goes HIGH when it's open, and LOW when it's pressed.
    // Turn on pin LED_PIN when the button's pressed, and off when it's not:
    if (sensorVal == HIGH) 
    {
        digitalWrite(LED_PIN, LOW);
    } 
    else
    {
        // Blink pin LED_PIN for 5 times 
        for (int i = 0; i < BLINK_TIMES; i++)
        {
            digitalWrite(LED_PIN, HIGH); // Turn on the LED 
            delay(BLINK_DELAY); // Wait for half a second 
            digitalWrite(LED_PIN, LOW); // Turn off the LED
            delay(BLINK_DELAY); // Wait for half a second
        }
    }
    // After blinking 5 times, turn off the LED digitalWrite(LED_PIN, LOW);
}
```

### Make Some Noise
``` c
#include "pitches.h"

#define LED_PIN 13
#define BZR_PIN 8
#define BTN_PIN 2

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BZR_PIN, OUTPUT);
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(BTN_PIN);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {}
  else 
  {
    for (int i = 0; i < 8; i++)
    {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[i];
      tone(BZR_PIN, melody[i], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(BZR_PIN);
    }
  }
}
```
### Servo
``` c
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
```