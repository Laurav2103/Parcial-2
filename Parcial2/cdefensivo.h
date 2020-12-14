#ifndef CDEFENSIVO_H
#define CDEFENSIVO_H
#include <math.h>
#include <iostream>
using namespace std;
class cDefensivo
{
private:

    //parametros del cañon defensivo


    float Xd=d; //pos inicial en x del cañon def
    float Yd=0; // pos inicial en y
    float dd=0.025*d; // rango de destruccion
    float d=0;
    float pi=3.1416;
    float G=9.81;

    float normaE(float x1, float x2, float y1, float y2);
    void imprimir(float angle,float V0,float x,float y,float t);

public:
    cDefensivo();

    void disparosDef(float Xo,float Yo);
    void disparoDef2(float Yo,float Xd,float Yd,int anglei, int V2ini);
    void disparodef3(float Yo, float Xd, float Yd, int anglei, int V2ini);


    float getXd() const;
    void setXd(float value);
    float getYd() const;
    void setYd(float value);
    float getDd() const;
    void setDd(float value);
    float getD() const;
    void setD(float value);


};

#endif // CDEFENSIVO_H
