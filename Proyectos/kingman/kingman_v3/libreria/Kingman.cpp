#include "Arduino.h"
#include "Kingman.h"
#include "math.h"

Kingman::Kingman() {  // seteo de pines

  //  for (int e = 0; e < 4; e++) {
  //    pinMode(Motor1[e], OUTPUT);
  //    pinMode(Motor2[e], OUTPUT);
  //  }
  pinMode(_M1_0, OUTPUT);
  pinMode(_M1_1, OUTPUT);
  pinMode(_M1_2, OUTPUT);
  pinMode(_M1_3, OUTPUT);

  pinMode(_M2_0, OUTPUT);
  pinMode(_M2_1, OUTPUT);
  pinMode(_M2_2, OUTPUT);
  pinMode(_M2_3, OUTPUT);

}

void Kingman::girar(String dire) {  //adelante ==> atras
  if (dire.equals("ADELANTE")) {
    adelante(del);

  } else if (dire.equals("ATRAS")) {
    atras(del);
  }
}

void Kingman::estrella(float lado, int lados) {
  for (int i = 0; i < lados; i++) {
    if (lados == 3) {
      rotar_derecha(120);
      recorrer(lado);
    }
    else {
      rotar_derecha(180 - (360 / lados));
      recorrer(lado);
    }
  }
}

void Kingman::poligono(float lado, int lados) {
  for (int i = 0; i < lados; i++) {
    if (lados == 3) {
      rotar_derecha(120);
      recorrer(lado);
    }
    else {
      rotar_derecha(360 / lados);
      recorrer(lado);
    }
  }
}

void Kingman::rectangulo(float largo, float ancho) {
  recorrer(largo);
  rotar_derecha(90);
  recorrer(ancho);
  rotar_derecha(90);
  recorrer(largo);
  rotar_derecha(90);
  recorrer(ancho);
  rotar_derecha(90);
}

void Robot::circulo(int angulo, double resolx) {
  // double apotema = radio -0.25;
  // float lado = pow(pow(radio,2)-apotema,0.5);
  for (int i = 0; i < (360 / angulo + 10); i++) {
    rotar_especial(angulo);
    recorrer_especial(resolx); // r = 5.25cm
  }
}

void Kingman::detener() {         //todos los pines en bajo
  digitalWrite(_M1_0, LOW);
  digitalWrite(_M1_1, LOW);
  digitalWrite(_M1_2, LOW);
  digitalWrite(_M1_3, LOW);

  digitalWrite(_M2_0, LOW);
  digitalWrite(_M2_1, LOW);
  digitalWrite(_M2_2, LOW);
  digitalWrite(_M2_3, LOW);
  delay(2400000);
}

void Kingman::pausa(int tiempo) { // se detienen
  tiempo = tiempo * 1000;
  delay(tiempo);
}

void Kingman::ir_adelante(int grados) {

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

void Kingman::ir_atras(int grados) {
  _numero_pasos = 0.0;
  grados = 2 * grados;

  while (grados > _numero_pasos) {

    //uno
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
    
    _numero_pasos = _numero_pasos + 1.40625;
  }
}

void Kingman::rotar_izquierda(float grados) {
  //_offset = 2;     //27.318/31.415 = 0.84 (factor de anterior escala)
  _numero_pasos = 0.0;
  grados = 0.8737 * 2 * grados;

  while (grados > _numero_pasos) { // Girohacia la izquierda en grados
    // uno

    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);

    delay(del);
    //dos
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(del);
    //tres
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);


    delay(del);
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);


    delay(del);
    //cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);


    delay(del);
    //seis
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);


    delay(del);
    //siete
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);


    delay(del);
    //ocho
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);


    delay(del);
    _numero_pasos = _numero_pasos + 1.40625;
  }
}

void Kingman::rotar_derecha(float grados) {
  _numero_pasos = 0.0;
  grados = grados * 2 * 0.8737;

  while (grados > _numero_pasos) { // Girohacia la izquierda en grados
    // uno
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(del);
    //dos

    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);
    delay(del);
    //tres

    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(del);
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(del);
    //cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    //seis
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    //siete
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(del);
    //ocho
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(del);
    _numero_pasos = _numero_pasos + 1.40625;
  }
}

void Kingman::rotar_especial(float grados) {
  _numero_pasos = 0.0;
  grados = grados * 2 * 0.8737;

  while (grados > _numero_pasos) { // Girohacia la izquierda en grados
    // uno
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(retraso);
    //dos

    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);
    delay(retraso);
    //tres

    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(retraso);
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(retraso);
    //cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(retraso);
    //seis
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(retraso);
    //siete
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(retraso);
    //ocho
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(retraso);
    _numero_pasos = _numero_pasos + 1.40625;
  }
}

void Kingman::adelante(int tao) {
  _numero_pasos = 0.0;

  while (6 > _numero_pasos) { // Girohacia la izquierda en grados
    // uno
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    //dos
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);

    delay(tao);
    //tres
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //seis
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //siete
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //ocho
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    _numero_pasos = _numero_pasos + 1.40625;
  }
}
void Kingman::atras(int tao) {
  _numero_pasos = 0.0;

  while (6 > _numero_pasos) {

    //uno
    digitalWrite(_M1_0, HIGH);  //1
    digitalWrite(_M1_1, LOW);   //0
    digitalWrite(_M1_2, LOW);   //0
    digitalWrite(_M1_3, HIGH);  //1

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    //dos
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //tres
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    // cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //seis
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //siete
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    //ocho
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);

    _numero_pasos = _numero_pasos + 1.40625;
  }
}

void Kingman::adelante360(int tao) {
  _numero_pasos = 0.0;

  while (720 > _numero_pasos) { // Girohacia la izquierda en grados
    // uno
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    //dos
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);

    delay(tao);
    //tres
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //seis
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //siete
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(tao);
    //ocho
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    _numero_pasos = _numero_pasos + 1.40625;
  }
}

void Kingman::atras360(int tao) {
  _numero_pasos = 0.0;

  while (720 > _numero_pasos) {

    //uno
    digitalWrite(_M1_0, HIGH);  //1
    digitalWrite(_M1_1, LOW);   //0
    digitalWrite(_M1_2, LOW);   //0
    digitalWrite(_M1_3, HIGH);  //1

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    //dos
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //tres
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //cuatro
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    // cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //seis
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);
    delay(tao);
    //siete
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);
    delay(tao);
    //ocho
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(tao);

    _numero_pasos = _numero_pasos + 1.40625;
  }
}

void Kingman::recorrer(float dis) {
  _numero_pasos = 0.0;
  dis = dis / 0.043196;

  while (dis > _numero_pasos) { // Giro hacia la izquierda en grados
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
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, HIGH);

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
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, HIGH);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, HIGH);
    digitalWrite(_M2_3, LOW);

    delay(del);
    //cinco
    digitalWrite(_M1_0, LOW);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, LOW);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(del);
    //seis
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, HIGH);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, HIGH);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(del);
    //siete
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, LOW);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, LOW);

    delay(del);
    //ocho
    digitalWrite(_M1_0, HIGH);
    digitalWrite(_M1_1, LOW);
    digitalWrite(_M1_2, LOW);
    digitalWrite(_M1_3, HIGH);

    digitalWrite(_M2_0, HIGH);
    digitalWrite(_M2_1, LOW);
    digitalWrite(_M2_2, LOW);
    digitalWrite(_M2_3, HIGH);
    delay(del);
    _numero_pasos = _numero_pasos + 1.40625;
  }
}
