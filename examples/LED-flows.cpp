#include <Arduino.h>

int pins[4] = {13, 12, 14, 27};
// int num_pins = sizeof(pins) / sizeof(int);

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  
  // set up all the pins to be outputs
  for(int p: pins){
    pinMode(p, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // light up the LEDs in order
  for(int p: pins){
    digitalWrite(p, HIGH);
    delay(100);
  }

  // turn off the LEDs in order
  for(int p: pins){
    digitalWrite(p, LOW);
    delay(100);
  }

}

// put function definitions here: