#include "raiz.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>

Raiz::Raiz(){

 primerocolumna=NULL;
 ultimocolumna=NULL;
 primerofila=NULL;
 ultimofila=NULL;

}

void Raiz::InsertarMatriz(int a,int b,std::string dato,std::string cate,std::string dia){

    Cabecera *auxma=primerocolumna;
    Cabecera *aux2=primerofila;
    bool estado;
    bool encontrado=false;
    if(auxma!=NULL){
    while(auxma->cabeza.numero!=a){
        auxma=auxma->siguiente;
    }

    while(aux2->cabeza.numero!=b){
        aux2=aux2->siguiente;
    }
//---------------------------------------------Guardar Enemigo-------------------------------------
    Matriz *mat=new Matriz(a,b,dato,cate,dia);//string curso
    Matriz *temp;
    mat->coor.x=a;
    mat->coor.y=b;
    mat->coor.dato=dato;
    //-----------------------------------posicion en X-------------------------------------------
    if(auxma->primeromatriz==NULL){
        mat->siguiente=NULL;
        auxma->primeromatriz=mat;
        auxma->ultimomatriz=mat;
        //agregarPilaEnemigo(nuevoenemigo,0);
    }else{
        Matriz *nodoma=auxma->primeromatriz;
        estado=true;
        while(estado==true){
            if(nodoma!=NULL){
                if(nodoma->coor.y==b){
                    estado=false;
                    encontrado=true;
                }else{
                    nodoma=nodoma->siguiente;
                }
            }else{
                estado=false;
                encontrado=false;
            }
        }
       //------------------------------------if de encontrado-----------------------------
        if(encontrado==false){
            if(b<auxma->primeromatriz->coor.y){
                mat->anterior=NULL;
                mat->siguiente=auxma->primeromatriz;
                auxma->primeromatriz->anterior=mat;
                auxma->primeromatriz=mat;
            }else if(b>auxma->ultimomatriz->coor.y){
                mat->siguiente=NULL;
                mat->anterior=auxma->ultimomatriz;
                auxma->ultimomatriz->siguiente=mat;
                auxma->ultimomatriz=mat;
            }else{
                Matriz *nodoauxiliar;
                temp=auxma->primeromatriz;
                estado=true;
                while(estado){
                    if(temp->siguiente!=NULL){
                        if(b<temp->siguiente->coor.y){
                          estado=false;
                        }else{
                            temp=temp->siguiente;
                        }
                    }else{
                        estado=false;
                    }
                }
                nodoauxiliar=temp->siguiente;
                temp->siguiente=mat;
                mat->siguiente=nodoauxiliar;
            }
            //agregarPilaEnemigo(nuevoenemigo,0);
        }else{
            //-------------------------else de encontrado---------------------------------
           // agregarPilaEnemigo(nodoma,0);
        }



    }


    //-----------------------------------posicion en Y-------------------------------------------
    if(aux2->primeromatriz==NULL){
       mat->arriba=NULL;
       aux2->primeromatriz=mat;
       aux2->ultimomatriz=mat;
    }else{
        Matriz *nodoma=aux2->primeromatriz;
        estado=true;
        encontrado=false;
        while(estado==true){
            if(nodoma!=NULL){
                if(nodoma->coor.x==a){
                    estado=false;
                    encontrado=true;
                }else{
                    nodoma=nodoma->arriba;
                }
            }else{
                estado=false;
                encontrado=false;
            }
        }
        //------------------------------------if de encontrado-----------------------------
         if(encontrado==false){
             if(a<aux2->primeromatriz->coor.x){
                 mat->abajo=NULL;
                 mat->arriba=aux2->primeromatriz;
                 aux2->primeromatriz->abajo=mat;
                 aux2->primeromatriz=mat;
             }else if(a>aux2->ultimomatriz->coor.x){
                 mat->arriba=NULL;
                 mat->abajo=aux2->ultimomatriz;
                 aux2->ultimomatriz->arriba=mat;
                 aux2->ultimomatriz=mat;
             }else{
                Matriz *nodoauxiliar;
                 temp=aux2->primeromatriz;
                 estado=true;
                 while(estado){
                     if(temp->arriba!=NULL){
                         if(a<temp->arriba->coor.x){
                           estado=false;
                         }else{
                             temp=temp->arriba;
                         }
                     }else{
                         estado=false;
                     }
                 }
                 nodoauxiliar=temp->arriba;
                 temp->arriba=mat;
                 mat->arriba=nodoauxiliar;
             }

         }else{
             //-------------------------else de encontrado---------------------------------
         }


    }
    }
}



void Raiz::existeX(int x,std::string dato){
    bool estado=true;
    bool encontrado=false;
    Cabecera *temp=primerocolumna;
    Cabecera *aux;
    //----------------------------------Si esta vacia la cabecera--------------------------------------
    if(primerocolumna==NULL){
       Cabecera *nuevo=new Cabecera(x,dato,"");
        nuevo->cabeza.numero=x;
        nuevo->primeromatriz=NULL;
        nuevo->siguiente=NULL;
        primerocolumna=nuevo;
        ultimocolumna=nuevo;
    }else{
        while(estado==true){
            if(temp!=NULL){
                if(temp->cabeza.numero==x){
                    estado=false;
                    encontrado=true;
                }else{
                    temp=temp->siguiente;
                }
            }else{
                estado=false;
                encontrado=false;
            }
        }

        if(encontrado==false){
            Cabecera*nuevo=new Cabecera(x,dato,"");
            nuevo->cabeza.numero=x;
            nuevo->primeromatriz=NULL;

            if(x<primerocolumna->cabeza.numero){
                nuevo->siguiente=primerocolumna;
                primerocolumna=nuevo;
            }else if(x>ultimocolumna->cabeza.numero){
                ultimocolumna->siguiente=nuevo;
                nuevo->siguiente=NULL;
                ultimocolumna=nuevo;
            }else{
                temp=primerocolumna;
                estado=true;
                while(estado){
                    if(temp->siguiente!=NULL){
                        if(x<temp->siguiente->cabeza.numero){
                          estado=false;
                        }else{
                            temp=temp->siguiente;
                        }
                    }else{
                        estado=false;
                    }
                }
                aux=temp->siguiente;
                temp->siguiente=nuevo;
                nuevo->siguiente=aux;
            }


        }else{

        }
    }
}


//----------------------------------Busca la cabecera vertical------------------------------------------------------
void Raiz::existey(int y,std::string dato,std::string edificio){

    bool estado=true;
    bool encontrado=false;
    Cabecera*temp=primerofila;
    Cabecera *auy;
    //----------------------------------Si esta vacia la cabecera--------------------------------------
    if(primerofila==NULL){
       Cabecera *nuevo=new Cabecera(y,dato,edificio);
        nuevo->primeromatriz=NULL;
        nuevo->cabeza.numero=y;
        nuevo->siguiente=NULL;
        primerofila=nuevo;
        ultimofila=nuevo;
    }else{
        while(estado==true){
            if(temp!=NULL){
                if(temp->cabeza.numero==y){
                    estado=false;
                    encontrado=true;
                }else{
                    temp=temp->siguiente;
                }
            }else{
                estado=false;
                encontrado=false;
            }
        }

        if(encontrado==false){
       Cabecera *nuevo=new Cabecera(y,dato,edificio);
            nuevo->primeromatriz=NULL;
            nuevo->cabeza.numero=y;

            if(y<primerofila->cabeza.numero){
                nuevo->siguiente=primerofila;
                primerofila=nuevo;
            }else if(y>ultimofila->cabeza.numero){
                ultimofila->siguiente=nuevo;
                nuevo->siguiente=NULL;
                ultimofila=nuevo;
            }else{
                temp=primerofila;
                estado=true;
                while(estado){
                    if(temp->siguiente!=NULL){
                        if(y<temp->siguiente->cabeza.numero){
                          estado=false;
                        }else{
                            temp=temp->siguiente;
                        }
                    }else{
                        estado=false;
                    }
                }
                auy=temp->siguiente;
                temp->siguiente=nuevo;
                nuevo->siguiente=auy;
            }


        }else{

        }
    }
}

//---------------------------------------------------------------Generar Grafica----------------------------------------------------------------------------------
void Raiz::graficarMatriz(){
    std::ofstream afile("Matriz.dot",std::ios::out);

    Cabecera *auxiliar=primerocolumna;
    Cabecera *auxiliar2=primerofila;
    afile << "digraph G{\n";
    afile << "subgraph cluster_area{\n";
    //------------------------------------------FILAS Y COLUMNAS-----------------------------------------
    afile << "{rank=same raiz ";

    while(auxiliar!=NULL){
        long int point = reinterpret_cast<long int>(auxiliar);
        afile << point;
        afile << " ";
        auxiliar=auxiliar->siguiente;
    }
    afile << "}\n";
    afile << "}\n";
    auxiliar=primerocolumna;
    if(auxiliar!=NULL){
        //--------------------------------------------COLUMNA-----------------------------------------------
        afile << "subgraph cluster_lista_columna{\n";
        afile <<  "raiz[shape=box,label=\"*\"];\n";
        long int point = reinterpret_cast<long int>(auxiliar);
        afile << "raiz->"<<point<<";\n";
        while(auxiliar!=NULL){
            long int point = reinterpret_cast<long int>(auxiliar);
            if(auxiliar->siguiente!=NULL){
                        long int point2 = reinterpret_cast<long int>(auxiliar->siguiente);
                        afile << point << "[shape=box,label=\"" <<auxiliar->cabeza.dato<<"\"];\n";
                        afile << point2 << "[shape=box,label=\"" <<auxiliar->siguiente->cabeza.dato<<"\"];\n";
                        afile <<point<<"->"<<point2<<";\n";
            }else if(auxiliar==primerocolumna){
                        afile<<point<<"[shape=box,label=\""<<auxiliar->cabeza.dato<<"\"];\n";
            }
            Matriz *temp=auxiliar->primeromatriz;
            if(temp!=NULL){
                point=reinterpret_cast<long int>(auxiliar);
                long int point2=reinterpret_cast<long int>(temp);
                afile <<point<<"->"<<point2<<";\n";
                while(temp!=NULL){
                    if(temp!=auxiliar->ultimomatriz){
                         long int point = reinterpret_cast<long int>(temp);
                         long int point2 = reinterpret_cast<long int>(temp->siguiente);
                         afile<<point<<"->"<<point2<<";\n";
                         afile <<point <<"[label=\""<<temp->coor.dato<<"\"]\n";
                         afile<<point2<<"->"<<point<<";\n";
                         }else if(temp==auxiliar->primeromatriz || temp==auxiliar->ultimomatriz){
                            long int point = reinterpret_cast<long int>(temp);
                            afile<<point<<"[label=\""<<temp->coor.dato<<"\"]\n";
                         }
                    temp=temp->siguiente;
                }
            }
            auxiliar=auxiliar->siguiente;
        }
        //--------------------------------- FILA----------------------------------------------
        point=reinterpret_cast<long int>(auxiliar2);
        if(auxiliar2!=NULL){
            afile<<"raiz->"<<point<<";\n";
            int contador=0;
            while(auxiliar2!=NULL){
               long int point = reinterpret_cast<long int>(auxiliar2);
               if(auxiliar2->siguiente!=NULL){
                            long int point2 = reinterpret_cast<long int>(auxiliar2->siguiente);
                            afile<<point<<"[shape=box,label=\""<<auxiliar2->cabeza.dato<<"\"];\n";
                            afile<<point2<<"[shape=box,label=\""<<auxiliar2->siguiente->cabeza.dato<<"\"];\n";
                            afile<<point<<"->"<<point2<<";\n";
               }else if(auxiliar2==primerofila){
                    afile<<point<<"[shape=box,label=\""<<auxiliar2->cabeza.dato<<"\"];\n";
               }
               Matriz *temp=auxiliar2->primeromatriz;
               //---------------------------------------horizontal la mtriz ortogonal-----------------------------------
                 point = reinterpret_cast<long int>(auxiliar2);
                 afile<<"{rank=same "<<point<<" ";
               while(temp!=NULL){
                   long int point = reinterpret_cast<long int>(temp);
                   afile<<point;
                   afile<<" ";
                   temp=temp->arriba;
               }
               afile<<"}\n";

               //--------------------------------------Matriz Ortogonal--------------------------------------------------
               temp=auxiliar2->primeromatriz;
               if(temp!=NULL){
                   point=reinterpret_cast<long int>(auxiliar2);
                   long int point2=reinterpret_cast<long int>(temp);
                   afile<<point<<"->"<<point2<<";\n";
                   while(temp!=NULL){
                       if(temp!=auxiliar2->ultimomatriz){
                            long int point = reinterpret_cast<long int>(temp);
                            long int point2 = reinterpret_cast<long int>(temp->arriba);
                            afile<<point<<"->"<<point2<<";\n";
                            afile<<point2<<"->"<<point<<";\n";
                            }else if(temp==auxiliar2->primeromatriz || temp==auxiliar2->ultimomatriz){
                               long int point = reinterpret_cast<long int>(temp);
                            }
                       temp=temp->arriba;
                   }
               }

                auxiliar2=auxiliar2->siguiente;
                contador+=1;
            }

        }

    }
    afile<<"}\n";
    afile<<"}\n";
    afile.close();
    system("dot -Tpng Matriz.dot -o Matriz.png");
}


Raiz::~Raiz(){}
