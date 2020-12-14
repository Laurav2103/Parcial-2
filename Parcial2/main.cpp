#include <iostream>
#include "cofensivo.h"
#include "cdefensivo.h"
using namespace std;


int main()
{
    // Definicion de objetos:
    cOfensivo disOfensivo;
    cDefensivo disDefensivo;

    float d,Yo,Yd,VinO,angleO;
    int a;
    cout<<"PARCIAL 2. INFORMATICA II:"<<endl<<endl<<endl;
    cout<<"Para poder iniciar la simulacion, debe ingresar las condiciones iniciales del entorno"<<endl<<endl;
    cout<<"Ingrese:"<<endl<<endl;
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
        cout<<endl<<endl;

        switch (a) {
         case 1:
            cout<<"PUNTO 1: Generar disparos (al menos tres) ofensivos que comprometan la integridad del ca"<<char(164)<<"on defensivo"<<endl;
            cout<<"El disparo ofensivo sera efectivo con los siguientes parametros"<<endl;
            disOfensivo.disparosOf(d,Yd);
         break;
         case 2:
            cout<<"PUNTO 2: Generar disparos (al menos tres) defensivos que comprometan la integridad del ca"<<char(164)<<"on ofensivo.";
            cout<<"El disparo defensivo sera efectivo con los siguientes parametros"<<endl;
            disDefensivo.disparosDef(0,Yo);
         break;
         case 3:
            cout<<"PUNTO 3: Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el ca"<<char(164)<<"on defensivo sea destruido sin importar si el ca"<<char(164)<<"on ofensivo pueda ser destruido.";
            cout<<"Ingrese los datos dados por el espia"<<endl;
            cout<<"Velocidad incial de la bala ofensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala ofensiva(grados): ";
            cin>>angleO;
            disDefensivo.disparoDef2(Yo,d,Yd,angleO,VinO);
            break;
        }

    }





    return 0;
}
