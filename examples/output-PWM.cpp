#include <Arduino.h>
#include <esp32-hal-ledc.h>

#define pwmChannel  0 // Selects channel 0
#define frequence   1000 // PWM frequency of 1 KHz
#define resolution  8 // 8-bit resolution, 256 possible values, different voltages
#define pwmPin      23

void setup(){
    // Configuration of channel 0 with the chosen frequency and resolution
    ledcSetup(pwmChannel, frequence, resolution);

    // Assigns the PWM channel to pin 23
    ledcAttachPin(pwmPin, pwmChannel);

    // Create the selected output voltage
    ledcWrite(pwmChannel, 127); // 1.65 V
}

void loop(){
}