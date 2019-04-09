#ifndef NODODIAS_H
#define NODODIAS_H
#include <stdlib.h>
#include <string>
#include <string.h>
#include <raiz.h>

class NodoDias{
public:
std::string dia;
NodoDias *siguiente;
	NodoDias(std::string,Raiz*);
  std::string getDia();
  ~NodoDias();
};




#endif
