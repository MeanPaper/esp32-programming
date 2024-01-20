#include <Arduino.h>

#define BLUE_LED 2

// put function declarations here:


void setup() {
    // put your setup code here, to run once:

    /* pinMode(uint8_t pin, uint8_t mode);
     * 
     * pin: specifies the GPIO pin on the board
     * mode: set the pin to be INPUT or OUTPUT
     * 
     * */    
    pinMode(BLUE_LED, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:

    /**
     * digitalWire(uint8_t pin, uint8_t val);
     * 
     * pin: GPIO pin
     * val: a specific val for the output
     * 
    */
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);  // delay(val), the val is in miliseconds
    digitalWrite(BLUE_LED, LOW);
    delay(1000);

}

// put function definitions here:
