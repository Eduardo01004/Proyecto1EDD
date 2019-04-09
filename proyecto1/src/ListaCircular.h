#ifndef ListaCircular_H
#define ListaCircular_H
#include <string.h>
#include "NodoCircular.h"
#include "Arbol.h"
#include <string>
#include <list>

class ListaCircular
{
public:

	NodoCircular *primero;
	NodoCircular *ultimo;


	void InsertarCircular(struct Circular curso);
	void bst_print_dot_aux(Nodo*,FILE*);
	void bst_print_dot(Nodo*,FILE*);
	Nodo *raiz;
	void graficaBinario();
	std::string Modificar(std::string ,Circular nuevo);
	void eliminar(std::string);
	void print_dotList(ListaCircular *, FILE*);
	void graficarListaA(ListaCircular *,Arbol*);
	void print_dotList_aux(ListaCircular *, FILE*);
	void graficar(Arbol*);
	ListaCircular();
	~ListaCircular();

};




#endif
