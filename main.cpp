#include <iostream>
#include "cola.h"
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	
	
	Cola<string> A;
	Cola<string> B;
	Cola<string> C;
	Cola<string> D;
	Cola<string> E;
	Cola<string> F;
	
	struct cola q;
	
	q.delante = NULL;
	q.atras   = NULL;
	
	struct cola p;
	
	p.delante = NULL;
	p.atras   = NULL;
	
	
	
	
	fstream ficheroEntrada;
	string nombre="Datos.txt";
	string frase;
	string array[10];
	
	
	
	
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
				string g;
				string b;
				string c;
				string d;
				string e;
				string f;
				while(ptr1 != NULL)
				{
					string dato = string(ptr1);
					if(a==0){
						g=dato;
					}
					if(a==1){
						b=dato;
					}
					if(a==2){
						c=dato;
					}
					if(a==3){
						d=dato;
					}
					if(a==4){
						e=dato;
					}
					if(a==5){
						f=dato;
					}
					//cout<<dato<<endl;
					//insertar(dato);
					
					ptr1 = strtok(NULL,"/");
					a++;
				}
				
				A.encolar( q, g,b,d,e,f, c );
				A.ordenarPrioridad(q);
				
			}
			
			ficheroEntrada.close();
			
		}
		
	
		A.muestraCola(q);
		cout<<""<<endl;
		//listar();
	}else 
	cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
	
	
	
	 
	return 0;
}
