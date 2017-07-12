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
	
	string instrucciones1[1000];
	string instrucciones2[1000];
	string instrucciones3[1000];
	string instrucciones4[1000];
	
	int i=0;
	
	cout << "Dime el nombre del fichero: ";
	getline(cin,nombre);
	
	
	ficheroEntrada.open ( nombre.c_str() , ios::in);
	if (ficheroEntrada.is_open()) {
		
		while (! ficheroEntrada.eof() ) {
			getline (ficheroEntrada,frase);
			array[i]=frase;
			i++;
			
		}
		for(int j=0;j<2;j++){
			
			string oracion= array[j];
			char *frase = (char*)oracion.c_str(); 
			char *ptr;
			cout << "Proceso: " << frase << endl;
			ptr = strtok(frase,";");
			int c = 0;
			string procesos[1000];
			while(ptr != NULL)
			{
				procesos[c] = ptr;
				string oracion1=procesos[c];
				char *frase1 = (char*)oracion1.c_str(); 
				char *ptr1;
				ptr1 = strtok(frase1,"/");
				int a = 0;
				while(ptr1 != NULL)
				{
					if(a==0){
						instrucciones1[a] = ptr1;
						ptr1 = strtok(NULL, "/");
						a++;
					}
					if(a==1){
						instrucciones2[a] = ptr1;
						ptr1 = strtok(NULL, "/");
						a++;
					}
					if(a==2){
						instrucciones3[a] = ptr1;
						ptr1 = strtok(NULL, "/");
						a++;
					}
					if(a==3){
						instrucciones4[a] = ptr1;
						ptr1 = strtok(NULL, "/");
						a++;
					}
					
					
				}
				ptr = strtok(NULL, ";");
				c++;
					
				
				
			}
			
			for(int x=0;x<3;x++){
				cout<<instrucciones1[x]<<endl;
		}
			

		
		}
		ficheroEntrada.close();
	}
	else cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;  
	
	
	

	return 0;
}

