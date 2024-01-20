# ESP32 
Notes on ESP32

## Pin usage of ESP32

### Input-only pins
GPIO 34 to 39 are GPIs, only supporting input. They do not have pull-up/pull-down resistors.

On the board I used only have GPIO 34, 35, 36, 39 available

### SPI Flash
GPIO 6 to 11. They are connected to ESP32 SPI flash. It is recommended to not use them for other purposes. Do not use them in projects.

- GPIO 6 (SCK/CLK)
- GPIO 7 (SDO/SD0)
- GPIO 8 (SDI/SD1)
- GPIO 9 (SHD/SH2)
- GPIO 10 (SWP/SD3)
- GPIO 11 (CSC/CMD)

### Capacitive Touch Pins
ESP32 has 10 internal capacitive touch sensors. They can sense changes in any electrically charged substance, such as human skin. Therefore, they can detect the changes caused when touching the gpio with a finger. These pins can be easily integrated into capacitive pads and replace mechanical buttons. Capacitive pins can also be used to wake up the ESP32 from deep sleep.

T0 (GPIO 4), T1 (GPIO 0), T2 (GPIO 2), T3 (GPIO 15)<br>
T4 (GPIO 13), T5 (GPIO 12), T6 (GPIO 14), T7 (GPIO 27)<br>
T8 (GPIO 33), T9 (GPIO 32)

## Coding

### Some common functions that are provided in Arduino

- `pinMode(pin, mode)`: setting pin input/output mode. pin: pin number, mode: INPUT/OUTPUT
- `digitalWrite(pin, value)`: write a value (HIGH or LOW) to a pin. pin: pin number，value: value that will be written to the pin
- `digitalRead(pin)`: read the value of a pin (HIGH or LOW)
- `analogRead(pin)`: read value (0 - 1023) from analog signal pin. pin: analog signal pin number
- `analogWrite(pin, value)`: use on a pin that supports PWM output, analog range (0-255), pin: pin number，value: output value
- `delay(ms)`: create a delay in a program, ms: number of milliseconds
- `millis()`: returns the number of milliseconds since startup, which can be used for time tracking and timers.
- `Serial.begin(baud)`: used to initialize serial communication, where baud is the baud rate.
- `Serial.print(data)`: used to print data to the serial monitor. data can be a number, string or other data type.
- `Serial.available()`: check if data can be read from the serial port

### MACRO
Use MACRO can save some memory.

### PWM signal
We can take advantage of `esp32-hal-ledc.h`

```cpp
// setting LEDC channel freqeuncy and counter bit resolution (duty cycle resolution), return final frequency
// resolution means divide a cycle into 2^(resolution bits) parts
uint32_t    ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);

// specify a channel to output a wave based on the duty cycle
void        ledcWrite(uint8_t channel, uint32_t duty);

// similar the tone on arduino, can make a passive buzzer to produce a certain sounds based on the frequency
uint32_t    ledcWriteTone(uint8_t channel, uint32_t freq);

//  该方法是上面方法的进一步封装，可以直接输出指定调式和音阶声音的信号
uint32_t    ledcWriteNote(uint8_t channel, note_t note, uint8_t octave);

// return the duty cycle of a specific channel
uint32_t    ledcRead(uint8_t channel);

// return the frequency of a channel (if duty cycle = 0, function return 0)
uint32_t    ledcReadFreq(uint8_t channel);

// attach LEDC channel to an IO pin to output signal
void        ledcAttachPin(uint8_t pin, uint8_t channel);

// free IO's LEDC functionality
void        ledcDetachPin(uint8_t pin);
```

Used LEDC produce PWM:
1. use `ledcSetup()` establish LEDC channel
2. use `ledcAttachPin()` map a GPIO pin to LEDC channel
3. use `ledcWrite(), ledcWriteTone(), ledWriteNote()` setting frequency, or buzzer tone
4. use `ledDetachPin()` to the mapping of GPIO pins to LEDC channels