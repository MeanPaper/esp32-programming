#include <Arduino.h>
#include <esp32-hal-ledc.h>

#define FREQ      50    // 20ms for a period
#define CHANNEL   0
#define RESOL     8     // use 0 to (2^8)-1 to map to 0 to 180 degrees
#define SERVO     13    

// put function declarations here:

int calc_PWM(int degree){ 

  // duty cycle * (2 ^ resolution)
  int min_width = (0.5 / 20) * pow(2, RESOL); // 0 degree
  int max_width = (2.5 / 20) * pow(2, RESOL); // 180 degree
  
  // used the following to determine the time of high voltage in 20ms
  // [(max_width - min_width) * 50 / 100] + min_width
  
  return ((max_width - min_width) * degree / 180) + min_width;
}


void setup() {
  // put your setup code here, to run once:
  
  // setup channel
  ledcSetup(CHANNEL, FREQ, RESOL);
  
  // setup pins
  ledcAttachPin(SERVO, CHANNEL);

}

void loop() {
  // put your main code here, to run repeatedly:  
  for(int i = 0; i <= 180; i += 10){
    ledcWrite(CHANNEL, calc_PWM(i));
    delay(1000);
  }
}

// put function definitions here:
