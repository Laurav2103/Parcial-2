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
    cout<<"Altura del Defensivo (m): ";
    cin>>Yd;
    disOfensivo.setD(d);
    disOfensivo.setD0(0.05*d);




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
        }

    }



    return 0;
}
