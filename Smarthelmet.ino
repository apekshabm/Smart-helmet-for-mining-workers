#define BLYNK_TEMPLATE_NAME "Test"
#define BLYNK_AUTH_TOKEN "I7WYWEsJdlbShwYtvGVyTQk3O15Q_wM6"
#define BLYNK_TEMPLATE_ID "TMPL3NT5lM99V"
#include <DHT.h>
#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_tockn.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
MPU6050 mpu(Wire);
#define DHTPIN 4 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
const int switchPin = 2;
const int ledPin = 13;
// Replace with your actual Wi-Fi credentials
char ssid[] = "G 5G";
char pass[] = "12345678";
// Replace with your Blynk Auth Token
char auth[] = "I7WYWEsJdlbShwYtvGVyTQk3O15Q_wM6";
// Define the GPIO pin connected to the MQ-7 sensor's analog output
const int mq7_pin = 33; // Using GPIO 34 (A2)
const int mq2_pin = 34;
BlynkTimer timer;
void setup() {
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
timer.setInterval(1000L, readSensor1);
timer.setInterval(1000L, readSensor2); // Read sensor every second
timer.setInterval(1000L, readSensor3);
timer.setInterval(1000L, readSensor4);
timer.setInterval(1000L, readSensor5);
}
void loop() {
Blynk.run();
timer.run();
}
void readSensor1()
{
int sensor_value1 = analogRead(mq7_pin);

Convert the sensor value to a voltage (optional)
float voltage2 = (sensor_value2 *100)/4095;
Serial.print("Sensor Value2: ");
Serial.print(sensor_value2);
Serial.print(" (");
Serial.print(voltage2);
Serial.println(" V)");
delay(1000);
Blynk.virtualWrite(V1, voltage2);
}
void readSensor3()
{
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from DHT sensor!");
return;
}
Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" *C ");
delay(1000);
Blynk.virtualWrite(V2, h);
Blynk.virtualWrite(V3, t);
}
void readSensor4()
{
int switchState = digitalRead(switchPin);
// Print the switch state to the serial monitor
Serial.print("Switch state: ");
Serial.println(switchState);
delay(1000);
Blynk.virtualWrite(V4, switchState);
}
}
