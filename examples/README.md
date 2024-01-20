Some common functions that are provided in Arduino

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
