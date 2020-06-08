//
//  main.cpp
//  RadixSort
//
//  Created by Leandro Smirnovff on 6/8/20.
//  Copyright © 2020 Leandro Igor Estrada Santos. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;


int main(){

    srand(time(NULL));//inicializador del generador de numeros random

    int num_rand, N_elementos, max_digitos=0,x,y,aux,aux2,num,num_digitos;
    int X,Y,con;


    cout<<"Ingrese la longitud de la lista de elementos: "<<endl;
    cin>>N_elementos;

    int lista[N_elementos];

    int matriz[10][10];
    cout<<endl;
    cout<<"Matriz con los numeros a ordenar: "<<endl;
    
//llenado de la matriz con 0 en todos sus espacios
    for(x=0;x<10;x++){
        for(y=0;y<10;y++){
            matriz[x][y]=0;
        }
    }
    
//llenando la lista con numeros random
    for(x=0; x<N_elementos; x++){
        num_rand=1+rand()%(100-1);
        lista[x]=num_rand;
        cout<<num_rand<<", ";
    }


    cout<<endl<<endl;
//busqueda del maximo de digitos de unlementos
    for(x=0; x<N_elementos; x++){
        num=lista[x];
        aux2=0;
        while(num>=1){
            num=num/10;
            aux2++;
        }

        if (aux2>max_digitos){
            max_digitos=aux2;
        }
    }

    cout<<max_digitos<<endl;
//cout<<N_elementos<<endl;

    for(con=0;con<max_digitos;con++){

        for(x=0;x<N_elementos;x++){
            y=0;
            num=lista[x];
            switch(con){
                case 0:aux2=num%10;
                    break;
                case 1:if (num<10){
                        aux2=0;
                    }
                    else{aux2=(num-(num%10))/10;}

                    break;
            }

            while (matriz[aux2][y]>=1){
                y++;
            }
            matriz[aux2][y]=lista[x];
        }
        cout<<endl;
        //cout<<"Matriz contenedora: "<<endl;

//mostrar la matriz
        for(x=0;x<10;x++){
            y=0;
            for(y=0;y<10;y++){
                cout<<matriz[x][y]<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
//ingresando los valores ordenados en la lista
        aux2=0;
        for(x=0;x<10;x++){
            y=0;
            for(y=0;y<10;y++){
                if (matriz[x][y]>=1){
                    aux=matriz[x][y];
                    lista[aux2]=aux;
                    aux2++;
                }

            }
            cout<<endl;
        }
        for(x=0;x<N_elementos;x++){
            cout<<lista[x]<<", ";
        }
//blanqueado de la matriz
        for(x=0;x<10;x++){
            for(y=0;y<10;y++){
                matriz[x][y]=0;
            }
        }
    }
    cout<<endl<<"lista ordenada"<<endl;
    for(x=0;x<N_elementos;x++){
        cout<<lista[x]<<", ";
    }

    return 0;
}
