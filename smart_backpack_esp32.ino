// smart_backpack_esp32.ino
// ESP32 Firmware for Smart Backpack Sensor Reading and Control

#include <WiFi.h>
#include <Wire.h>

// Sensor pins
#define TEMP_SENSOR_PIN 34
#define HUMIDITY_SENSOR_PIN 35
#define AIR_QUALITY_SENSOR_PIN 32
#define WATER_SENSOR_PIN 33

// Actuator pins
#define HEATING_PAD_PIN 25
#define BUZZER_PIN 26

void setup() {
  Serial.begin(115200);

  // Initialize pins
  pinMode(TEMP_SENSOR_PIN, INPUT);
  pinMode(HUMIDITY_SENSOR_PIN, INPUT);
  pinMode(AIR_QUALITY_SENSOR_PIN, INPUT);
  pinMode(WATER_SENSOR_PIN, INPUT);

  pinMode(HEATING_PAD_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Smart Backpack ESP32 Initialized");
}

void loop() {
  int tempValue = analogRead(TEMP_SENSOR_PIN);
  int humidityValue = analogRead(HUMIDITY_SENSOR_PIN);
  int airQualityValue = analogRead(AIR_QUALITY_SENSOR_PIN);
  int waterSensorValue = analogRead(WATER_SENSOR_PIN);

  // Convert analog readings to usable values (dummy conversions)
  float temperature = map(tempValue, 0, 4095, -10, 50);  // Celsius approximation
  float humidity = map(humidityValue, 0, 4095, 0, 100);  // Percentage
  int airQuality = map(airQualityValue, 0, 4095, 0, 100); // Air quality scale 0-100
  bool waterLeak = waterSensorValue > 1000;              // Threshold for water detection

  Serial.printf("Temp: %.1f C, Humidity: %.1f%%, Air Quality: %d, Water Leak: %s\n",
                temperature, humidity, airQuality, waterLeak ? "YES" : "NO");

  // Control logic
  if (temperature < 15) {
    digitalWrite(HEATING_PAD_PIN, HIGH);  // Turn heating pad ON
  } else {
    digitalWrite(HEATING_PAD_PIN, LOW);   // Turn heating pad OFF
  }

  if (waterLeak) {
    digitalWrite(BUZZER_PIN, HIGH);       // Sound buzzer for water leakage
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(2000);  // 2 seconds delay between readings
}
