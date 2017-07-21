
#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
/*Practice No. 4: Queue */
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
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
	
	void insertar(int x);
	int extraer(struct cola q);
	void imprimir();
	bool vacia();
	void encolar( struct cola &q, string valor1,string valor2,string valor3,string valor4,string valor5, string priori  );
	void modificar( struct cola &q, string valor1,string valor2,string valor3,string valor4,string valor5, string priori );
	void muestraCola( struct cola q );
	void ordenarPrioridad( struct cola &q );
		
};

/*************Constructor,destructor********/
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
void Cola<T>::insertar(int x)
{  
	nuevo = new Nodo();
	nuevo->dato = x;
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
int Cola<T>::extraer(struct cola q)
	
	
{
	struct nodo *aux;
	
	aux = q.delante;
	
	if (!vacia()) {
		string informacion = aux;
		Nodo* bor = q.delante;
		if (q.delante ==0) {
			q.delante = NULL;
			q.atras = NULL;
		}
		else {
			int x=q.delante->dato1;
				
			q.delante = x-1;
		}
		cout << "Dato eliminado, ahora el dato a quitar  es:" << q.delante->dato1 << endl;
		
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
void Cola<T>::modificar( struct cola &q, string valor1,string valor2,string valor3,string valor4,string valor5, string priori )
{
	
	struct nodo *aux1;
	
	
	aux1 = q.delante;
	while( aux1->sgte != NULL)
	{
	if(aux1->dato1==valor1){
		aux1->priori = priori;
		aux1->dato1 = valor1;
		aux1->dato2  = valor2;
		aux1->dato3 = valor3;
		aux1->dato4 = valor4;
		aux1->dato5  = valor5;
	}
	aux1 = aux1->sgte;
	}
	
	 
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
	
	cout<<""<<endl;
	/*cout<<  " Procesos Ordenados por prioridad"<<endl;
	cout << " Caracter   Estado   #Instrucciones   #Bloqueo   Evento  Prioridad " << endl;
	cout << " ----------------------------------------------------------------- " << endl;
	
	while( aux != NULL )
	{
		cout<<"    "<< aux->dato1 << "     |   " << aux->dato2 << "     |   " << aux->dato3 << "     |   " << aux->dato4 << "     |   " << aux->dato5 << "     |   " << aux->priori <<    endl;
		
		
		aux = aux->sgte;
		
		
		
	}    */
	
	int b,d,f,h,j,k,l=0,m=0,n=0,o=0,p=0,r,i;
	cout<<"ingrese el numeo de ciclos"<<endl;
	cin>>o;
	struct nodo *aux;
	
	aux = q.delante;
	
		while(aux!=NULL){
			string v=aux->priori;
			string a=aux->dato1;
			string c=aux->dato2;
			string w=aux->dato5;
			r=atoi(w.c_str());
			string e=aux->dato4;
			f=atoi(e.c_str());
			string g=aux->dato3;
			h=atoi(g.c_str());
			n+=atoi(g.c_str());
			
		for(i=0;i<o;i++){
				if(l<f){
					l++;
				}else{
					p++;	
				}
				if(f==3&&p==13){
					l+=p;
				}
				if(f==5&&p==27){
					l+=p;
				}
		}	
		int b=h-l;
		string s=""+b;
		int t=f-l;
		string u=""+t;
		modificar(q,a,c,s,u,e,v);
			
			
			if(l<o){
				aux = aux->sgte; 
				if(aux==NULL){
					aux=q.delante;
				}	
			}else{
				aux = NULL;
			}
				
			
			
		}
		
		
	
	k=l-i;
	/*C.insertar(h);
	D.insertar(j);
	E.insertar(k);
	F.insertar(l);
	G.insertar(m);*/
	
	
	
	
	
	
	
	cout << "NUEVO" << endl;
	cout<<h<<endl;
	
	cout << "LISTO." << endl;
	cout<<n<<endl;
	cout << "EJECUTANDO." << endl;
	cout<<l<<endl;
	cout << "BLOQUEADO" << endl;
	cout<<p<<endl;
	cout << "SALIENTE" << endl;
	cout<<k<<endl;
	
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
