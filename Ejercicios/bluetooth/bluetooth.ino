#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(9,8);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
// AT+NAME=VENNOM_51
// AT+PSWD=1234 // CONTRASEÑA
// AT+UART=115200,0,0
// AT+ORGL   // VOLVER A RESET DE FABRICA

void setup()
{
  BT.begin(38400);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie   
  
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}
