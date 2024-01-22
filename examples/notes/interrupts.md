# Interrupt in ESP32

## Brief
### Hardware interrupt
Example,
- the state of GPIO pin changes, causing GPIO interrupt
- HW Timer interrupt

ESP32 HW interrupt can be positive edge triggered, negative edge triggered, high voltage triggered, or low voltage triggered.


### Software interrupt
Example,
- SW Timer interrupt
- timer overflow

## Interrupt using Timer
ESP32 can use timers to complete pre-configured tasks. When ESP 32 timers reach a certain time, an interrupt rises and uses a callback function to run the interrupt service.

### Hardware Timer
Internal hardware timer in ESP32 chip. It is designed to do time counting. We can use specific registers to config and control the hardware timer. Hardware timers are more reliable and have higher accuracy.

### Software Timer
A simulated timer (a piece of code). Does not require hardware modules, but uses a counter variable to achieve time counting.


## Coding
With arduino development environment. we can use the function `attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)` 
- pin: GPIO pin
- ISR: interrupt service functions (without parameters and return values)
- mode: interrupt mode:
  - LOW: low voltage
  - HIGH: high voltage
  - RISING: rising edge
  - FALLING: falling edge
  - CHANGE: change in voltage

Something to keep in mind when using interrupts:
1. The program in the interrupt services needs to be short
2. avoid using ***blocking*** functions in interrupt service (eg. `delay()`), use ***non-blocking*** functions to deal with delays (`micros()`)
3. variables shared between main program an interrupt service needs to use `volatile`
4. When interrupt in use, avoid using `Serial` print functions in interrupt service. When using `Serial` print, some problems may arise:
   - time delays
   - buffer overflow

An useful article on interrupts and locks ([here](http://www.uinio.com/Project/Arduino-ESP32/#%E5%A4%96%E9%83%A8%E4%B8%AD%E6%96%AD-%E8%87%AA%E6%97%8B%E9%94%81))

In ESP32 Arduino, we can use some library functions to configure and control hardware timer:
A reference: [here](https://docs.geeksman.com/esp32/Arduino/16.esp32-arduino-timer.html#%E8%BD%AF%E4%BB%B6%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1)

steps for using hardware timer
1. initialize timer: user timerBegin() to initialize HW timer;
2. attach interrupt service routine: use timerAttachInterrupt() to associate the interrupt service routine and timer;
3. setting timer mode: use timerAlarmWrite(), to set the timer to trigger once, or periodically;
4. enable the timer: use timerAlarmEnable() to enable timer and let the timer start counting.

We can use `Ticker.h` to make software timers
- `detach()`: stop ticker
- `active()`: check if ticker is active, true = in use
- `once(n, callback, arg)`: execute callback after n seconds, arg refered to the params in the callback (leave empty means callback has no param)
- `once_ms()`: execute callback after n ms, arg refered to the params in the callback (leave empty means callback has no param)
- `attach(n, callback, arg)`: execute callback every n seconds 
- `attach_ms(n, callback, arg)`: execute callback every n ms

Note: suggest not to use callbacks in ticker to do blocking IO operation (BIO), eg. network, serial, file, ... operations