#ifndef NODOEDIFICIOS_H
#define NODOEDIFICIOS_H
#include <stdlib.h>
#include <string>

#include <string.h>
struct Edificio {
  std::string edificio;
int codigo;
std::string datosalon;
int capacidad;


};

class NodoEdificios{
public:
  struct Edificio edif;
NodoEdificios *siguiente;
NodoEdificios *atras;
	NodoEdificios(struct Edificio nuevo);
  ~NodoEdificios();

};




#endif
