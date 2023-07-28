#include <Arduino.h>
#include "constants.h"

void ledStart()
{
  digitalWrite(13, LOW);

  for (int i = 0; i < 10; i++)
  {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
  }
}

void checkAndWaterPlant()
{
  int soilMoisture = analogRead(MOISTURE_SENSOR_PIN);

  if (soilMoisture > DRY_SOIL)
  {
    Serial.println("Watering plant");
    digitalWrite(WATER_PUMP_PIN, HIGH);
    digitalWrite(LED_PUMP_PIN, HIGH);
    delay(WATER_PUMP_DURATION);
    digitalWrite(WATER_PUMP_PIN, LOW);
    digitalWrite(LED_PUMP_PIN, LOW);
  }
  else
  {
    Serial.println("Plant is watered");
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(LED_START_PIN, OUTPUT);
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(WATER_PUMP_PIN, OUTPUT);
  pinMode(LED_PUMP_PIN, OUTPUT);

  ledStart();
}

void loop()
{
  checkAndWaterPlant();
  delay(1000);
}
