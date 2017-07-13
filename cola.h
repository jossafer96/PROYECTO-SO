#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
/*Practice No. 4: Queue */
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class Cola {
	
private:
	class Nodo {
	public:
		T dato;
		Nodo* siguiente;
	};
	Nodo* nuevo;
	Nodo* inicio;
	Nodo* fin; //fondo
public:
	Cola();
	~Cola();
	
	void insertar(string x);
	int extraer();
	void imprimir();
	bool vacia();
	void encolar( struct cola &q, string valor1,string valor2,string valor3,string valor4,string valor5, string priori  );
	void muestraCola( struct cola q );
	void ordenarPrioridad( struct cola &q );
		
};

/*************Constructor,destructor********/
template <typename T>
Cola<T>::Cola()
{
	inicio = NULL;
	fin = NULL;
}

template <typename T>
Cola<T>::~Cola()
{
	Nodo* recorrido = inicio;
	Nodo* bor;
	while (recorrido != NULL) {
		bor = recorrido;
		recorrido = recorrido->siguiente;
		delete bor;
	}
}

/*************Métodos (Funciones)***********/
template <typename T>
void Cola<T>::insertar(string x)
{ T y=x;
	nuevo = new Nodo();
	nuevo->dato = y;
	nuevo->siguiente = NULL;
	if (vacia()) {
		inicio = nuevo;
		fin = nuevo;
	}
	else {
		fin->siguiente = nuevo;
		fin = nuevo;
	}
}

template <typename T>
int Cola<T>::extraer()
{
	if (!vacia()) {
		string informacion = inicio->dato;
		Nodo* bor = inicio;
		if (inicio == fin) {
			inicio = NULL;
			fin = NULL;
		}
		else {
			inicio = inicio->siguiente;
		}
		cout << "Dato eliminado, ahora el dato a quitar  es:" << inicio->dato << endl;
		delete bor;
		//return informacion;
	}
	else {
		cout << endl
			<< "Empty Queue!!!" << endl;
		//return -1;
	}
}

template <typename T>
void Cola<T>::imprimir()
{
	Nodo* recorrido = inicio;
	
	while (recorrido != NULL) {
		cout  << recorrido->dato << endl;
		recorrido = recorrido->siguiente;
	}
	cout << endl;
}

template <typename T>
bool Cola<T>::vacia()
{
	if (inicio == NULL)
		return true;
	else
		return false;
}
struct nodo
{
	string dato1;
	string dato2;
	string dato3;
	string dato4;
	string dato5;
	string priori;        // prioridad del nodo
	struct nodo *sgte;
};

/*                      Estructura de la cola      
------------------------------------------------------------------------*/
struct cola
{
	nodo *delante;
	nodo *atras  ;
};

struct nodo *crearNodo( string x,string y,string z,string w,string s, string pr)
{
	struct nodo *nuevoNodo = new(struct nodo);
	nuevoNodo->dato1 = x;
	nuevoNodo->dato2 = y;
	nuevoNodo->dato3 = z;
	nuevoNodo->dato4 = w;
	nuevoNodo->dato5 = s;
	nuevoNodo->priori = pr;
	return nuevoNodo;
}

template <typename T>
void Cola<T>::encolar( struct cola &q, string valor1,string valor2,string valor3,string valor4,string valor5, string priori )
{
	
	struct nodo *aux = crearNodo(valor1,valor2,valor3,valor4,valor5, priori);
	aux->sgte = NULL;
	
	if( q.delante == NULL)
		q.delante = aux;   // encola el primero elemento
	else
		(q.atras)->sgte = aux;
	
	q.atras = aux;        // puntero que siempre apunta al ultimo elemento 
}
template <typename T>
void Cola<T>::muestraCola( struct cola q )
{
	
	Cola<string> C;
	Cola<string> D;
	Cola<string> E;
	Cola<string> F;
	Cola<string> G;
	Cola<string> H;
	struct nodo *aux;
	
	aux = q.delante;
	cout<<""<<endl;
	cout<<  " Procesos Ordenados por prioridad"<<endl;
	cout << " Caracter   Estado   #Instrucciones   #Bloqueo   Evento  Prioridad " << endl;
	cout << " ----------------------------------------------------------------- " << endl;
	
	while( aux != NULL )
	{
		cout<<"    "<< aux->dato1 << "     |   " << aux->dato2 << "     |   " << aux->dato3 << "     |   " << aux->dato4 << "     |   " << aux->dato5 << "     |   " << aux->priori <<    endl;
		C.insertar(aux->dato1);
		D.insertar(aux->dato2);
		E.insertar(aux->dato3);
		F.insertar(aux->dato4);
		G.insertar(aux->dato5);
		H.insertar(aux->priori);
		
		aux = aux->sgte;
		
		
		
	}    
	
	
	
	cout << "Listado de todos los ID." << endl;
	C.imprimir();
	cout << "Listado de todos los Estados." << endl;
	D.imprimir();
	cout << "Listado de todos las Prioridades." << endl;
	H.imprimir();
	cout << "Listado de todos las Instrcciones." << endl;
	E.imprimir();
	cout << "Listado de todos las Instrucciones de Bloqueo." << endl;
	F.imprimir();
	cout << "Listado de todos los Eventos." << endl;
	G.imprimir();
}

template <typename T>
void Cola<T>::ordenarPrioridad( struct cola &q )
{
	struct nodo *aux1, *aux2;
	string p_aux;
	string c_aux1;
	string c_aux2;
	string c_aux3;
	string c_aux4;
	string c_aux5;
	
	aux1 = q.delante;
	
	while( aux1->sgte != NULL)
	{
		aux2 = aux1->sgte;
		
		while( aux2 != NULL)
		{
			if( aux1->priori > aux2->priori )
			{
				p_aux = aux1->priori;
				c_aux1 = aux1->dato1;
				c_aux2 = aux1->dato2;
				c_aux3 = aux1->dato3;
				c_aux4 = aux1->dato4;
				c_aux5 = aux1->dato5;
				
				aux1->priori = aux2->priori;
				aux1->dato1 = aux2->dato1;
				aux1->dato2  = aux2->dato2;
				aux1->dato3 = aux2->dato3;
				aux1->dato4 = aux2->dato4;
				aux1->dato5  = aux2->dato5;
				
				aux2->priori = p_aux;
				aux2->dato1 = c_aux1;
				aux2->dato2 = c_aux2;
				aux2->dato3 = c_aux3;
				aux2->dato4 = c_aux4;
				aux2->dato5 = c_aux5;
			}
			
			aux2 = aux2->sgte;
		}
		
		aux1 = aux1->sgte;
	}
}
#endif // COLA_H_INCLUDED
