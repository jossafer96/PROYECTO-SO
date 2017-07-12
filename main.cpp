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
	
	/************* Menu ***********/
	bool flag = false;
	char tecla;
	char answer[2];
	
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
				while(ptr1 != NULL)
				{
					string dato = string(ptr1);
					if(a==0){
						A.insertar(dato);
					}
					if(a==1){
						B.insertar(dato);
					}
					if(a==2){
						C.insertar(dato);
					}
					if(a==3){
						D.insertar(dato);
					}
					if(a==4){
						E.insertar(dato);
					}
					if(a==5){
						F.insertar(dato);
					}
					//cout<<dato<<endl;
					//insertar(dato);
					
					ptr1 = strtok(NULL,"/");
					a++;
				}
				
			}
			
			ficheroEntrada.close();
			
		}
		cout << "Listado de todos los ID." << endl;
		A.imprimir();
		cout << "Listado de todos los Estados." << endl;
		B.imprimir();
		cout << "Listado de todos las Prioridades." << endl;
		C.imprimir();
		cout << "Listado de todos las Instrcciones." << endl;
		D.imprimir();
		cout << "Listado de todos las Instrucciones de Bloqueo." << endl;
		E.imprimir();
		cout << "Listado de todos los Eventos." << endl;
		F.imprimir();
		//listar();
	}else 
							   cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
	
	
	
	 
	return 0;
}
