#include "cofensivo.h"

cOfensivo::cOfensivo()
{

}

float cOfensivo::ecu_estudiante(float A, float B, float C)
{
    return (-B-sqrt(B*B-4*A*C))/(2*A);
}

void cOfensivo::disparosOf(float Xd, float Yd)
{
    int col=0,Vin=5;
    float x=0, y=0,Vxin,Vyin;

    for (int V0=Vin;V0<=400 && col!=3;V0+=4){
        for (int angle=0;angle<90 && col!=3;angle++){
            for (int t=0;;t++){
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
         }
     }
    if (col!=3)cout<<"No se lograron disparos ofensivos efectivos ";

}

void cOfensivo::destructor(float Xd, float Yd, float angleD, float Vd)
{
    int i=0;
    float K1,K2,M1,M2,R,A,B,C,t1,t,alphaO,Vo,x,y,velx,vely;
    vely=Vd*sin((angleD)*pi/180);
    velx=Vd*cos((angleD)*pi/180);
   // constantes generadas para simplicar la implementacion de las ecuaciones;
    K1=Xd+2*velx;
    M1=velx+vel[i]*cos(ang[i]*pi/180);
    K2=Yd-Yo-2*G-2*vely;
    M2=vely+2*G-vel[i]*sin(ang[i]*pi/180);
    R=0.025*Xd;
    A=M1*M1+M2*M2;
    B=2*(K2*M2-K1*M1);
    C=K1*K1+K2*K2-R*R;
    t1=ecu_estudiante(A,B,C);//Para calcular el momento en el cual la bala defensiva destruye la ofensiva
    if(t1>=3){ //3 segundos de retraso en total
        for(int col=1;col<4;col++){
            t=3+((t1-3)/(4.0))*col;
            alphaO=atan((Yd-Yo+vely*(t-2)+G*0.5*(5-2*t))/(Xd-velx*(t-2)));
            Vo=(Xd-velx*(t-2))/((t-3)*cos(alphaO));
            x=Vo*cos(alphaO)*(t-3);
            y=Yo +Vo*sin(alphaO)*(t-3)-(0.5*G*(t-3)*(t-3));
            imprimir(alphaO*180/pi,Vo,x,y,t);
         }
    }
    else cout<<"No es posible defender la bala ofensiva"<<endl;


}
void cOfensivo::imprimir(float angle, float V0, float x, float y, float t)
{

    cout<<"El angulo de disparo con el que debe salir la bala es de: "<<angle<<" grados"<<endl;
    cout<<"El impacto se produce con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Posicion del impacto (X,Y)= ("<<x <<','<<y<<")."<<endl;
    cout<<"Tiempo de impacto: "<<t<<" s"<<endl<<endl;
}


float cOfensivo::getD0() const
{
    return d0;
}


void  cOfensivo::setD(float value)
{
    d = value;
}



void  cOfensivo::setXo(float value)
{
    Xo = value;
}



void  cOfensivo::setYo(float value)
{
    Yo = value;
}


void  cOfensivo::setD0(float value)
{
    d0 = value;
}


