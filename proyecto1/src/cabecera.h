#ifndef CABECERA_H
#define CABECERA_H
#include <stdlib.h>
#include <string>
#include <string.h>
#include "nodoma.h"
struct CabeceraCol
{
		int numero;//con esto ordena
		std::string dato;// es para graficar
		std::string edificio;//edificio en insertar y
		//int capacidad;//capacidad en insertar y
};
class Cabecera
{
	public:
		struct CabeceraCol cabeza;
		Cabecera*siguiente;
		Cabecera *anterior;
		Matriz *primeromatriz;
    Matriz *ultimomatriz;
		Cabecera(int,std::string,std::string);
		~Cabecera();
};
#endif
