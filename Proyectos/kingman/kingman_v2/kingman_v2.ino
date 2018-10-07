#include "Vennom.h"
Vennom robot;

//    motor DEREHO
int _M1_0 = 2;
int _M1_1 = 4;
//    motor IZQUIERDO
int _M2_0 = 7;
int _M2_1 = 12;


void setup() {
  //robot.MotorTiempo("izquierdo", "adelante", 1000);

  pinMode(_M1_0, OUTPUT);
  pinMode(_M1_1, OUTPUT);
  pinMode(_M2_0, OUTPUT);
  pinMode(_M2_1, OUTPUT);
/*
  int aa = 0;
  while (500 > aa) {
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);

    aa = aa + 1;
    delay(2);
  }

  digitalWrite(_M1_0, LOW);
  digitalWrite(_M1_1, LOW);
  digitalWrite(_M2_0, LOW);
  digitalWrite(_M2_1, LOW);*/

  int grados = 20 * 7.15;
  int bb=0;
  while (grados > bb) {
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    bb = bb + 1;
    delay(2);
  }

  digitalWrite(_M1_0, LOW);
  digitalWrite(_M1_1, LOW);
  digitalWrite(_M2_0, LOW);
  digitalWrite(_M2_1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
