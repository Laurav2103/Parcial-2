#include "cofensivo.h"


cOfensivo::cOfensivo()
{

}
float cOfensivo::getD0() const
{
    return d0;
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
                //Calculo de las velocidades en X y Y de la bala ofensiva
                Vxin=V0*cos(angle*pi/180);
                Vyin=V0*sin(angle*pi/180);
                //Calculo de las posciones en X y Y de la bala ofensiva
                x=Vxin*t;
                y=Yo+ Vyin*t-(0.5*G*t*t);
                //Se verifica la condicion de impacto sobre el cañon defensivo
                if(sqrt(pow((Xd-x),2)+pow((Yd-y),2))<=getD0()){
                    if(y<0) y=0;
                    ang[col]=angle;
                    vel[col]=V0;
                   // ImprimirDatos(angle,V0,x,y,t);
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


