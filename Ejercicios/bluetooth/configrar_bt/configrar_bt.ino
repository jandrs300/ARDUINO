#include <SoftwareSerial.h>

SoftwareSerial BTSerial(9, 8); // RX | TX

char NOMBRE[10]  = "INSANI BT";
char BPS         = '8'; // 1=1200 , 2=2400, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
char PASS[10]    = "1234"; // CONTRASEÑA
int ledPin = 7;
int velocidad=115200;


void setup()
{
  BTSerial.flush();
  delay(500);
  Serial.begin(9600);
  BTSerial.begin(velocidad);
  delay(500);
  Serial.println("Preparado para enviar comandos AT:");
  BTSerial.print("AT");
  delay(1000);      //Espera de 1 segundo según datasheet entre envio de comandos AT

  //Cambio de nombre donde se envia AT+NAME y seguido el nombre que deseemos
  BTSerial.print("AT+NAME");
  BTSerial.print(NOMBRE);
  //Espera de 1 segundo según datasheet entre envio de comandos AT
  delay(1000);
  //Configuracion Password, se envia AT+PIN y seguido password que queremos
  BTSerial.print("AT+PIN");
  BTSerial.print(PASS);
  delay(1000);
  
  /*Cambio de la velocidad del modulo en baudios
    Se envia AT+BAUD y seguido el numero correspondiente:

    1 -- 1200 baudios
    2 -- 2400 baudios
    3 -- 4800 baudios
    4 -- 9600 baudios (por defecto)
    5 -- 19200 baudios
    6 -- 38400 baudios
    7 -- 57600 baudios
    8 -- 115200 baudios*/
  BTSerial.print("AT+BAUD");
  BTSerial.print(BPS);
  //Espera de 1 segundo según datasheet entre envio de comandos AT
  delay(1000);
  
  //Mostramos tanto por puerto serial y por led la finalizacion de la
  //configuracion AT del modulo bluetooth

  /*  Configurar el Role: para que trabaje como Maestro o Esclavo
       Enviar: AT+ROLE=<Role> Ejm: AT+ROLE=0
       Donde:<Role>
       0 -> Esclavo
       1 -> Maestro    */

 // BTSerial.print("AT+ROLE");
 // BTSerial.print(1);

  /*Configurar el modo de conexión (cuando se trabaja como maestro)
     Enviar: AT+CMODE=<Mode>  Ejm: AT+CMODE=1
     Donde: < Mode >
     0 -> Conectarse a un dispositivo con la dirección especificada(Se utiliza otro comando AT para especificar esta dirección).
     1 -> conectar el módulo a cualquier dirección disponible(aleatorio).
     Enviar el siguiente comando para averiguar el modo actual de conexión: AT+ CMODE?
  */

  //BTSerial.print("AT+CMODE");
  //BTSerial.print(0);

  /*Especificar la dirección del dispositivo al cual nos vamos a conectar
     Enviar: AT+BIND=<Address>
     Respuesta: OK
     Donde:
     < Address > Es la dirección del dispositivo al cual nos vamos a conectar, la dirección se envía de la siguiente forma: 1234,56,ABCDEF la cual equivale a la dirección 12:34:56:AB:CD:EF
     Ejemplo:
     Enviar: AT+BIND=E668,46,9277F2
     Para ver la dirección actual en este parámetro hay que enviar el siguiente comando: AT+ BIND?
  */
  //BTSerial.print("AT+BIND");
  //BTSerial.print(); // MAC del RX

  BTSerial.print("TERMINADO");

}
void loop()
{
  if(BTSerial.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BTSerial.read());
  }
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BTSerial.write(Serial.read());
  }
}

