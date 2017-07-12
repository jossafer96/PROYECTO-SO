#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cola.h"

using namespace std;

struct datos {
	int dato;
	datos *s;
}*p,*aux,*u;

void insertar (int dat);
void borrar ();
void listar ();

int main(int argc, char *argv[]) {
	fstream ficheroEntrada;
	string nombre;
	string frase;
	string array[10];
	
	cout << "Dime el nombre del fichero: ";
	getline(cin,nombre);
	
	
	ficheroEntrada.open ( nombre.c_str() , ios::in);
	if (ficheroEntrada.is_open()) {
		
		while (! ficheroEntrada.eof() ) {
			getline (ficheroEntrada,frase);
			string oracion= frase;
			char *frase = (char*)oracion.c_str(); 
			char *ptr;
			ptr = strtok(frase,";");
			int j=0;
			while(ptr != NULL)
			{
				array[j] = ptr;
				ptr = strtok(NULL, ";");
				j++;
			}
			
			for(int z=0;z<j;z++){
				string procesos;
				procesos=array[z];
					string oracion1=procesos;
					cout<<oracion1<<endl;
					char *frase1 = (char*)oracion1.c_str(); 
					char *ptr1;
					ptr1 = strtok(frase1,"/");
					int a = 0;
					while(ptr1 != NULL)
					{
						int dato = atoi(ptr1);
						//cout<<dato<<endl;
						insertar(dato);
						ptr1 = strtok(NULL,"/");
						a++;
					}
					
			}
			
			ficheroEntrada.close();
			
			}
		listar();
		}else 
		cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
		
	

	return 0;
}
void insertar (int dat)
{
	aux=new(datos);
	aux->dato=dat;
	if(u)
	{
		u->s=aux;
		aux->s=NULL;
		u=aux;
	}
	else
	{
		p=u=aux;
	}
}
void borrar()
{
	if(p)
	{
		aux=p;
		cout<<"\nElimino a " <<p->dato;
		p=aux->s;
		delete(aux);
	}
	else
	{
		cout<<"\n No hay datos";
	}
}

void listar()
{
	int i;
	if(!u)
	{
		cout<<"\n No hay datos en la cola";
		return;
	}
	aux=p;
	while(aux)
	{
		cout<<"\n"<<++i<<" - "<<aux->dato;
		aux=aux->s;
	}
}
