#include "pitches.h"

#define LED_PIN 13
#define BZR_PIN 8
#define BTN_PIN 2

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BZR_PIN, OUTPUT);
}

void loop() {
  int sensorVal = digitalRead(BTN_PIN);
  Serial.println(sensorVal);

  if (sensorVal == LOW)
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