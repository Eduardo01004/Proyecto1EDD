#include "ListaDias.h"
#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
#include <iomanip>
ListaDias::ListaDias(){

	primero=NULL;
	  ultimo = NULL;
}


void ListaDias::InsertarDia(std::string dia,Raiz* horario)
{
  NodoDias *nuevo=new NodoDias(dia,horario);
	if(primero==NULL){
			primero = nuevo;
			primero->siguiente = NULL;
			ultimo = nuevo;
	}else{
			ultimo->siguiente = nuevo;
			nuevo->siguiente = NULL;
			ultimo = nuevo;
	}
}
