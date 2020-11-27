#include <stdio.h>
#include <iostream>
#define MAX 50
using namespace std;

void buscarBinario( int k, int vetor[MAX]);

void buscarBinario(int k,  int vetor[MAX]){
	int temp;
	int cont = -1;
	for(int i = 0; i < temp; i++){
		if(k == vetor[i]){
			
			cout << "O k está na posição " << i;
			break;
		}else
			cout << temp; 
		
	}
	
	
}

int main(){
	
	int k, cont, qntInteiros, i , j;
	
	cout << "Entre com o valor inicial" << endl;
	cin >> k ;
	cout << "Entre com a quantidade de inteiros " << endl;
	cin >> qntInteiros;
	
	int vetor[qntInteiros];
	
	for(i = 0; i < qntInteiros; i++){
		cout << " Entre com o valor na posicao: " << i << endl;
		cin >> vetor[i];
		
	}
	buscarBinario(k , vetor[qntInteiros]);
	
	for(i = 0 ; i < qntInteiros; i++){
		if(vetor[i] == k){
			cout << "O "<< k <<" está na posição: " << i;
			break;
			
		}else
		cout << -1;
	}
	
	return 0;
}
