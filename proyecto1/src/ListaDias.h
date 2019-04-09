#ifndef ListaDias_H
#define ListaDias_H
#include "NodoDias.h"
#include "raiz.h"

class ListaDias
{
public:

	NodoDias *primero;
  NodoDias *ultimo;
	Matriz *horario;

	void InsertarDia(std::string,Raiz*);

	ListaDias();
	~ListaDias();

};

#endif
