#include <Arduino.h>

// put function declarations here:
#define X_IN    26
#define Y_IN    27
#define Z_IN    14

#define RESOLUTION  12
#define SERVO       13
#define CHANNEL     0
#define FREQ        50

int value;

//20ms 周期内，高电平持续时长 0.5-2.5 ms，对应 0-180 度舵机角度。
//对应 0.5ms（0.5ms/(20ms/256)）
int min_width = 0.6 / 20 * pow(2, RESOLUTION);
//对应 2.5ms（2.5ms/（20ms/256））
int max_width = 2.5 / 20 * pow(2, RESOLUTION);

void setup() {
  // 配置衰减器
  analogSetAttenuation(ADC_11db);

  // 设置 ADC 分辨率
  analogReadResolution(RESOLUTION);


  // 配置输入模式
  pinMode(X_IN, INPUT);
  pinMode(Y_IN, INPUT);
  pinMode(Z_IN, INPUT_PULLUP);

  // 配置串口通信波特率
  Serial.begin(9600);

  // 用于设置 LEDC 通道的频率和分辨率
  ledcSetup(CHANNEL, FREQ, RESOLUTION);
  // 将通道与对应的引脚连接
  ledcAttachPin(SERVO, CHANNEL);
  
}

/**
 * x = map(value, fromLow, fromHigh, toLow, toHigh);
 * map 函数主要功能为将范围为 A 的变量等比例转化至 B 中，
 * 在 Arduino 编程中有广泛应用，例如将 10 位模拟输入结果转化至 8 位
 * 模拟输出、利用模拟输入值控制舵机角度等。
 * 
 * x，value 为同类型变量，fromHigh 与 fromLow 为 t 变量本身的上下界，
 * toHigh 与 toLow 为 x 变量的上下界。该函数将t变量值根据范围比例变换后将结果存入 x 变量。
 * 
*/

void loop() {
  
  // 将 ADC 的值映射到舵机的转动范围
  value = map(analogRead(Y_IN), 0, pow(2, RESOLUTION), min_width, max_width);
  
  // 读取数值
  Serial.printf("x: %d, y: %d, z: %d, 映射后的 y: %d\n", analogRead(X_IN), analogRead(Y_IN), digitalRead(X_IN), value);
  
  ledcWrite(CHANNEL, value);
  delay(100);

}

// put function definitions here:



// Using third party libraries
// #include <ESP32Servo.h>


// #define PS2_X      15
// #define PS2_Y      2
// #define SW         4
// #define SERVO      13
// #define RESOLUTION 12
// #define FREQ       50


// // 定义 Servo 对象
// Servo my_servo;

// int value;

// void setup() {
//   // 配置输入模式
//   pinMode(PS2_X, INPUT);
//   pinMode(PS2_Y, INPUT);
//   pinMode(SW, INPUT_PULLUP);

//   // 配置串口通信波特率
//   Serial.begin(9600);

//   // 分配硬件定时器
//   ESP32PWM::allocateTimer(0);
//   // 设置频率
//   my_servo.setPeriodHertz(FREQ);
//   // 关联 servo 对象与  GPIO 引脚，设置脉宽范围
//   my_servo.attach(SERVO, 500, 2500);
  
// }

// void loop() {

//   value = map(analogRead(PS2_Y), 0, pow(2, RESOLUTION), 0, 180);
  
//   // 读取数值
//   Serial.printf("x: %d, y: %d, z: %d, 映射后的 y: %d\n", analogRead(PS2_X), 
//                 analogRead(PS2_Y), digitalRead(SW), value);

//   // 输出PWM
//   my_servo.write(value);

//   delay(100);
// }
