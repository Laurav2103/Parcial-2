#include "cdefensivo.h"
#include <math.h>
#include <iostream>
cDefensivo::cDefensivo()
{

}

void cDefensivo::disparosDef(float Xo, float Yo)
{
    int col=0,V0=0,t=0,Vin=5;
    float x=0,y=0,Vxin,Vyin;
    int angle=0;
    for (V0=Vin;V0<=400 && col!=3;V0+=4){
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
    if (col!=3) cout<<"No se lograron disparos defensivos efectivos"<<endl;

}

void cDefensivo::disparoDef2(float Yo, float Xd, float Yd, int angle, int V2in)
{

    float x=0, y=0,t2,t=0,thetaD,Vd,vely,velx;
    float t1=(2*V2in*cos((angle)*pi/180))/(Xd-0.05*Xd);
    vely=V2in*sin((angle)*pi/180);
    velx=V2in*cos((angle)*pi/180);
    x=V2in*cos((angle)*pi/180)*2;
    y=Yo +vely*2-(0.5*G*2*2);
    if(normaE(Xd,x,Yd,y)>Xd*0.05){
        for(int col=1;col<4;col++){
            t2=t1+((1-t1)/4.0)*col;
            t=(Xd-0.05*Xd)*t2/velx;
            thetaD=atan((Yo-Yd+vely*t-2*G*t+2*G)/(Xd-velx*t));
            Vd=((Xd-velx*t))/((t-2)*cos(thetaD));
            x=velx*t;
            y=Yo +vely*t-(0.5*G*t*t);
            imprimir(thetaD*180/pi,Vd,x,y,t);
            }
    }
    else cout<<"No es posible defender el ca"<<char(164)<<"on defensivo"<<endl;

}

void cDefensivo::disparodef3(float Yo, float Xd, float Yd, int angle, int V2in)
{

    float x=0, y=0,t2,t=0,thetaD,Vd,tfinal,velx,vely;

    float t1=(2*V2in*cos((angle)*pi/180))/(Xd-0.05*Xd);    //tamaño del intervalo donde se puede disparar
    vely=V2in*sin((angle)*pi/180);
    velx=V2in*cos((angle)*pi/180);
    x=velx*2;
    y=Yo +vely*2-(0.5*G*2*2);

    if(normaE(Xd,x,Yd,y)>Xd*0.05){
        for(int col=1;col<4;col++){

            t2=t1+((1-t1)/4.0)*col;// se realiza una particion del tiempo
            t=0.95*Xd*t2/velx; // tiempo de colision
            //despeje a partir de igualacion de ecuaciones cinematicas para cada cañon"
            thetaD=atan((Yo-Yd+vely*t-2*G*t+2*G)/(Xd-velx*t));
            Vd=((Xd-velx*t))/((t-2)*cos(thetaD));
            x=velx*t;
            y=Yo +vely*t-(0.5*G*t*t);

            tfinal=2+(Vd*sin(thetaD)+sqrt(Vd*sin(thetaD)*Vd*sin(thetaD)+2*G*Yd))/G;// tiempo en el cual y=0;
            if(tfinal>=(2+(Xd*0.975)/(Vd*cos(thetaD)))){ //verificacion
                t1=t1*1.5;
                col--;
            }
            else {
                t1=(2*velx)/(0.95*Xd);
                imprimir(thetaD*180/pi,Vd,x,y,t);
            }
        }
    }
    else cout<<"No es posible defender el ca"<<char(164)<<"on defensivo"<<endl;

}

void cDefensivo::imprimir(float angle, float V0, float x, float y, float t)
{
    cout<<endl;
    cout<<"El angulo de disparo con el que debe salir la bala es de: "<<angle<<" grados"<<endl;
    cout<<"El impacto se produce con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Posicion del impacto (X,Y)= ("<<x <<','<<y<<")."<<endl;
    cout<<"Tiempo de impacto: "<<t<<" s"<<endl<<endl;
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
float cDefensivo::normaE(float x1, float x2, float y1, float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
