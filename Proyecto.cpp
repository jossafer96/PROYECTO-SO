#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

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
						cout<<ptr1<<endl;
						ptr1 = strtok(NULL,"/");
						a++;
					}
					
			}
			
			ficheroEntrada.close();
			
			}
			
		}else 
		cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
		
	

	return 0;
}
