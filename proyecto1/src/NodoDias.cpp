#include "NodoDias.h"
#include <string.h>


NodoDias::NodoDias(std::string dia,Raiz* ho){
  dia=dia;
 siguiente=NULL;

}

std::string NodoDias::getDia(){
    return dia;
}
NodoDias::~NodoDias(){}
