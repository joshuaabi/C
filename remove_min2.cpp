#include <stdio.h>
#include <iostream>
#define MAX 50
using namespace std;

int remover ( int n, int vetor[]);

int remover ( int n, int vetor[]){

	int k = 0, i = 0, menor = vetor[0];
		
	for(i = 0 ; i < n ; i++){
	 if(vetor[i] < menor){		// Encontrar o menor elemento
	 menor = vetor[i];
	 k = i;
	 }
 } 	
	   for (i = k+1; i < n+1; i++) {
      	vetor[i-1] = vetor[i];			//Remover o elemento e mover posições
      	
   }
   
   for(i = 0; i < n - 1   ; i++){
   	cout << vetor[i] << " ";
   }
}

int main(){
	int  tVetor, i;
	int valores[MAX];
	
	cout << "Entre com o tamanho do vetor" << endl;
	cin >> tVetor;
	valores[tVetor];
		for(i = 0 ; i < tVetor; i++){
			
		cin >>	valores[i] ;
		
		}
		remover(tVetor, valores);
}
