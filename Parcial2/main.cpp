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

    cout<<"Ingrese condiciones iniciales"<<endl;
    cout<<"Altura del Ofensivo (m): ";
    cin>>Yo;
    disOfensivo.setYo(Yo);
    cout<<"Separacion de los caniones (m): ";
    cin>>d;
    disOfensivo.setD(d);
    disDefensivo.setXd(d);
    disOfensivo.setD0(0.05*d);
    disDefensivo.setDd(0.025*d);
    cout<<"Altura del Defensivo (m): ";
    cin>>Yd;
    disDefensivo.setYd(Yd);





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
