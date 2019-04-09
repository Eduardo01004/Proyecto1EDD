#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H
#include <stdlib.h>
#include <string>

#include <string.h>

struct Circular
{
	std::string codigo;
    std::string curso;
    std::string catedratico;



		};

class NodoCircular
{
public:

	struct Circular nodocircular ;
	NodoCircular *siguiente;
	NodoCircular(struct Circular nuevo);
	NodoCircular *getSiguiente();
	struct Circular getCircular();
	~NodoCircular();

};


#endif
