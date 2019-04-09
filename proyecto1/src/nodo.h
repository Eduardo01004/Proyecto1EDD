#ifndef NODO_H
#define NODO_H
#include <stdlib.h>
#include <string>
#include <string.h>
struct Informacion{

	std::string codigo;
	std::string nombre;
	
};

class Nodo
{
	public:
		struct Informacion informacion;
		Nodo *izquierdo;
		Nodo *derecho;
		
		Nodo(std::string& codigo,std::string& nombre);
		~Nodo();
};
#endif

