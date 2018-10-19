//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int _numero_pasos=0, grados=0;
int _M1_0=15,_M1_1=2,_M1_2=4,_M1_3=16;
int _M2_0=5,_M2_1=18,_M2_2=19,_M2_3=21;
int del=2;


void setup() {
    Serial.begin(115200);
  SerialBT.begin("ESP32INSANI"); //Bluetooth device name
   pinMode(_M1_0, OUTPUT);
   pinMode(_M1_1, OUTPUT);
   pinMode(_M1_2, OUTPUT);
   pinMode(_M1_3, OUTPUT);

   pinMode(_M2_0, OUTPUT);
   pinMode(_M2_1, OUTPUT);
   pinMode(_M2_2, OUTPUT);
   pinMode(_M2_3, OUTPUT);
   

}

void loop() {
  if (SerialBT.available()) {
    char comando =SerialBT.read();
    if(comando=='1'){
         adelante_k2();
      }
  }
  delay(20);
}



void adelante_k2() {
  grados = 180;
    _numero_pasos = 0.0;
  grados = grados * 2;

  while (grados > _numero_pasos) { // Giro hacia la izquierda en grados
    // uno
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);

    delay(del);
    //dos
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);

    delay(del);
    //tres
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(del);
    //cuatro
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);

    _numero_pasos = _numero_pasos + 1.40625;
  }
}
