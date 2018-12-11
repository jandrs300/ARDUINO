#include <SoftwareSerial.h>
#include "Vennom.h"
SoftwareSerial SerialBT(9, 8); // RX, TX
char dato;
int size = 0, song = 0, cont = 0;
bool b_rgb;
String dd = "";
String trama_array[16] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0","0", "0", "0"};
Vennom robot;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin(9600);
  delay(1000);

}
void loop()
{

  if (SerialBT.available() > 0)  // Si llega un dato por el puerto BT se envía al monitor serial
  {
    dato =  SerialBT.read();
    //Serial.println(dato);
    recibe_bt(dato);

  }
  /*dato = '0';
    recibe_bt(dato);*/
}

void recibe_bt(char dat) {
  if (b_rgb) {
    programacion(dat, 10);
  } else {
    switch (dat) {
      case '?':
        delay(500);
        SerialBT.println("v1~");
        SerialBT.flush();
        dato = 'z';
        break;
      case 'p':
        delay(500);
        SerialBT.println("v1~");
        SerialBT.flush();
        dato = 'z';
        break;

      case 'c':
        delay(500);
        SerialBT.println("v1~");
        SerialBT.flush();
        dato = 'z';
        break;

      case '0':      // STOP
        SerialBT.flush();
        //Serial.write(dato);
        dato = 'z';
        robot.MoverVennom("detener");
        robot.LED_RGB(0, 0, 0);
        break;

      case '1':      // ADELANTE
        SerialBT.flush();
        //Serial.write(dato);
        dato = 'z';
        robot.MoverVennom("adelante");
        robot.LED_RGB(0, 255, 0);
        break;

      case '2':      // ATRAS
        SerialBT.flush();
        //Serial.write(dato);
        dato = 'z';

        robot.MoverVennom("atras");
        robot.LED_RGB(255, 0, 0);

        break;

      case '3':        // DERECHA
        SerialBT.flush();
        //Serial.write(dato);
        dato = 'z';
        robot.MoverVennom("derecha");
        robot.LED_RGB(0, 0, 255);
        break;

      case '4':        // IZQUIERDA
        SerialBT.flush();
        //Serial.write(dato);
        dato = 'z';
        robot.MoverVennom("izquierda");
        robot.LED_RGB(0, 0, 255);
        break;

      case '5':   //LED RGB
        //Serial.write(dato);
        dato = 'z';
        break;

      case 'a':
        dato = 'z';
        robot.Cantante("saludo");
        break;

      case 'e':
        dato = 'z';
        robot.Cantante("mario");
        break;
      case 'f':
        dato = 'z';
        robot.Cantante("despacito");
        break;
      case '$':
        dato = 'z';
        b_rgb = true;
        delay(80);
        break;
    }
  }
}

void programacion(char o, int espera) {
  if (o == '~') {
    delay(espera);
    if (b_rgb) {
      recibir_rgb();
    }
  } else {
    delay(80);
    if (o == ',') {
      trama_array[cont] = dd;
      dd = "";
      cont++;
    } else {
      dd = dd + o;
    }
  }
}


void recibir_rgb() {
  int r1 = trama_array[0].toInt();
  int g1 = trama_array[1].toInt();
  int b1 = trama_array[2].toInt();
  //r1 = 9-r1;
  //g1 = 9-g1;
  //b1 = 9-b1;
  r1 = map(r1, 0, 9, 0, 255);
  g1 = map(g1, 0, 9, 0, 255);
  b1 = map(b1, 0, 9, 0, 255);
  robot.LED_RGB(r1, g1, b1);
  
  for (int k = 0; k <= 16; k++) {
    trama_array[k] = "0";
  }
  b_rgb = false;
  dato = 'z';
  cont = 0;
}

