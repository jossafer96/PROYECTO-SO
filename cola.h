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
#endif // COLA_H_INCLUDED
