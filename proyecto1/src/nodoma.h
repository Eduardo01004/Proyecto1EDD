#ifndef NODOMA_H
#define NODOMA_H
#include <stdlib.h>
#include <string>
#include <string.h>

struct CoordMatriz{
int x;
int y;
std::string dato;
std::string dia;
std::string catedratico;
};

class Matriz
{
	public:

	struct CoordMatriz coor;

	Matriz *siguiente;
    Matriz *anterior;
    Matriz *abajo;
    Matriz *arriba;
		Matriz(int,int,std::string,std::string,std::string);
		~Matriz();
};




#endif
