#ifndef ListaEdificios_H
#define ListaEdificios_H
#include "NodoEdificios.h"

class ListaEdificios
{
public:

	NodoEdificios *primero;
	NodoEdificios *ultimo;
	std::string recorrido;

	void InsertarEdificios(struct Edificio edificio);
	void mostrarDoble();
	void FreeNodoPila(NodoEdificios *);
	void eliminarDoble(int );
	bool encontrarDoble(int);
	void editarDoble(int,std::string);
	void GraficarEdificios();

	ListaEdificios();
	~ListaEdificios();

};




#endif
