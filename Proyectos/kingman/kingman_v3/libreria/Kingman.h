//Primero los include guards
#ifndef KIGNMAN_H
#define KIGNMAN_H

#include <Arduino.h>

class Kingman {
  public:
    Kingman();

    //      MOTORES
    void girar(String dire);

    void pausa(int tiempo);
    void detener();
    void ir_adelante(int grados);
    void ir_atras(int grados);
    void recorrer(float dis);

    void adelante360(int tao);		// velocidad
    void atras360(int tao);		// velocidad
    void rotar_derecha(float grados);
    void rotar_izquierda(float grados);

    void girar_M_D(float dis);
    void girar_M_I(float dis);

    void adelante(int tao);
    void atras(int tao);
    void recorrer_especial(float dis); //figuras velocidad
    void rotar_especial(float grados);	// velocidad

    //      DIBUJO
    void rectangulo(float largo, float ancho);
    void poligono(float lado, int lados);
    void circulo(int angulo, double resolx);
    void estrella(float lado, int lados);


  private:
    int retraso = 2;
    int del = 2;

    int _M1_0 = 15;
    int _M1_1 = 2;
    int _M1_2 = 4;
    int _M1_3 = 16;

    int _M2_0 = 5;
    int _M2_1 = 18;
    int _M2_2 = 19;
    int _M2_3 = 21;


    float _numero_pasos;
};

#endif
