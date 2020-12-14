#ifndef COFENSIVO_H
#define COFENSIVO_H
#include <math.h>
#include <iostream>
using namespace std;

class cOfensivo
{
private:
    //parametros del cañon ofensivo

    float Xo=0; //pos inicial en x
    float Yo=0; //pos inicial en y
    float d=0;
    float d0=0.05*d; //rango de destruccion
    float pi=3.1416;
    float G=9.81;

    // vectores donde se guardaran los angulos y velocidades cuando se generan disparos of
    float ang[3]={};
    float vel[3]={};

    float ecu_estudiante(float A,float B,float C);
    void imprimir(float angle, float V0, float x, float y, float t);

public:
    cOfensivo();

    void disparosOf(float Xd,float Yd);
    void destructor(float Xd, float Yd, float angleD, float Vd);

    float getD() const;
    void setD(float value);

    float getXo() const;
    void setXo(float value);

    float getYo() const;
    void setYo(float value);

    float getD0() const;
    void setD0(float value);




};

#endif // COFENSIVO_H
