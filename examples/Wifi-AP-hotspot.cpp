#include <Arduino.h>
#include <WiFi.h>

// put function declarations here:
#define LED 2

const char * ssid = "ESP32_Dev";
const char * password = "1234567890";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // set up hot spot
  WiFi.softAP(ssid, password);
  
  Serial.println("WiFi IP: ");
  Serial.println(WiFi.softAPIP());

}

void loop() {
  // put your main code here, to run repeatedly:  
  
}

// put function definitions here:
