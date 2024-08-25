int SensorPin = A0;
void setup()
{
    pinMode(7, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int humedad = analogRead(SensorPin);
    Serial.println(humedad);
    if (humedad >= 460)
    {
        digitalWrite(7, LOW);
    }
    else
    {
        digitalWrite(7, HIGH);
    }
    delay(1000);
}