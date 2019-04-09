#include "NodoCircular.h"
#include <string.h>

NodoCircular::NodoCircular(struct Circular nuevo){
/*  nodocircular.codigo=codigo;
  nodocircular.curso=curso;
  nodocircular.catedratico=catedratico;
  */
  nodocircular=nuevo;
  siguiente=NULL;


}
NodoCircular::~NodoCircular(){}



NodoCircular * NodoCircular::getSiguiente(){

return siguiente;

}

struct Circular NodoCircular::getCircular(){

	return nodocircular;
}
