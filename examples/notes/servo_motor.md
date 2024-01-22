# Servo Motor

In general, servo motors have 3 wires (GND, 5V, PWM(signal)). The colors of the three wires are normally brown, red, and orange. Some servo motors may have wires with different colors. To turn a servo motor, we need to send a specifc PWM signal to the motor.

The rotation angle of the servo is achieved by adjusting the duty cycle of the PWM signal.

Standard PWM signal has a period of 20ms (50Hz). The theoretical pulse width is between 1ms and 2ms, but it can vary from 0.5ms to 2.5ms. Each pulse width is mapped to each angle from 0 to 180 degrees.

## Relationship between PWM duty cycles and rotations

| pulse width (for a period of 20ms)| rotation (degrees) | duty cycle |
|:-:|:-:|:-:|
| 0.5 ms | 0 | 0.5 / 20 |
| 1 ms | 45 | 1 / 20 |
| 1.5ms | 90 | 1.5 / 20 |
| 2ms | 135 | 2 / 20 |
| 2.5ms | 180 | 2.5 / 20 |

PWM high speed channels (driven by 80MHz CLK): 0 to 7 <br>
PWM slow speed channels (drive by 1MHz CLK): 8 to 15 

## Coding
We can use `esp32-hal-ledc.h` to make our own servo driver or we can use existing libraries (such as `ESP32-Servo.h`) to accomplish this.
