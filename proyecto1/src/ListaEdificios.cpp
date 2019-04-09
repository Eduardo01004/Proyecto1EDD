#include "ListaEdificios.h"
#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
#include <iomanip>
ListaEdificios::ListaEdificios(){

	primero=NULL;
}


void ListaEdificios::InsertarEdificios(struct Edificio edificio){
  NodoEdificios *nuevo=new NodoEdificios(edificio);
  if (primero==NULL) {

    primero=nuevo;
	primero->siguiente=NULL;
  	primero->atras=NULL;
    ultimo=primero;
  }else{

    ultimo->siguiente=nuevo;
    nuevo->siguiente=NULL;
    nuevo->atras=ultimo;
    ultimo=nuevo;
  }
}

void ListaEdificios::mostrarDoble(){
  NodoEdificios* i = primero;
    while(i!=NULL){

  recorrido=recorrido+"{ \"codigo\":"+ std::to_string(i->edif.codigo)+","+"\"edificio\":"+ i->edif.edificio+","+"\"datosalon\":"+i->edif.datosalon+","+"\"capacidad\":"+std::to_string(i->edif.capacidad)+"},";

        i=i->siguiente;
  }
}

void ListaEdificios::FreeNodoPila(NodoEdificios *nodo){
  nodo->siguiente=NULL;
  nodo->atras=NULL;
  free(nodo);
}

void ListaEdificios::eliminarDoble (int id){
  NodoEdificios* del = primero;
  bool state= false;
    while(del!=NULL){
      if(del->edif.codigo==id){
        bool state= true;
        if(del->atras != NULL){
          del->siguiente->atras=del->atras;
          del->atras->siguiente=del->siguiente;
        }else if (del->atras==NULL){
          primero=del->siguiente;
          primero->atras=NULL;
        }else if (del->siguiente == NULL){
          ultimo=del->atras;
          ultimo->siguiente=NULL;
        }
      }
      del=del->siguiente;
    }
    if(state!=false)
      FreeNodoPila(del);

  }

	bool ListaEdificios::encontrarDoble(int id){
	  NodoEdificios* i = primero;
	    while(i!=NULL){
	      if(i->edif.codigo==id){
	      return true;
	    }
	      i=i->siguiente;
	  }
	  return false;
	}


	void ListaEdificios::editarDoble(int id,std::string edi){
	  NodoEdificios* i = primero;
	    while(i!=NULL){
	      if(i->edif.codigo==id){
	      i->edif.edificio=edi;
	    }
	      i=i->siguiente;
	  }
	}

void ListaEdificios::GraficarEdificios(){

  FILE *archivo;
	archivo=fopen("Grafo1.dot","w");
	fprintf(archivo, "digraph G{\nsubgraph cluster{\nlabel=\"Edificios\";\n");
	NodoEdificios *aux=primero;
		if(primero!=NULL){
  	while(aux!=NULL){
      if(aux->atras==NULL){

fprintf(archivo, "%s;\n", aux -> edif.edificio.c_str() );
}
else if(aux->atras){
	fprintf(archivo, "%s -> %s;\n", aux->edif.edificio.c_str(),aux->atras->edif.edificio.c_str());
}
if(aux->siguiente){

	fprintf(archivo, "%s -> %s;\n", aux -> edif.edificio.c_str(),aux->siguiente->edif.edificio.c_str());
}else if(aux->siguiente==NULL){
	fprintf(archivo, "%s;\n", aux -> edif.edificio.c_str() );

}
aux=aux->siguiente;

}
}
  fputs("}\n",archivo);
  fputs("}\n",archivo);
fclose(archivo);
system("dot -Tpng Grafo1.dot -o Grafo1.png");
system("eog Grafo1.png");



}
