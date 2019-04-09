#include "NodoEdificios.h"
#include <string.h>


NodoEdificios::NodoEdificios(struct Edificio nuevo){
/*  nodocircular.codigo=codigo;
  nodocircular.curso=curso;
  nodocircular.catedratico=catedratico;
  */
  edif=nuevo;
  siguiente=NULL;
  atras=NULL;


}
NodoEdificios::~NodoEdificios(){}
