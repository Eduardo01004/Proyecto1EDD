#include "Arbol.h"
#include "NodoCircular.h"
#include "ListaCircular.h"
#include <iostream>
#include <string.h>

Arbol::Arbol(){
	raiz=NULL;
}
int Arbol:: vacio( Nodo*h )
{

	int r=0;
	if( !h ) r=1;;
	return r;
}

bool Arbol::estaVacio(){
  if(raiz == NULL){
    return true;
  }
  return false;
}


Nodo* Arbol::Insertar(Nodo *p,Nodo *q){
	if(p==NULL) p=q;
	else{
		char nq[20];
		char np[20];
		strcpy(nq,q->informacion.codigo.c_str());
		strcpy(np,p->informacion.codigo.c_str());
		if(strcmp(nq,np)<=0)
		p->izquierdo=Insertar(p->izquierdo,q);
		else
		p->derecho=Insertar(p->derecho,q);
	}
	return p;
}



void Arbol::Crear(Nodo *q){
	raiz=Insertar(raiz,q);
}
void Arbol::borrar1(std::string &q){
	raiz=borrar(raiz,q);
}


void Arbol::inOrden(Nodo *p){

	if(p!=NULL){
		inOrden(p->izquierdo);
		recorrido=recorrido+"{ \"codigo\":"+ p->informacion.codigo+","+ "\"nombre\":"+ p->informacion.nombre+"},";
		inOrden(p->derecho);
	}
}

void Arbol::modificar(Nodo *q,std::string& cod, std::string& nom)
{
		if (q->informacion.codigo == cod)
			q->informacion.nombre=nom;
		else if(cod < q->informacion.codigo)
			return modificar(q->izquierdo,cod,nom);
		else
			return modificar(q->derecho,cod,nom);
}
Nodo* Arbol::buscar(std::string cod){
  if(!estaVacio()){
      return buscarNodo(cod, raiz);
  }
  return NULL;
}

Nodo* Arbol::buscarNodo(std::string cod, Nodo* root){
  if(root != NULL){
    if(cod == root -> informacion.codigo){
      return root;
    } else if (cod < root -> informacion.codigo){
      return buscarNodo(cod,root -> izquierdo);
    } else{
      return buscarNodo(cod,root->derecho);
    }
  } else {
    return NULL;
  }
}


bool Arbol::busqueda(Nodo *q,std::string& cod)
{

	if (q==NULL)
		 return false;
	else if (q->informacion.codigo == cod)
			return true;
		else if(cod < q->informacion.codigo)
			return busqueda(q->izquierdo,cod);
		else
			return busqueda(q->derecho,cod);
}


Nodo* Arbol::in(Nodo *temp)
{
	if(temp != NULL)
	{
		in(temp->izquierdo);
		return temp;
		std::cout << temp->informacion.codigo << " ";
		in(temp->derecho);
	}
}

Nodo* Arbol::borrar( Nodo *q, std::string num )
{

	if(q->informacion.codigo ==num )
	{
		Nodo *p, *p2;

		if( vacio(q) )
		{
			free( q);
			q= NULL;
			return q;
		}
		else if(q->izquierdo==NULL )
		{
			p= q->derecho;
			free( q );
			return p;
		}
		else if( q->derecho==NULL )
		{
			p= q->izquierdo;
			free( q);
			return p;
		}
		else
		{
			p= q->derecho;
			p2= q->derecho;
			while( p->izquierdo) p= p->izquierdo;
			p->izquierdo= q->izquierdo;
			free( q );
			return p2;
		}
	}
	else if( num<q->informacion.codigo )
	q->izquierdo= borrar( q->izquierdo, num );
	else
	q->derecho= borrar(  q->derecho ,num );
	return q;
}

void Arbol::bst_print_dot_null(std::string codigo, int nullcount, FILE* stream)
{
	fprintf(stream, "    null%d [shape=point, color=lightblue2 , style=filled];\n", nullcount);
	fprintf(stream, "    %s -> null%d;\n", codigo.c_str(), nullcount);
}


void Arbol::bst_print_dot_aux(Nodo* node, FILE* stream)
{
	static int nullcount = 0;

	if (node->izquierdo)

	{

		fprintf(stream, "%s -> %s;\n", node->informacion.codigo.c_str(),node->izquierdo->informacion.codigo.c_str(),"\"];\n");
		bst_print_dot_aux(node->izquierdo, stream);
	}

	if (node->derecho)
	{

		fprintf(stream, "%s -> %s;\n", node->informacion.codigo.c_str(), node->derecho->informacion.codigo.c_str());
		bst_print_dot_aux(node->derecho, stream);
	}

}

void Arbol::bst_print_dot(Nodo *tree,FILE* stream)
{
	fprintf(stream, "digraph BINARIO {\n");

	fprintf(stream, "node [fontname=\"Arial\", color=gray30, style=	rounded];\n");

	if (!tree)
	fprintf(stream, "\n");

	else if (!tree->derecho && !tree->izquierdo)
	fprintf(stream, "%s;\n", tree->informacion.codigo.c_str());
	else
	bst_print_dot_aux(tree, stream);

	fprintf(stream, "}\n");
}

void Arbol::graficaBinario(){
	FILE *archivo;
	FILE *fich;
	archivo=fopen("ABB.dot","w");
	fich=fopen("ABBC.jpg","r");
	bst_print_dot(raiz,archivo);
	fseek(fich, 0L, SEEK_END);
	printf("ocupa %d bytes", ftell(fich));
	fclose(archivo);
	system("dot -Tjpg ABB.dot -o ABBC.jpg");


}
static const char encoding_table[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/' };


	char* Arbol::base64_encode(const unsigned char *data, size_t input_length, size_t &output_length) {

		const int mod_table[] = { 0, 2, 1 };

		output_length = 4 * ((input_length + 2) / 3);

		char *encoded_data = (char*)malloc(output_length);

		if (encoded_data == nullptr)
		return nullptr;

		for (int i = 0, j = 0; i < input_length;) {

			uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
			uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
			uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

			uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

			encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
			encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
			encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
			encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];

		}

		for (int i = 0; i < mod_table[input_length % 3]; i++)
		encoded_data[output_length - 1 - i] = '=';

		return encoded_data;

	}



	Arbol::~Arbol(){}
