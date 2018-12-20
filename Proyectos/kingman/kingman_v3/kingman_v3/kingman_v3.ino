#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

int grados = 0, _numero_pasos = 0;
int _M1_0 = 15, _M1_1 = 2, _M1_2 = 4, _M1_3 = 16; // motor izquierdo
int _M2_0 = 5, _M2_1 = 18, _M2_2 = 19, _M2_3 = 21; // motor derecho
int del = 2, cont = 0;
//String trama_array[16] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
char trama_array[16] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

void setup() {

  SerialBT.begin("King"); //Bluetooth device name
  Serial.begin(115200);

  pinMode(_M1_0, OUTPUT);
  pinMode(_M1_1, OUTPUT);
  pinMode(_M1_2, OUTPUT);
  pinMode(_M1_3, OUTPUT);

  pinMode(_M2_0, OUTPUT);
  pinMode(_M2_1, OUTPUT);
  pinMode(_M2_2, OUTPUT);
  pinMode(_M2_3, OUTPUT);

  /*delay(1000);
    selec('1');
    selec('2');
    selec('1');
    selec('2');
    selec('1');
    selec('2');
    selec('1');
    selec('2');*/
}

void loop() {
  if (SerialBT.available()) {
    char comando = SerialBT.read();
    if (comando == '~')  {
      datos_();
    } else {
      if (comando != ',')  {
        trama_array[cont] = comando;
        cont++;
      }
    }
  }
}

void datos_() {
  for (int i = 0; i < sizeof(trama_array) - 1; i++) {
    selec(trama_array[i]);
    //Serial.println(trama_array[i]);
  }
  selec('y');
}

void selec(char i) {
  switch (i) {
    case '0':
      break;
    case '1':
      adelante_();
      break;
    case '2':
      girar_der();
      break;
    case '3':
      girar_izq();
      break;
    case '4':
      atras_();
      break;
    case '?':
      SerialBT.println("k1~");
      SerialBT.flush();
      break;
    case 'y':
      for (int i = 0; i <= sizeof(trama_array) - 1; i++) {
        trama_array[i] = '0';
      }
      cont = 0;
      break;
  }
}


void girar_izq() {
  grados = 125; //512 ===90ª
  _numero_pasos = 0.0;
  grados = grados ;

  while (grados > _numero_pasos) { // Giro hacia la DERECHA en grados
    // uno
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    
    //dos
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    
    //tres
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(del);

    //cuatro
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(del);
    _numero_pasos = _numero_pasos + 1;
  }
}

void atras_() {
  grados = 250;
  _numero_pasos = 0.0;
  while (grados > _numero_pasos) { // Giro hacia la DERECHA en grados
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

    _numero_pasos = _numero_pasos + 1;
  }
}

void girar_der() {
  grados = 125; //256 === 12cm
  _numero_pasos = 0.0;

  while (grados > _numero_pasos) { // Giro hacia la DERECHA en grados
    
    // uno
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(del);

    //dos
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(del);

    //tres
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);

    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    _numero_pasos = _numero_pasos + 1;
  }
}

void adelante_() {
  grados = 250; //256 === 12cm
  _numero_pasos = 0.0;

  while (grados > _numero_pasos) { // Giro hacia la DERECHA en grados
    // uno
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    
    //dos
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);


    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    
    //tres
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);


    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(del);
    
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(del);

    _numero_pasos = _numero_pasos + 1;
  }
}
