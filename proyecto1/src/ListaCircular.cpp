#include "ListaCircular.h"
#include "Arbol.h"
#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
#include <iomanip>
ListaCircular::ListaCircular(){

	primero=NULL;
}


void ListaCircular::InsertarCircular(struct Circular curso){
			NodoCircular *nuevo=new NodoCircular(curso);
			NodoCircular *aux=primero;
			if(primero==NULL){
				primero=nuevo;
				primero->siguiente=nuevo;
				ultimo=nuevo;
			}else {
				char dato1[20];
				char dato2[20];
				char dato3[20];
				strcpy(dato1,primero->nodocircular.codigo.c_str());
				strcpy(dato2,curso.codigo.c_str());
				strcpy(dato3,ultimo->nodocircular.codigo.c_str());
				if(strcmp(dato1,dato2)>=0){
					nuevo->siguiente=primero;
					ultimo->siguiente=nuevo;
					primero=nuevo;
				}else if(strcmp(dato3,dato2)<=0){
					nuevo->siguiente=ultimo->siguiente;
					ultimo->siguiente=nuevo;
					ultimo=nuevo;
				}else{
					do{
						char dato4[20];
						strcpy(dato4,aux->nodocircular.codigo.c_str());
						if(strcmp(dato4,dato2)>=0){
							NodoCircular* aux2=primero;
							while(aux2->siguiente!=aux){ aux2=aux2->siguiente;}
							aux2->siguiente=nuevo;
							nuevo->siguiente=aux;
							break;
						}
						aux=aux->siguiente;
					}while(aux!=primero);
				}
			}
}


std::string ListaCircular::Modificar(std::string codigo,Circular nuevo)
{
			NodoCircular *s;
		s=primero;
		std::string estado;
			bool state= false;

	if(primero!=NULL){
  do {
  	/* code */

        if(codigo==s->nodocircular.codigo)  // Es igual al codigo que se busca.
        {
            std::cout<<"Se ha encontrado el codigo a editar."<<std::endl;
            s->nodocircular.codigo = nuevo.codigo;
            s->nodocircular.curso = nuevo.curso;
            s->nodocircular.catedratico = nuevo.catedratico;
            estado = "Curso con codigo: "+codigo+", ha sido actualizado a: "+nuevo.codigo+".";
            std::cout<<"Nodo actualizado."<<std::endl;
            break;
        }
        std::cout<<s->nodocircular.codigo<<" ";
        s = s->siguiente;
    }	while(s != primero);
}
    return estado;

}




void ListaCircular::eliminar(std::string codigo)
{
    NodoCircular *temp, *s;
    s = ultimo->siguiente;

    // Si solo hay un elemento en la lista
    if(ultimo->siguiente == ultimo && ultimo->nodocircular.codigo == codigo)
    {
        temp = ultimo;
        ultimo = NULL;
        free(temp);
        return;
    }
    if(s->nodocircular.codigo == codigo) // Eliminando el primer elemento
    {
        temp = s;
        ultimo->siguiente = s->siguiente;
        free(temp);
    }
    while(s->siguiente != ultimo)
    {
        // Elemento al medio
        if(s->siguiente->nodocircular.codigo == codigo)
        {
            temp = s->siguiente;
            s->siguiente = temp->siguiente;
            free(temp);
            std::cout<<"El codigo: "<< codigo <<", ha sido removido."<<std::endl;
            return;
        }
        s = s->siguiente;
    }
    // Eliminando el ultimo elemento
    if(s->siguiente->nodocircular.codigo == codigo)
    {
        temp = s->siguiente;
        s->siguiente = ultimo->siguiente;
        free(temp);
        ultimo = s;
        return;
    }
    std::cout<<"codigo: "<<codigo<<", no encontrado."<<std::endl;
}
void ListaCircular::graficarListaA(ListaCircular *listacursos, Arbol *a){
	FILE *archivo;
	archivo=fopen("cursos.dot","w");
	print_dotList(listacursos,archivo);
	bst_print_dot(a->raiz,archivo);
	print_dotList_aux(listacursos,archivo);
	fclose(archivo);
	system("dot -Tjpg cursos.dot -o cursos.jpg");
}

void ListaCircular::graficar(Arbol *p){
	FILE *stream;
	stream=fopen("cursos.dot","w");

	fprintf(stream, "digraph G{\nsubgraph cluster{\nlabel=\"Calendario\";\n");
	fprintf(stream, "node [fontname=\"Arial\", color=floralwhite, style=filled];\n");
	bst_print_dot(p->raiz,stream);
	NodoCircular* tmp = primero;

	if(tmp != NULL){
		do {
			fprintf(stream, " %s;\n", tmp -> nodocircular.codigo.c_str(),tmp -> nodocircular.codigo.c_str());

			tmp = tmp ->siguiente;
		} while(tmp != primero);
		// crear conexiones
		do {
			fprintf(stream, "%s -> %s;\n", tmp -> nodocircular.codigo.c_str(), tmp-> siguiente -> nodocircular.codigo.c_str() );
			fprintf(stream, "%s -> %s;\n", tmp -> nodocircular.codigo.c_str(), tmp-> siguiente -> nodocircular.catedratico.c_str() );
			tmp = tmp -> siguiente;
		} while(tmp != primero);
		do{
			tmp = tmp -> siguiente;
		}while (tmp != primero);

		//afile << "}";
		fputs("}\n",stream);
		fputs("}\n",stream);
		fclose(stream);

	}
	system("dot -Tpng cursos.dot -o cursos.png");
}



void ListaCircular::print_dotList(ListaCircular *lista, FILE* stream)
{
			fprintf(stream, "digraph ListaArbol {\n");
			fprintf(stream, "    subgraph lista{");

			if (primero==NULL){
				fprintf(stream, "\n");

			 }
			 else{
				NodoCircular *pivote = lista->primero;
				fprintf(stream, "    {rank=same ");
				do{
					fprintf(stream, "%s ", pivote->nodocircular.codigo.c_str());
					pivote = pivote->siguiente;
				}while(pivote!=lista->primero);
				fprintf(stream, "}\n");

				do{
					fprintf(stream, "    %s -> %s;\n", pivote->nodocircular.codigo.c_str(), pivote->siguiente->nodocircular.codigo.c_str());
					//fprintf(stream, "    %s -> %s;\n", pivote->c.codigo.c_str(), pivote->siguiente->c.catedratico.c_str());
					pivote = pivote->siguiente;
				}while(pivote!=lista->primero);
			}
			fprintf(stream, "}\n");
}


void ListaCircular::bst_print_dot_aux(Nodo* node, FILE* stream)
{
		static int nullcount = 0;

		if (node->izquierdo)
		{
			fprintf(stream, "    %s -> %s;\n", node->informacion.codigo.c_str(), node->izquierdo->informacion.codigo.c_str());
			bst_print_dot_aux(node->izquierdo, stream);
		}
		//else
		// bst_print_dot_null(node->informacion.codigo, nullcount++, stream);

		if (node->derecho)
		{
			fprintf(stream, "    %s -> %s;\n", node->informacion.codigo.c_str(), node->derecho->informacion.codigo.c_str());
			bst_print_dot_aux(node->derecho, stream);
		}
		//else
		// bst_print_dot_null(node->informacion.codigo, nullcount++, stream);
}


void ListaCircular::bst_print_dot(Nodo *tree,FILE* stream)
{
	fprintf(stream, "subgraph BINARIO {\n");
	fprintf(stream, "    node [fontname=\"Arial\", color=gray30, style=filled];\n");

	if (!tree)
	fprintf(stream, "\n");
	else if (!tree->derecho && !tree->izquierdo)
	fprintf(stream, "    %s;\n", tree->informacion.codigo.c_str());
	else
	bst_print_dot_aux(tree, stream);

	fprintf(stream, "}\n");
}

void ListaCircular::print_dotList_aux(ListaCircular *lista, FILE* stream){

	fprintf(stream, "\n");

	if (primero==NULL){
		fprintf(stream, "\n");
	}else{
		NodoCircular *pivote = lista->primero;
		do{
			fprintf(stream, "    %s -> %s;\n", pivote->nodocircular.codigo.c_str(), pivote->siguiente->nodocircular.catedratico.c_str());
			pivote = pivote->siguiente;
		}while(pivote!=lista->primero);
	}
	fprintf(stream, "}\n");
}

void ListaCircular::graficaBinario(){
	FILE *archivo;

	bst_print_dot(raiz,archivo);

	system("dot -Tpng cursos.dot -o cursos.png");


}


ListaCircular::~ListaCircular(){}
