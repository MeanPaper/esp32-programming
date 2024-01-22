#include <Arduino.h>
// put function declarations here:

#define LED_PIN   18 
#define LED_ONCE  14

hw_timer_t * timer = NULL;
hw_timer_t * timer_once = NULL;

void timer_interrupt(){
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}

void timer_once_interrupt(){
  digitalWrite(LED_ONCE, !digitalRead(LED_ONCE));
}

void setup() {
  // put your setup code here, to run once:
  pinMode(18, OUTPUT);
  pinMode(14, OUTPUT);
  
  /* initialize the timers */
  // params: timer_num, timer_divider, true for up-counting/false for down-counting
  // timer_divider: normally it is set to 80. larger the divider, lower the clock frequency for the timer
  timer  = timerBegin(0, 80, true); 
  timer_once = timerBegin(1, 80, true);

  /* set up the timers */
  timerAttachInterrupt(timer, timer_interrupt, true); // true: for edge trigger, false: for voltage trigger
  timerAttachInterrupt(timer_once, timer_once_interrupt, true);

  /* set up timer mode */
  // timer-name, period (in microseconds), mode (true: periodic, false: once)
  timerAlarmWrite(timer, 1000*1000, true); // triggered every 1 sec
  timerAlarmWrite(timer_once, 3000*1000, false); // triggered every 3 sec

  /* Enable timers */
  timerAlarmEnable(timer);
  timerAlarmEnable(timer_once);

}

void loop() {
  // put your main code here, to run repeatedly:

}

// put function definitions here:
