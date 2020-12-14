#include <iostream>
#include "cofensivo.h"
#include "cdefensivo.h"
using namespace std;

int main()
{
    // Definicion de objetos:
    cOfensivo disOfensivo;
    cDefensivo disDefensivo;

    float Vin,d,Yo,Yd,VinO,angleO;
    int a;
    cout<<"PARCIAL 2. INFORMATICA II:"<<endl<<endl<<endl;
    cout<<"Para poder iniciar la simulacion, debe ingresar las condiciones iniciales del entorno"<<endl<<endl;
    cout<<"Ingrese:"<<endl;
    cout<<"Altura Ho del ca"<<char(164)<<"on Ofensivo en metros: ";
    cin>>Yo;
    cout<<"Separacion en metros de los ca"<<char(164)<<"ones ofensivo y defensivo: ";
    cin>>d;
    cout<<"Altura Hd del ca"<<char(164)<<"on Defensivo en metros: ";
    cin>>Yd;
    disOfensivo.setYo(Yo);
    disDefensivo.setYd(Yd);
    disOfensivo.setD(d);
    disDefensivo.setXd(d);
    disOfensivo.setD0(0.05*d);
    disDefensivo.setDd(0.025*d);




    while(true){
        cout<<"Ingrese si quiere realizar el punto 1, 2, 3, 4 o 5:";
        cin>>a;
        cout<<"Ingrese Velocidad de prueba: ";
        cin>>Vin;
        cout<<endl<<endl;

        switch (a) {
         case 1:
            cout<<"El disparo ofensivo sera efectivo con los siguientes parametros"<<endl;
            disOfensivo.disparosOf(d,Yd,Vin);
         break;
         case 2:
            cout<<"El disparo defensivo sera efectivo con los siguientes parametros"<<endl;
            disDefensivo.disparosDef(0,Yo,Vin);
         break;
        }

    }



    return 0;
}
