#include "Lista.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include "Personaje.h"
using namespace std;
#define PERSONAJE_H
#include "Nodo.h"
int Lista::tamano(){
    int cont=0;
    Nodo *aux= h_grafo;
    while(aux){
        cont++;
        aux=aux->sig;
    }
    cout<<cont<<endl;
    return cont;
}
void Lista::inicializa(){
    h_grafo=nullptr;

}

bool Lista::vacia(){
    Nodo *aux = h_grafo;
    if(aux==nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Lista::reemplazavertice(Personaje p,string e){
    int b=0;
    Nodo *aux=h_grafo;
    if(vacia()){
        cout<<"Grafo vacio"<<endl;
    }
    else{
        while(aux){
            if(e==aux->etiqueta){
                b=1;
                eliminarvertice(aux->etiqueta);
                insertavertice(p,e);
                return;

            }
            aux=aux->sig;
        }
    }
    if (b==0){
        insertavertice(p,e);
    }
}

Nodo* Lista::buscar(string d){
    int b=0;
    int i=0;
    Nodo *aux=h_grafo;
    if(vacia()){
        cout<<"Grafo vacio"<<endl;
    }
    else{
        while(aux){
            if(d==aux->dato.getNombre()){
                b=1;
                i=i+1;
                cout<<"\ntu Personaje:"<<aux->dato.getNombre()<<" ha sido encontrado en el Vertice: "<<aux->etiqueta<<endl;
                return aux;

            }
            aux=aux->sig;
            i=i+1;
        }
    }
    if (b==0){
        cout<<"Personaje no encontrado"<<endl;
    }
}

void Lista::eliminarvertice(string d){
        Nodo *aux=h_grafo;
        Nodo *auxR=nullptr;
        bool band=true;
        if (aux){//elementos de la lista
            while(aux and band){
                if(aux->etiqueta!=d){
                    auxR=aux;
                    aux=aux->sig;
                }
                else{
                 band=false;
                 }
            }
            if (aux==nullptr){
                cout<<"Vertice no encontrado"<<endl;
            }
            else if(aux==h_grafo){
                h_grafo=h_grafo->sig;
                delete aux;
            }
            else{
                auxR->sig=aux->sig;
                delete aux;
            }
        }
        else
            cout<<"Grafo vacio"<<endl;
}

void Lista::eliminarvertice2(string d){
        Nodo *aux=h_grafo;
        Nodo *auxR=nullptr;
        bool band=true;
        if (aux){//elementos de la lista
            while(aux and band){
                if(aux->etiqueta!=d){
                    auxR=aux;
                    aux=aux->sig;
                }
                else{
                 band=false;
                 }
            }
            if (aux==nullptr){
                cout<<"Vertice no encontrado"<<endl;
            }
            else if(aux==h_grafo){
                eliminaristas(aux->etiqueta);
                h_grafo=h_grafo->sig;
                delete aux;
            }
            else{
                eliminaristas(aux->etiqueta);
                auxR->sig=aux->sig;
                delete aux;
            }
        }
        else
            cout<<"Grafo vacio"<<endl;
}


Nodo* Lista::buscanodo(string d){
        Nodo *aux = h_grafo;
        while(aux){
            if(d==aux->etiqueta){
                cout<<"Vertice encontrado"<<endl;
                return aux;
            }
            aux=aux->sig;
        }
        cout<<"Vertice no encontrado"<<endl;
        return nullptr;
}

void Lista::vaciar(){
    Nodo *aux=h_grafo;
    if(vacia()){
        cout<<"Grafo vaciao!"<<endl;
    }
    else if(h_grafo ->sig==nullptr){
            cout<<"Grafo de un elemento vaciado..."<<endl;
            h_grafo=nullptr;
    }
    else{
            cout<<"Vaciando Grafo de varios elementos..."<<endl;
        while(h_grafo){
            aux=h_grafo;
            h_grafo=h_grafo->sig;
            aux=nullptr;
        }
    }
}
//-----------------------------
//METODO CARGAR Y GUARDAR
//------------------------------

void Lista::guardar(){
    //el constructor de ofstream abre el archivo
    ofstream archivoClientesSalida( "file01.txt", ios::out );
    // sale del programa si no puede crear el archivo
    if ( !archivoClientesSalida ) // operador ! sobrecargado
    {
    cerr << "No se pudo abrir el archivo" << endl;
    exit( EXIT_FAILURE );
    } // fin de if
    Nodo *aux = h_grafo;
    if (aux){
        while(aux){
            cout<<"[Nombre: "<<aux->dato.getNombre()<<" Etiqueta: "<<aux->etiqueta<<"]";
            archivoClientesSalida <<aux->etiqueta<<"|"<<aux->dato.getId() << "|" << aux->dato.getNombre() << "|" << aux->dato.getNivel();
            cout<<"Vertice guardado!"<<endl;
            cout<<"Guardando aristas!!"<<endl;
            arista *arisaux = aux->h_arista;
            while(arisaux){
                    cout<<"costo arista: "<<arisaux->costo<<"Destino: "<<arisaux->destino->etiqueta<<endl;;
                    archivoClientesSalida<<"|"<<arisaux->costo<<"|"<<arisaux->destino->etiqueta;
                arisaux=arisaux->sig;
            }
            archivoClientesSalida<<"*";
            aux=aux->sig;
        }
            cout<<"Grafo Guardado"<<endl;
    }
    else{
        cout<<"lista vacia"<<endl;
    }
}

void Lista::cargar(){
  int i,j;
  string d;
  ifstream is("file01.txt", ifstream::binary);
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    char * buffer = new char [length];
    char * registro=new char;
    char * campo=new char;

    char *tokenPtr;
    char *tokenCampo;



    cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);

    stringstream ss(buffer);

    vector<string> tokens;

    string tmpStr;
    string tmpStrC;

    if (is)
    {
      cout<< "all characters read successfully."<<endl;
      //cout<<buffer<<endl;
      i=0;
      d=(string)buffer;


      while(getline(ss,tmpStr,'*'))
      {
          tokens.push_back(tmpStr);
      }
        int p=0;
        bool estado = true;
         for(int i = 0; i < tokens.size()-1; i++)
         {
            vector<string> tokensC;
             p=0;
            stringstream cm(tokens[i]);
            Personaje p1("a",1,1);
                  //con p me muevo entre mi registro.
                   while(getline(cm,tmpStrC,'|'))
                  {
                       p++;
                       tokensC.push_back(tmpStrC);
                       cout<<"P: "<<p<<endl;
                       cout<<tmpStrC<<endl;
                       if(p>5 && estado){
                        estado=false;
                        insertaArista(tokensC[0],tmpStrC,(atoi(tokensC[p-2].c_str())));
                       }
                       else{
                        estado=true;
                       }
                      if(p==4){
                        //si p es igual a cuatro, ya llegue al limite de mi personaje entonces ahora en adelante seran aristas.
                        string etiqueta;
                        etiqueta = tokensC[0];
                        p1.setId(atoi(tokensC[1].c_str()));
                        p1.setNombre(tokensC[2]);
                        p1.setNivel(atoi(tokensC[3].c_str()));
                        reemplazavertice(p1,etiqueta);
                      }
                  }
         }
    }
    else{
      cout << "error: only " << is.gcount() << " could be read";

    is.close();

    // ...buffer contains the entire file...

    delete[] buffer;
  }
}
}

void Lista::imprimirGrafo(){
    Nodo *aux_vertice = h_grafo;
    arista *aux_arista;
    while(aux_vertice){
        aux_arista = aux_vertice->h_arista;
        cout<<"##"<<aux_vertice->etiqueta<<"##"<<endl;
        cout<<"##"<<"Personaje: "<<aux_vertice->dato.getNombre()<<")"<<"##"<<endl;

        //cout<<aux_arista.
        while(aux_arista){
            cout<<"("<<aux_arista->costo<<","<<aux_arista->destino->etiqueta<<"),";
            aux_arista = aux_arista->sig;
        }
        cout<<endl;
        aux_vertice=aux_vertice->sig;
    }
}

void Lista::eliminaristas(string etiqueta){
    cout<<"eliminar aristas"<<endl;
    Nodo* auxvertice = h_grafo;
   bool band=true;
   arista* auxaristaR = nullptr;

   while(auxvertice){
        if (auxvertice->etiqueta!=etiqueta){
                    arista* auxarista= auxvertice->h_arista;
        cout<<"Entre a aux vertice:"<<auxvertice->etiqueta<<endl;
        cout<<"Vertice ancla "<<h_grafo->etiqueta<<endl;
        while(auxarista){
            cout<<"entre a auxarista"<<endl;
            cout<<"Destino:"<<auxarista->destino->etiqueta<<"Vertice a eliminar: "<<etiqueta<<endl;
                if(auxarista->destino->etiqueta==etiqueta){
                    if(auxarista==auxvertice->h_arista){
                        cout<<"llegue a etiqueta"<<endl;
                        auxaristaR=auxarista;
                        arista*tmp=auxarista;
                        auxarista=auxarista->sig;
                        auxaristaR->sig=auxarista;
                        delete tmp;
                        auxvertice->h_arista=auxarista;
                    }
                    else{
                        auxaristaR=auxarista;
                        arista*tmp=auxarista;
                        auxarista=auxarista->sig;
                        auxaristaR->sig=auxarista;
                        delete tmp;
                    }
                }
                else{
                    auxaristaR=auxarista;
                    auxarista=auxarista->sig;
                    }
        }
        auxvertice=auxvertice->sig;
   }
    auxvertice=auxvertice->sig;
   cout<<"Vertices borrados"<<endl;
}
}

void Lista::mostrarVertices(){
    Nodo *aux=h_grafo;
    while(aux){
        cout<<aux->etiqueta<<")";
        aux=aux->sig;
    }
}

void Lista::insertavertice(Personaje p,string e){
    Nodo *tmp = new Nodo(e);
    tmp->dato = p;
    if(h_grafo){
        tmp->sig=h_grafo;
        h_grafo=tmp;
    }
    else{
        h_grafo = tmp;
    }
}

Nodo* Lista::dirVertice(string des){
    Nodo *aux = h_grafo;
    while(aux){
        if(des==aux->etiqueta){
            return aux;
        }
        aux=aux->sig;
    }
    return nullptr;
}

void Lista::insertaArista(string ori,string des,int c){
    Nodo *destino=dirVertice(des);
    if(!destino){
        cout<<"NO SE ENCONTRO DESTINO PARA LA ARISTA!!"<<endl;
        Personaje p1("a",1,1);
        insertavertice(p1,des);
        destino=dirVertice(des);
    }
    if(destino){
        cout<<"SI SE ENCONTRO DESTINO PARA LA RISTA"<<endl;
        arista *tmp = new arista(c,destino);
        Nodo * aux=h_grafo;
        bool band = true;
        while(aux and band){
            if(ori==aux->etiqueta)
                band = false;
            else
                aux=aux->sig;
        }
        //--------------
        if(aux){
            arista *aux_arista = aux->h_arista;
            if(aux_arista==nullptr){
                    aux->h_arista=tmp;
            }
            else{
                    while(aux_arista->sig!=nullptr){
                        aux_arista = aux_arista->sig;
                    }
                    aux_arista->sig = tmp;
            }
        }
    }


}

