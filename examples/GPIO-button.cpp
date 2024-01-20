#include <Arduino.h>
// put function declarations here:

bool led_logic = false;
bool led_state = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(18, OUTPUT);
  pinMode(14, INPUT_PULLDOWN); // set a pull-down resistor
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(14)){
    delay(50); // software solution to debounce, hardware solution would be adding a capacitor as debouncer
    if(digitalRead(14) && !led_state){
      led_logic = !led_logic;
      digitalWrite(18, led_logic);
      led_state = !led_state;
    }
    else if(!digitalRead(14)){
      led_state = false;
    }  
  }

}

// put function definitions here:





