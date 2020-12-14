#ifndef CDEFENSIVO_H
#define CDEFENSIVO_H
#include <math.h>
#include <iostream>
using namespace std;
class cDefensivo
{
private:

    float d=0;
    float Xd=d; //pos inicial en x del cañon def
    float Yd=0; // pos inicial en y
    float dd=0.025*d; // rango de destruccion
    float pi=3.1416;
    float G=9.81;

public:
    cDefensivo();
    void disparosDef(float Xo,float Yo,int Vin);
    void imprimir(float angle,float V0,float x,float y,float t);

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
