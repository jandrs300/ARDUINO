#include <SoftwareSerial.h>
#include "Vennom.h"
SoftwareSerial BTSerial(9, 8); // RX | TX
Vennom robot;

char NOMBRE[10]  = "INSANI BT";
char BPS         = '8'; // 1=1200 , 2=2400, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
char PASS[10]    = "1234"; // CONTRASEÑA
int ledPin = 13;
int velocidad = "115200";
char name_robot[9]="robot DOS";
char env[40]="";

void setup() {
  pinMode(ledPin, OUTPUT);
  BTSerial.flush();
  delay(500);
  Serial.begin(9600);
  BTSerial.begin(38400);
  Serial.println("Preparado para enviar comandos AT:");
  BTSerial.print("AT");
  delay(1000);
  BTSerial.print("AT");
  delay(1000);
    if (BTSerial.available())   // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BTSerial.read());

  }
  //Cambio de nombre donde se envia AT+NAME y seguido el nombre que deseemos
  /*BTSerial.print("AT+NAME=");
  BTSerial.print(NOMBRE);
  delay(1000);
  BTSerial.print("AT+UART=");
  BTSerial.print(velocidad+",0,0");
  delay(1000);
  digitalWrite(ledPin, HIGH);
  robot.Cantante("saludo");*/
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available())   // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BTSerial.read());

  }
  if (Serial.available()) // Si llega un dato por el monitor serial se envía al puerto BT
  {
    BTSerial.write(Serial.read());
  }

}
