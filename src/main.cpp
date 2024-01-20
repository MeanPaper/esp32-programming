#include <Arduino.h>
#include <esp32-hal-ledc.h>
// put function declarations here:

#define LED_PIN 18

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256; i++){
    analogWrite(LED_PIN, i); // range [0,255]
    delay(10);
  }
  for(int i = 255; i >= 0; i--){
    analogWrite(LED_PIN, i); // range [0,255]
    delay(10);
  }
}

// put function definitions here:
