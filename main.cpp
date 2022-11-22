#include <iostream>
#include <stdlib.h>
#include "Lista.h"
#include "Nodo.h"
using namespace std;

int main()
{
Lista *uno = new Lista;
Personaje p1("a",1,1);
string nom;
int niv;
int ide;
int op=0;
   do{
        cout<<"\nGrafo de Personajes. Se componen de Nombre, Nivel y ID"<<endl;
        cout<<"\nEscoge una opcion\n1.-)salir\n2.-)insertar Vertice\n3.-)Mostrar Vertices\n4.-)Inserta Arista\n5.-)Mostrar Grafo."<<endl;
        cout<<"6.-)Guardar grafo\n7.-)Cargar Grafo\n8.-)Mostrar tamano del grafo\n9.-)Buscar personaje en el grafo\n10.-)Buscar un vertice en el grafo\n11.-)Eliminar un vertice"<<endl;
        cin>>op;
        switch(op){
            case 1:
                cout<<"Salir..."<<endl;
                break;
            case 2:{
                cout<<"Escogiste insertar, introduce el nombre personaje a insertar"<<endl;
                cin.ignore();
                getline(cin,nom);
                cout<<"Introduce el Nivel que tendra el personaje"<<endl;
                cin>>niv;
                cout<<"Introduce el ID de tu personaje."<<endl;
                cin>>ide;
                p1.setNombre(nom);
                p1.setNivel(niv);
                p1.setId(ide);
                string etiqueta;
                cout<<"introduce el vertice a insertar"<<endl;
                cin>>etiqueta;
                uno->insertavertice(p1,etiqueta);
                }
                break;
            case 3:
                cout<<"Escogiste Mostrar vertices, mostrando..."<<endl;
                uno->mostrarVertices();
                break;
            case 4:{
                string origen, destino;
                int costo;
                cout<<"Escogiste Inserta Arista"<<endl;
                cout<<"Introduce vertice Origen (etiqueta)"<<endl;
                cin>>origen;
                cout<<"Introduce vertice destino (etiqueta)"<<endl;
                cin>>destino;
                cout<<"introduce costo de la arista"<<endl;
                cin>>costo;
                uno->insertaArista(origen,destino,costo);
                }
                break;
            case 5:
                cout<<"Escogiste mostrar grafo, mostrando... "<<endl;
                uno->imprimirGrafo();
                break;
            case 6:
                cout<<"Escogiste Guardar grafo, guardando..."<<endl;
                uno->guardar();
                break;
            case 7:
                cout<<"Escogiste Cargar grafo, cargando..."<<endl;
                uno->cargar();
                break;
            case 8:
                cout<<"Escogiste mostrar tamano del grafo..-"<<endl;
                cout<<"El tamaño es: "<<uno->tamano()<<endl;
                break;
            case 9:
                cout<<"Escogiste buscar personaje en el grafo..."<<endl;
                cout<<"introduce el nombre de tu personaje"<<endl;
                cin.ignore();
                getline(cin,nom);
                uno->buscar(nom);
                break;
            case 10:{
                string d;
                cout<<"Escogiste Buscar un vertice en el grafo"<<endl;
                cout<<"introduce el vertice a buscar (etiqueta)"<<endl;
                cin>>d;
                uno->buscanodo(d);
                }
                break;
            case 11:{
                string d;
                cout<<"Escogiste el metodo eliminar..."<<endl;
                cout<<"introduce el vertice a eliminar(se eliminaran aristas.)"<<endl;
                cin>>d;
                uno->eliminarvertice2(d);
            }
        }
    }while(op!=1);
}
