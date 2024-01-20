#include <Arduino.h>
#include <esp32-hal-ledc.h>
// put function declarations here:

#define FREQ        2000
#define RESOLUTION  8
#define LED_PIN     18
#define CHANNEL     0

void setup() {
  // put your setup code here, to run once:
  ledcSetup(CHANNEL, FREQ, RESOLUTION);
  ledcAttachPin(LED_PIN, CHANNEL);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < pow(2, RESOLUTION); i++){
    ledcWrite(CHANNEL, i);
    delay(5);
  }
  for(int i = pow(2, RESOLUTION)-1; i >= 0; i--){
    ledcWrite(CHANNEL, i);
    delay(5);
  }
}

// put function definitions here:
