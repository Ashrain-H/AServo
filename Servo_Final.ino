/*
 * ——Programmed By Kels_Astell 2019-2020——
 * 已经完成封装但未经实机测试,BOOM也不是没有可能(认真)
 * 如果有问题的话,下亿个版本会更新
 * 确实没什么大的技术含量,只是提供一下自己的思路
 * QQ:435570123 欢迎扩列嘤,我身体很好的(想桃子)
 */
#include <Servo.h>
#define Max_Random_Angle 50
#define Min_Random_Angle 0

Servo servo1;
Servo servo2;

int c_angle = 0;
int aim_angle = 0;
int angle = 0;
unsigned char i; int do_or_not = 0;

void setup()
{
  servo1.attach(8);
  servo2.attach(7);
  delay(50);
  angle = 90;
  increase_angle(angle);
  delay(1000);
  angle = -90;
  decrease_angle(angle);
  angle = random(Min_Random_Angle, Max_Random_Angle);
}

void loop() {
    do_or_not = random(2, 9);//四种模式,抖动/正转/反转/抖动*2
    delay(2000);
    switch (do_or_not) {
      case '8': increase_angle(angle); delay(50); decrease_angle(angle); break;
      case '9': increase_angle(angle); break;
      case '7': decrease_angle(angle); break;
      case '6': for (i = 0; i < 2; i++) {increase_angle(angle);delay(50);decrease_angle(angle);
        } break;
    }
    angle = random(Min_Random_Angle, Max_Random_Angle);
}

void increase_angle(int angle) {
if (c_angle + angle > 180) { //越界判断
    aim_angle = 180;
  }
  else {
    aim_angle = c_angle + angle;
  }
  for (i = c_angle; i < aim_angle; i++) {
    servo1.write(i);
    servo2.write(180 - i);
    delay(10);
  }
  c_angle = aim_angle;
}

void decrease_angle(int angle) {
if (c_angle - angle < 0) { //越界判断
    aim_angle = 0;
  }
  else {
    aim_angle = c_angle - angle;
  }
  for (i = c_angle; i > aim_angle; i--) {
    servo1.write(i);
    servo2.write(180 - i);
    delay(10);
  }
  c_angle = aim_angle;
}
