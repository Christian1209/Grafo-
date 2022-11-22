#ifndef NODO_H
#define NODO_H
#include "Personaje.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

class Nodo;

class arista{
public:
    int costo;
    arista *sig;
    Nodo *destino;

    arista()
    {
        costo=0;
        sig = nullptr;
        destino = nullptr;
    };
        arista(int c,Nodo *destino){
            costo=c;
            this->destino = destino;
            sig = nullptr;
        }
};

class Nodo
{
    public:
        string etiqueta;
        Nodo *sig;
        arista *h_arista;
        Personaje dato;
        Nodo(){
            etiqueta = "";
            sig = nullptr;
            h_arista = nullptr;
            dato.setNombre("");
            dato.setId(0);
            dato.setNivel(0);
        };
        Nodo(string e){
            etiqueta=e;
            sig = nullptr;
            h_arista = nullptr;
            dato.setId(0);
            dato.setNivel(0);
            dato.setNombre(" ");
            ;
        }
    private:
};

#endif // NODO_H
