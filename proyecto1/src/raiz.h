#ifndef RAIZ_H
#define RAIZ_H
#include <stdlib.h>
#include <string>
#include <string.h>
#include "cabecera.h"
class Raiz
{
	public:
		Cabecera *primerocolumna;
    	Cabecera*ultimocolumna;
    	Cabecera *primerofila;
    	Cabecera*ultimofila;
    	void InsertarMatriz(int,int,std::string,std::string,std::string);
			void graficarMatriz();
    	void existeX(int,std::string);
    	void existey(int,std::string,std::string);
		Raiz();
		~Raiz();
};

#endif
