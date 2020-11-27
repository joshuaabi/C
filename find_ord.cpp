#include <stdio.h>
#include <iostream>
#define MAX 50


using namespace std;

int buscarBinario( int k, int vetor[MAX] ,int n );

int buscarBinario(int k, int vetor[MAX] ,int n ){
	int esq, dir, meio;
    esq = -1;
    dir = k;

    while (esq < dir - 1) {
        meio = (esq + dir) / 2;

        if(vetor[meio] == n)
            return meio;
        if (vetor[meio] < n)
            esq = meio;
        else
            dir = meio;
    }

    return -1;
}

int main(){
	
	int k = 0, qntInteiros = 0, i = 0 ;
	int vetor[MAX];

	cin >> k;
	
	cin >> qntInteiros;
	

	
	for(i = 0; i < qntInteiros; i++){
		
		cin >> vetor[i];	
	}
	cout << buscarBinario(qntInteiros ,vetor, k );
	
	return 0;
}
