// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#include "Proyecto1.h"

#include <string.h>
#include <iostream> //Biblioteca donde se encuentra la función cout

Arbol *arbol=new Arbol();//arbol abb
ListaCircular  *circu=new ListaCircular();//Lista Circular
Raiz  *rai=new Raiz();
ListaEdificios *edi=new ListaEdificios();
ListaDias *Ddia=new ListaDias();

/*********Arbol ABB********************/
std::string Proyecto1::insertarDato(InformacionSerial informacion)	{
	std::string response="Dato ingresado con exito";
	Nodo *q=new Nodo(informacion.codigo,informacion.nombre);
	arbol->Crear(q);
	return response;
}

std::string Proyecto1::inOrden(){

	arbol->recorrido="";
	Nodo *aux=arbol->raiz;
	arbol->inOrden(aux);
	std::string response=arbol->recorrido;
	response=response.substr(0,response.size()-1);
	response="["+response+"]";
	return response;
}

std::string Proyecto1::borrar(std::string n){


	std::string response="bro";
	arbol->borrar1(n);
	return response;

}
std::string Proyecto1::modificarCatedratico(std::string cod, std::string nom){
    std::string response;
    Nodo *aux=arbol->raiz;

			if (arbol->busqueda(aux,cod)==true)
			{
				arbol->modificar(aux,cod,nom);
				response="Modificado";
			}
			else{
				response="No encontrado";
			}



	return response;

}
std::string Proyecto1::BuscarCatedratico(std::string cod){
	std::string response;
	Nodo* tmp = arbol -> buscar(cod);
 if(tmp != NULL) return response=response+tmp -> informacion.nombre;

}

std::string Proyecto1::graficaBinario(){
	std::string response="";
	arbol->graficaBinario();
	response="Grafica Hecha :D";
	return response;

}



/*********LISTADOBLE EDIFICIOS---------------*/
std::string Proyecto1::InsertarListaDoble(Edificioserial edifi)	{
	std::string response="";
	struct Edificio nuevo;
		nuevo.codigo=edifi.codigo;
	nuevo.edificio=edifi.edificio;
nuevo.datosalon=edifi.datosalon;
	nuevo.capacidad=edifi.capacidad;


	edi->InsertarEdificios(nuevo);
	response="Curso ingresado con exito";

	return response;


}

std::list<Edificioserial> Proyecto1::Mostrar(){
std::list<Edificioserial>response;
NodoEdificios *actual=edi->primero;
Edificioserial temp;
if (edi->primero!=NULL) {
	while (actual!=NULL) {
		temp.edificio=actual->edif.edificio;
		temp.datosalon=actual->edif.datosalon;
		temp.capacidad=actual->edif.capacidad;
		temp.codigo=actual->edif.codigo;
		response.push_back(temp);
		actual=actual->siguiente;
		/* code */
	}
	/* code */
}
	return response;

}


std::string Proyecto1::borrarEdificios(int cod){
	 std::string response="";
	if (edi->encontrarDoble(cod)==true)
	{
		edi->eliminarDoble(cod);
		response="borrado";
	}
	else{
		response="No encontrado";
	}
    return response;
}

std::string Proyecto1::modificarEdificio(int cod, std::string cur){
    std::string response;
	if (edi->encontrarDoble(cod)==true)
	{
		edi->editarDoble(cod,cur);
		response="Modificado";
	}
	else{
		response="No encontrado";
	}
	return response;

}


std::string Proyecto1::graficaredi(){
	std::string response="";
	edi->GraficarEdificios();
	response="Grafica Hecha :D";

	return response;
}
/*--------------------lista circular-----------------------*/

std::string Proyecto1::InsertarCircular(CircularL curso)	{
	std::string response="Dato ingresado con exito";
	struct Circular nuevo;
	nuevo.codigo=curso.codigo;
	nuevo.curso=curso.curso;
	nuevo.catedratico=curso.catedratico;
	circu->InsertarCircular(nuevo);
	response="Curso ingresado con exito";
	return response;
}

std::string Proyecto1::MostrarCir(){

	std::string response="";
	std::string response2="";
	NodoCircular *actual=circu->primero;

	do{
		if (actual!=circu->primero && actual->siguiente==circu->primero)
		{
			response=response+"{\"codigo\":"+ actual->nodocircular.codigo+","+ "\"curso\":"+ actual->nodocircular.curso+","
			+"\"catedratico\":"+actual->nodocircular.catedratico+"}";
		}
		else{
			response=response+"{\"codigo\":"+ actual->nodocircular.codigo+","+ "\"curso\":"+ actual->nodocircular.curso+","
			+"\"catedratico\":"+actual->nodocircular.catedratico+"},";
		}

		response2= "["+response+"]";
		actual=actual->siguiente;
	}
	while(actual!=circu->primero);
	return response2;
}

std::string Proyecto1::Update(std::string codigo ,CircularL curso){
	std::string response;
	struct Circular nuevoCurso;

	nuevoCurso.codigo = curso.codigo;
	nuevoCurso.curso = curso.curso;
	nuevoCurso.catedratico = curso.catedratico;

	response = circu-> Modificar(codigo, nuevoCurso);

	return response;
}


std::string Proyecto1::deletecurso(std::string codigo)
{
	std::string response;

	circu ->eliminar(codigo);
	response = "Curso con codigo: " + codigo +", eliminado.";
	return response;
}

std::string Proyecto1::graficarCursos(){
	std::string response="";
	circu->graficarListaA(circu,arbol);
	//circu->graficaBinario();
	return response;
}
static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
'w', 'x', 'y', 'z', '0', '1', '2', '3',
'4', '5', '6', '7', '8', '9', '+', '/'};
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};

void build_decoding_table() {

	decoding_table = (char*) malloc(256);

	for (int i = 0; i < 64; i++)
	decoding_table[(unsigned char) encoding_table[i]] = i;
}

char *base64_encode(const unsigned char *data,
	size_t input_length,
	size_t *output_length) {

		*output_length = 4 * ((input_length + 2) / 3);

		char *encoded_data = (char*) malloc(*output_length);
		if (encoded_data == NULL) return NULL;

		unsigned int i , j;
		for (i = 0, j = 0; i < input_length;) {

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
		encoded_data[*output_length - 1 - i] = '=';

		return encoded_data;
	}


	std::string ReadFile(const char *name)
	{
		FILE *file;
		unsigned char *buffer;
		char *lobi;
		//Open file
		file = fopen(name , "rb");
		if (!file)
		{
			fprintf(stderr, "Unable to open file %s", name);
			return "error";
		}
		//Get file length
		fseek(file, 0, SEEK_END);
		long int fileLen=ftell(file);
		fseek(file, 0, SEEK_SET);
		//Allocate memory
		buffer=(unsigned char*)malloc(fileLen+1);
		if (!buffer)
		{
			fprintf(stderr, "Memory error!");
			fclose(file);
			return "error";
		}
		//Read file contents into buffer
		fread(buffer, fileLen, 1, file);
		size_t output_length = 0;
		lobi = base64_encode(buffer, fileLen, &output_length);
		return (std::string) lobi;
		FILE *fp;
		fp = fopen ( "salida.txt", "w+" );
		fputs(lobi,fp);
		fclose ( fp );
		fclose(file);
		free(buffer);
	}

	std::string Proyecto1::getB64()
	{

		std::string response=ReadFile("cursos.jpg");
		return response;


	}
	std::string Proyecto1::getB64Arbol()
	{

		std::string response=ReadFile("ABBC.jpg");
		return response;


	}

	std::string Proyecto1::getB64Agenda()
	{

		std::string response=ReadFile("Matriz.png");
		return response;


	}




	/*MAtriz Dispersa----------------------*/
	std::string Proyecto1::insertarMat(CoorMat mat)	{
		struct Edificio nuevo;
		nuevo.edificio=mat.edificio;
		nuevo.codigo=mat.coory;
		nuevo.capacidad=mat.capacidad;
		nuevo.datosalon=mat.datosalon;
		std::string response="Dato ingresado con exito";
		rai->existeX(mat.coorx,mat.datohora);//hora
		rai->existey(mat.coory,mat.datosalon,mat.edificio);//salon
		rai->InsertarMatriz(mat.coorx,mat.coory,mat.datocurso,mat.datocate,mat.dia);//curso
		//edi->InsertarEdificios(nuevo);
		Ddia->InsertarDia("Lunes",rai);

		return response;
	}

	std::string Proyecto1::graficarAgenda(){
		std::string response="";
		rai->graficarMatriz();
		return response;
	}


	std::string Proyecto1::mostrarMatriz(){
		std::string response="";
		Cabecera* aux=rai->primerocolumna;

		while(aux!=NULL){
			Matriz *temp=aux->primeromatriz;
			while(temp!=NULL){
				response=response+std::to_string(temp->coor.x)+"."+std::to_string(temp->coor.y)+",";
				temp=temp->siguiente;
			}
			aux=aux->siguiente;
		}
		return response;
	}
