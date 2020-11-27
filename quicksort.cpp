#include <stdio.h>
#include <iostream>
#define MAX 50
using namespace std;

void selecaoD (int n, int vetor[]);


void selecaoD (int n, int vetor[]){

int min = 0, i, j, aux;

   for ( i = 0; i < n-1; ++i) {
      min = i;
      for ( j = i+1; j < n; ++j)
         if (vetor[j] > vetor[min]) 
		 min = j;
       aux = vetor[i]; 
	  vetor[i] = vetor[min]; 
	  vetor[min] = aux;
   }
   
   for( i = 0 ; i < n ; i++){
   	cout << vetor[i] << " ";
   }
}

int main(){
	
	int n, i;
		
	cin >> n;
	int vetor[n];

	for(i = 0 ; i < n ; i++){
		

	cin >> vetor[i];
		
	}
	selecaoD( n, vetor);	
	
	return 0;
		
}
