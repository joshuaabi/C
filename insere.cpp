#include <stdio.h>
#include <iostream>
#define MAX 50
using namespace std;


void inserirValor(int k, int n, int vetor[]);
void inserirValor(int k, int n , int vetor[]){
    
  int i, j, aux; 
  n = n+1;

	vetor[n-1] = k;
 
for(i = 0; i < n -1 ; i++){
	for(j = i+1 ; j > 0; j--){
		if(vetor[j] < vetor[j-1]){
			aux = vetor[j];
			vetor[j] = vetor[ j -1 ];
			vetor[j-1] = aux;
		}
	}
}
  	for( i = 0 ; i < n ;i++){
		cout << vetor[i] << " ";
	} 
}


int main(){
	
	int k, n, i, vetor[MAX];
	
	cout<<"Entre com o valor a ser inserido" << endl;
	cin>>k;
	cout<<"Entre com o tamanho do vetor" << endl;
	cin>>n;
	
	vetor[n];

	for(i = 0; i < n ; i++){
		
		cin >> vetor[i];
	}
	
	
	inserirValor(k, n, vetor);
	
return 0;

}
