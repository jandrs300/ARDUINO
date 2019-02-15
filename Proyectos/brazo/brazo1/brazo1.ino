#include <Servo.h>

int Senal, Sena2, Sena3, Sena4;
int Lecturas[10]; //Vector de lecturas.
int Val, i = 0, Total = 0, Promedio = 0;
Servo M1, M2, M3, M4;

//int myPins[] = {0, , 60, 120, 179};

void setup() {
  M1.attach(5);
  M2.attach(6);
  M3.attach(9);
  M4.attach(10);
  Serial.begin(9600);
  for (i = 0; i < 10; i++); //Inicialización del vector.
  Lecturas[i] = 0;
  i = 0;
}

void loop() {
  
    //  Lee la señal del potenciómetro por el pin A0 (Pin 23 del ATMega328).
    Senal = analogRead(A4); // M1
    Sena2 = analogRead(A5); // M2
    Sena3 = analogRead(A6); // M3
    Sena4 = analogRead(A7); // M4
    Senal = map(Senal, 0, 1023, 0, 179);
    Sena2 = map(Sena2, 0, 1023, 0, 179);
    //Sena3 = map(Sena3, 0, 1023, 0, 179);
    Sena4 = map(Sena4, 0, 1023, 0, 179);
    M1.write(70);
    M2.write(Sena2);
  
/*
if (Sena2 < 45) {
      M2.write(45);
    } else if ((Sena2 > 45) && (Sena2 < 60)) {
      M2.write(60);
    } else if ((Sena2 > 60) && (Sena2 < 75)) {
      M2.write(75);
    }  else if ((Sena2 > 75) && (Sena2 < 90)) {
      M2.write(90);
    } else if ((Sena2 > 90) && (Sena2 < 105)) {
      M2.write(105);
    }  else if ((Sena2 > 105) && (Sena2 < 120)) {
      M2.write(120);
    } else if ((Sena2 > 120) && (Sena2 < 135)) {
      M2.write(135);
    } else if ((Sena2 > 135) && (Sena2 < 179)) {
      M2.write(155);
    }*/

  
    if (Sena3 < 45) {
      M3.write(45);
    } else if ((Sena3 > 45) && (Sena3 < 60)) {
      M3.write(60);
    } else if ((Sena3 > 60) && (Sena3 < 75)) {
      M3.write(75);
    }  else if ((Sena3 > 75) && (Sena3 < 90)) {
      M3.write(90);
    } else if ((Sena3 > 90) && (Sena3 < 105)) {
      M3.write(105);
    }  else if ((Sena3 > 105) && (Sena3 < 120)) {
      M3.write(120);
    } else if ((Sena3 > 120) && (Sena3 < 135)) {
      M3.write(135);
    } else if ((Sena3 > 135) && (Sena3 < 179)) {
      M3.write(155);
    }

  
    if (Sena4 < 60) {
      M4.write(0);
    } else if ((Sena4 > 60) && (Sena4 < 120)) {
      M4.write(60);
    } else if ((Sena4 > 120) && (Sena4 < 179)) {
      M4.write(179);
    }


    Serial.print(Senal);
    Serial.print(" , ");
    Serial.print(Sena2);
    Serial.print(" , ");
    Serial.print(Sena3);
    Serial.print(" , ");
    Serial.println(Sena4);
    delay(500);

    delay(500);
}
void posicion(int a) {
  switch (a) {
    case 0:
      M1.write(70);
      M2.write(30);
      M3.write(140);
      M4.write(0);
      break;
    case 1:
      break;
  }

}
