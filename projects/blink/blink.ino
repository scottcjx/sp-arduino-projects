#define LED_PIN 13
#define BTN_PIN 2

#define BLINK_TIMES 5           
#define BLINK_DELAY 500         // smaller number faster

void setup()
{
    Serial.begin(9600);
    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    int sensorVal = digitalRead(BTN_PIN);
    println(sensorVal);
    if (sensorVal == HIGH) 
    {
        digitalWrite(LED_PIN, LOW);
    } 
    else
    {
        for (int i = 0; i < BLINK_TIMES; i++)
        {
            digitalWrite(LED_PIN, HIGH); 
            delay(BLINK_DELAY); 
            digitalWrite(LED_PIN, LOW);
            delay(BLINK_DELAY);
        }
    }
}