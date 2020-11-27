#include <stdio.h>
#include <iostream>
#define MAX 50

#include <string.h>

using namespace std;

	typedef struct{
	int nEstudante;
	char nameEstudante[25];
} Estudantes;

void imprime(int nEncontrar, int tVetor, Estudantes estudantes[]);

void imprime(int nEncontrar, int tVetor, Estudantes estudantes[]){
	bool encontrou = false; 
	int aux, i , j;
	aux = nEncontrar;
	for(i = 0; i < tVetor; i++ ) {
		if(estudantes[i].nEstudante == aux ){
		cout  << estudantes[i].nameEstudante;
	
		encontrou = true;
		break;
			}
				
	}
		if(!encontrou) {
		cout << "not found" << endl;
	}
}


int main(){
	
	int nEncontrar , tVetor, i;
	Estudantes estudantes[MAX];
	
	cout << " Entre com numero de estudante para encontrar" << endl;
	cin >> nEncontrar;	
	
	cout << "Entre com o tamanho do vetor" << endl;
	cin >> tVetor;
	
	estudantes[tVetor];
	
		for(i = 0 ; i < tVetor; i++){
			
		cin >>	estudantes[i].nEstudante;
		cin >>  estudantes[i].nameEstudante;
			
		}
		
		imprime(nEncontrar, tVetor, estudantes);
		
		
		
return 0;	
}
