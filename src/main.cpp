#include <Arduino.h>

// put function declarations here:
#define SER 21  
#define RCLK 19
#define SCLK 18

// a number mask
unsigned char number[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int segment_pins[4] = {23, 34, 35, 32};

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(RCLK, OUTPUT);  
  pinMode(SCLK, OUTPUT);  
  pinMode(SER, OUTPUT);

  for(int sp: segment_pins){
    pinMode(sp, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    // for (int row = 0; row < 10; row++)   
    // {            
    //     digitalWrite(RCLK, LOW);     
    //     shiftOut(SER, SCLK, MSBFIRST, number[row]);      
    //     digitalWrite(RCLK, HIGH);      
    //     delay(1000);  
    // }
  // int startup = millis();
  delay(500);
  Serial.println("Hello");

}

// put function definitions here:





