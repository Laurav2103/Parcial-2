#include "cofensivo.h"


cOfensivo::cOfensivo()
{

}

void cOfensivo::disparosOf(float Xd, float Yd, int Vin)
{
    int col=0;
    float x=0, y=0;
    float Vxin,Vyin;
    int V0=0;
    int t=0;
    int angle=0;
    for (V0=Vin;V0<=500;V0+=5){
        for (angle=0;angle<90;angle++){
            for (t=0;;t++){
                //Ecuaciones cinematicas
                Vxin=V0*cos(angle*pi/180);
                Vyin=V0*sin(angle*pi/180);
                x=Vxin*t;
                y=Yo+ Vyin*t-(0.5*G*t*t);
                //condicion de impacto con el defensivo
                if(sqrt(pow((Xd-x),2)+pow((Yd-y),2))<=getD0()){
                    if(y<0) y=0;
                    ang[col]=angle;
                    vel[col]=V0;
                    imprimir(angle,V0,x,y,t);
                    col+=1;
                    V0+=30;
                    break;
                }
                if(y<0)break;
            }
            if (col==3) break;
        }
        if (col==3) break;
    }
    if (col!=3)cout<<" ";

}
void cOfensivo::imprimir(float angle, float V0, float x, float y, float t)
{
    cout<<endl;
    cout<<"El impacto se produce con un angulo de: "<<angle<<" grados"<<endl;
    cout<<"El impacto se produce con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Posicion respectiva en X: "<<x <<" m"<<endl;
    cout<<"Posicion respectiva en Y: "<<y <<" m"<<endl;
    cout<<"En un tiempo de: "<<t<<" s"<<endl<<endl;
}


float cOfensivo::getD0() const
{
    return d0;
}
float  cOfensivo::getD() const
{
    return d;
}

void  cOfensivo::setD(float value)
{
    d = value;
}

float  cOfensivo::getXo() const
{
    return Xo;
}

void  cOfensivo::setXo(float value)
{
    Xo = value;
}

float  cOfensivo::getYo() const
{
    return Yo;
}

void  cOfensivo::setYo(float value)
{
    Yo = value;
}


void  cOfensivo::setD0(float value)
{
    d0 = value;
}

