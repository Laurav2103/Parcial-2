#include "cdefensivo.h"
#include <math.h>
#include <iostream>
cDefensivo::cDefensivo()
{

}

void cDefensivo::disparosDef(float Xo, float Yo, int Vin)
{
    int col=0,V0=0,t=0;
    float x=0,y=0,Vxin,Vyin;
    int angle=0;
    for (V0=Vin;V0<=500 && col!=3;V0+=5){
        for (angle=0;angle<90 && col!=3;angle++){
            //Ecuaciones cinematicas
           Vxin=V0*cos((angle)*pi/180);
           Vyin=V0*sin((angle)*pi/180);

           for (t=0;;t++){

                x=Xd-Vxin*t;
                y=Yd+ Vyin*t-(0.5*G*t*t);
                //Condicion de impacto sobre el ofensivo
                if(sqrt(pow((Xo-x),2)+pow((Yo-y),2))<=getDd()){
                    if(y<0) y=0;
                    imprimir(angle,V0,x,y,t);
                    col+=1;
                    V0+=30;
                    break;
                }
                if(y<0)break;
            }

        }

    }
    if (col!=3) cout<<"No hubo impacto sobre el canion Ofensivo"<<endl;

}

void cDefensivo::imprimir(float angle, float V0, float x, float y, float t)
{
    cout<<endl;
    cout<<"El impacto se produce con un angulo de: "<<angle<<" grados"<<endl;
    cout<<"El impacto se produce con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Posicion respectiva en X: "<<x <<" m"<<endl;
    cout<<"Posicion respectiva en Y: "<<y <<" m"<<endl;
    cout<<"En un tiempo de: "<<t<<" s"<<endl<<endl;
}


float cDefensivo::getXd() const
{
      return Xd;
}

void cDefensivo::setXd(float value)
{
    Xd = value;
}

float cDefensivo::getYd() const
{
    return Yd;
}

void cDefensivo::setYd(float value)
{
    Yd = value;
}

float cDefensivo::getDd() const
{
    return dd;
}

void cDefensivo::setDd(float value)
{
     dd = value;
}
float cDefensivo::getD() const
{
     return d;
}

void cDefensivo::setD(float value)
{
     d = value;
}
