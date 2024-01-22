#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVO_PIN     13    
#define MAX_WIDTH     2500  // can be 2000
#define MIN_WIDTH     500   // can be 1000

// put function declarations here:

Servo my_servo;

void setup() {
  // put your setup code here, to run once:

  // allocate a timer
  ESP32PWM::allocateTimer(0);
  // setting frequency
  my_servo.setPeriodHertz(50);
  // associate servo object with GPIO pin and setting range
  my_servo.attach(SERVO_PIN, MIN_WIDTH, MAX_WIDTH);

}

void loop() {
  // put your main code here, to run repeatedly:  
  my_servo.write(180);
  delay(1000);
  my_servo.write(0);
  delay(1000);

}

// put function definitions here:
