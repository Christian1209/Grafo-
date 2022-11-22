#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

#include "Nodo.h"
class Lista
{
    public:
        Nodo *h_grafo;
        Lista(){
            h_grafo=nullptr;
        };
        void insertavertice(Personaje p,string e);
        void insertaArista(string,string,int);
        void mostrarVertices();
        Nodo *dirVertice(string);
        void imprimirGrafo();
        void guardar();
        int tamano();
        void inicializa();
        Nodo* buscar(string d);
        Nodo* buscanodo(string d);
        void eliminaristas(string etiqueta);
        void eliminarvertice2(string etiqueta);
        void vaciar();
        bool vacia();
        void reemplazavertice(Personaje p,string d);
        void eliminarvertice(string d);
        void cargar();
    private:
};

#endif // LISTA_H
