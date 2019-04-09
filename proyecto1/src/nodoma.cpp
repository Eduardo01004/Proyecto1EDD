#include "nodoma.h"
#include <string.h>
Matriz::Matriz(int x,int y,std::string dato,std::string catedratico,std::string dia)
{
coor.x=x;
coor.y=y;
coor.dato=dato;
coor.catedratico=catedratico;
coor.dia=dia;
	siguiente=NULL;
	anterior=NULL;
	arriba=NULL;
	abajo=NULL;
}

Matriz::~Matriz(){}
