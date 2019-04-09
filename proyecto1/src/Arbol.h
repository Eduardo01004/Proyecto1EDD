#ifndef ARBOL_H
#define ARBOL_H
#include <string.h>
#include "nodo.h"
//#include "NodoCircular.h"
//#include "ListaCircular.h"

#include <string>

class Arbol{
	private:
		Nodo *Insertar(Nodo*,Nodo*);
	public:

		void inOrden(Nodo*);
		bool estaVacio();
		Nodo *raiz;
		std::string recorrido;
		std::string recorrido2;
		Arbol();
		void Crear(Nodo*);
		int vacio(Nodo*);
		bool busqueda(Nodo *,std::string& );
		Nodo *borrar(Nodo*,std::string n);
		Nodo *in(Nodo *temp);
		Nodo *buscarNodo(std::string cod,Nodo *root);
		Nodo* buscar(std::string cod);
		void modificar(Nodo*,std::string& cod, std::string& nom);
		void borrar1(std::string&);
		void bst_print_dot_null(std::string codigo, int, FILE*);
		void bst_print_dot_aux(Nodo*,FILE*);
		void bst_print_dot(Nodo*,FILE*);
		void graficaBinario();
		char* base64_encode(const unsigned char *data, size_t input_length, size_t &output_length);

		~Arbol();
};


#endif
