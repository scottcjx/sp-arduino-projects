
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

    // Print out the value of the pushbutton Serial.println(sensorVal);
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