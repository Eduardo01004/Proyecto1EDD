#include "cabecera.h"
#include <string.h>

Cabecera::Cabecera(int num,std::string dato,std::string edificio)
{
	cabeza.numero=num;
cabeza.dato=dato;
cabeza.edificio=edificio;
//cabeza.capacidad=capacidad;
	siguiente=NULL;
	primeromatriz=NULL;
	ultimomatriz=NULL;
}
Cabecera::~Cabecera(){}
