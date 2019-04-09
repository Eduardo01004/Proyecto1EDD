#include "nodo.h"
#include <string.h>
Nodo::Nodo(std::string& codigo,std::string& nombre)
{
	informacion.codigo=codigo;
	informacion.nombre=nombre;
	
	//strcpy(informacion.nombre,nombre);
	//informacion0nombre=nombre;
	izquierdo=NULL;
	derecho=NULL;
}

Nodo::~Nodo(){}