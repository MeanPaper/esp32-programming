#include <Arduino.h>
#include <Ticker.h>

// put function declarations here:

#define LED_PIN   18 
#define LED_ONCE  14

Ticker timer;
Ticker timer_once;

void toggle(int pin);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_ONCE, OUTPUT);
  
  // setting software timer
  timer.attach(0.5, toggle, LED_PIN);
  timer_once.once(3, toggle, LED_ONCE);


}

void loop() {
  // put your main code here, to run repeatedly:

}

// put function definitions here:
void toggle(int pin){
  digitalWrite(pin, !digitalRead(pin));
}