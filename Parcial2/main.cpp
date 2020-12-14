#include <iostream>
#include "cofensivo.h"
#include "cdefensivo.h"
using namespace std;


int main()
{

    //Definicion de variables:
    float Yo,Yd,VinO,angleO,d;
    int a;
    // Definicion de objetos:
    cOfensivo dispOfensivo;
    cDefensivo dispDefensivo;
    cout<<"Laura Isabel Vidal Hurtado."<<endl;
    cout<<"PARCIAL 2. INFORMATICA II:"<<endl<<endl<<endl;
    cout<<"Para poder iniciar la simulacion, debe ingresar las condiciones iniciales del entorno"<<endl<<endl;
    cout<<"Ingrese:"<<endl<<endl;
    cout<<"Altura Ho del ca"<<char(164)<<"on Ofensivo en metros: ";
    cin>>Yo;
    cout<<"Altura Hd del ca"<<char(164)<<"on Defensivo en metros: ";
    cin>>Yd;
    cout<<"Separacion D en metros de los ca"<<char(164)<<"ones ofensivo y defensivo: ";
    cin>>d;


    dispOfensivo.setYo(Yo);
    dispDefensivo.setYd(Yd);
    dispOfensivo.setD(d);
    //dispDefensivo.setXd(d);
    dispOfensivo.setD0(0.05*d);
    dispDefensivo.setDd(0.025*d);

    while(true){

        cout<<endl<<endl;
        cout<<"Elija una de las opciones si desea realizar el punto 1, 2, 3, 4 o 5:";
        cin>>a;

        switch (a) {
         case 1:
            cout<<endl<<endl;
            cout<<"PUNTO 1: Generar disparos (al menos tres) ofensivos que comprometan la integridad del ca"<<char(164)<<"on defensivo"<<endl;
            cout<<endl<<endl;
            cout<<"El disparo ofensivo sera efectivo con los siguientes parametros:"<<endl<<endl;
            dispOfensivo.disparosOf(d,Yd);
         break;
         case 2:
            cout<<endl<<endl;
            cout<<"PUNTO 2: Generar disparos (al menos tres) defensivos que comprometan la integridad del ca"<<char(164)<<"on ofensivo."<<endl;
            cout<<endl<<endl;
            cout<<"El disparo defensivo sera efectivo con los siguientes parametros:"<<endl<<endl;
            dispDefensivo.disparosDef(0,Yo);
         break;
         case 3:
            cout<<endl<<endl;
            cout<<"PUNTO 3: Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el ca"<<char(164)<<"on defensivo sea destruido sin importar si el ca"<<char(164)<<"on ofensivo pueda ser destruido."<<endl;
            cout<<endl<<endl;
            cout<<"Ingrese los datos dados por el espia"<<endl;
            cout<<"Velocidad incial de la bala ofensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala ofensiva(grados): ";
            cin>>angleO;
            cout<<endl<<endl;
            dispDefensivo.disparoDef2(Yo,d,Yd,angleO,VinO);
            break;
         case 4:
            cout<<endl<<endl;
            cout<<"PUNTO 4: Dado un disparo ofensivo, generar (al menos tres) disparo defensivos que impidan que los cañones defensivo y ofensivo puedan ser destruidos."<<endl;
            cout<<endl<<endl;
            cout<<"Ingrese los datos dados por el espia:"<<endl;
            cout<<"Velocidad incial de la bala ofensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala ofensiva(grados): ";
            cin>>angleO;
            cout<<endl<<endl;
            dispDefensivo.disparodef3(Yo,d,Yd,angleO,VinO);
         break;
         case 5:
            cout<<endl<<endl;
            cout<<"PUNTO 5: Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la efectividad del ataque ofensivo, generar (al menos tres) disparos que neutralicen el ataque defensivo y permitan que el ataque ofensivo sea efectivo."<<endl;
            cout<<endl<<endl;
            cout<<"Ingrese los datos dados por el espia:"<<endl;
            cout<<"Velocidad incial de la bala defensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala defensiva(grados): ";
            cin>>angleO;
            cout<<endl<<endl;
            dispOfensivo.destructor(d,Yd,angleO,VinO);
         break;


        }

    }





    return 0;
}
