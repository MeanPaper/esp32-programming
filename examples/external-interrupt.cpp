#include <Arduino.h>
// put function declarations here:

#define LED_PIN 18 
#define BUTTON 4

// define a volatile variable
volatile bool flag = false;

void handle_button_irt(){
  flag = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLDOWN);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), handle_button_irt, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(flag){
    delay(50);
    Serial.println("button click");
    digitalWrite(LED_PIN, HIGH);
    delay(2000);  // not ideal, bc it is blocking
    digitalWrite(LED_PIN, LOW);
    flag = false;
  }
}

// put function definitions here:
