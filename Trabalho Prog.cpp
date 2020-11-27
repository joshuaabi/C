#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 500
#include <string.h>


/*Struct pro vetor de Clientes*/	

typedef struct{
	int numbCliente;
	float saldCliente;
	char nameClientes[25];
} Clientes;  

/*Declara��o de fun��es */

void insercaoCrescente (Clientes vetor[], int qntClientes);				
void imprimeVetor (Clientes clientes[], int qntClientes);	
void imprimeVetor2 (Clientes clientes[], int qntClientes);			
void selecaoDescre(int qntClientes, Clientes clientes[]);

int main() {
    
	setlocale(LC_ALL,"");
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int i, j, cont1 = 0,cont2 = 0,cont3= 0, cont4= 0,  tempConta1, tempConta2;				/* Variaveis temporarias  */
    int opcaoMenu , numeroCliente, numeroCliente2, qntClientes ;							/* Variaveis de intera��o em todo o c�digo */
    float valorTr;										
	bool encontrou;														
	char temp[24];

	Clientes clientes[MAX];		
	scanf("%d", &qntClientes);
	clientes[qntClientes];
	
	for(i = 0; i < qntClientes; i++){												
		scanf("%c",&temp); 	// Limpar Buffer 
   		scanf("%[^\n]",clientes[i].nameClientes);											/* Leitura de dados  inseridos pelo usuario */
		scanf("%5d", &clientes[i].numbCliente);
		scanf("%f", &clientes[i].saldCliente);    
	}
    
    do{
    /*	system("cls");*/
		printf("1. Consultar dados de um cliente \n");
		printf("2. Transfer�ncia de valor entre contas \n");								/* Menu */
		printf("3. Listagem de contas em ordem Crescente de saldo \n");
		printf("4. Listagem dos clientes em ordem alfab�tica (Decrescente ) \n");
		printf("0. Sair do Programa ! \n");
		
		scanf("%d", &opcaoMenu);
		switch(opcaoMenu) {
			case 0:
				printf("Encerrando!\n");
				break;
			/*Primeiro caso : Listar conta do Cliente   */	
			case 1:
				printf("Informe o n�mero de conta do cliente: \n");
				scanf("%d", &numeroCliente);
				
				encontrou = false;
				
				for(i = 0; i < qntClientes; i++ ) {
					if(clientes[i].numbCliente == numeroCliente ){
						printf("Cliente n�mero %d:\n  Nome:  %s\n  Saldo: %.2f\n\n", clientes[i].numbCliente, clientes[i].nameClientes, clientes[i].saldCliente);
						cont1++;
						encontrou = true;
						break;
					}	
				}
				printf("Foram feitas %d intera��es na op��o 1\n", cont1);

				if(!encontrou) {
					printf("Cliente n�o encontrado!\n");
				}
				
				break;
			/* Segundo caso : Transferir entre dois clientes  */		
			case 2:
				
				printf("Informe o n�mero de conta do cliente de Origem:\n");
				scanf("%d", &numeroCliente);
				printf("Informe o n�mero de conta do cliente de Destino:\n");
				scanf("%d", &numeroCliente2);
				printf("Informe o valor de transfer�ncia:\n");
				scanf("%f", &valorTr);
				
				for(i = 0; i < qntClientes; i++ ){
					if(clientes[i].numbCliente == numeroCliente ){											/*Se tiver a conta de origem, se n�o....  */
						tempConta1 = i;
						break;
					}else
					encontrou = false;
				}
				for(j = 0; j < qntClientes; j++ ){
					if(clientes[j].numbCliente == numeroCliente2 ){											/*Se tiver a conta de Destino, se n�o... */
						tempConta2 = j;
						break;
					}else
					encontrou = false;
				}
				
				if(clientes[tempConta1].saldCliente >= valorTr){											/* Se o saldo da conta de origem for maior ou igual */ 
					clientes[tempConta1].saldCliente = clientes[tempConta1].saldCliente - valorTr;			/* Existe conta de origem e destino */
					clientes[tempConta2].saldCliente = clientes[tempConta2].saldCliente + valorTr;
				printf("Novo saldo Conta de Origem: %.2f\n", clientes[tempConta1].saldCliente);
				printf("Novo saldo conta Destino : %.2f\n\n",clientes[tempConta2].saldCliente );
				cont2++;
				printf("Foram feitas %d intera��es na op��o 2\n", cont2);
				break;
				}else
				encontrou =false;
				
				if(!encontrou) {
					printf("Erro.\n");
				}				
				break;
				
				/* Terceiro caso listar em ordem de saldo, crescente por inser��o  */
			case 3:
				
				printf("Listagem de contas em ordem Crescente de saldo.\n");
				insercaoCrescente(clientes, qntClientes);
				cont3++;
				imprimeVetor(clientes, qntClientes);
				printf("Foram feitas %d intera��es na op��o 3\n", cont3);
				
				break;
				/* Quarto caso : Listar clientes em ordem alfabetica por sele��o  */
			case 4:
				cont4++;

				printf("Listagem dos clientes em ordem alfab�tica. ( Decrescente )\n");
			
				selecaoDescre(qntClientes,  clientes);
				imprimeVetor2(clientes, qntClientes);
				
				printf("Foram feitas %d intera��es na op��o 4\n", cont4);
				break;
			
			default:
				printf("Opcao n�o encontrada!\n");
				break;    
		}
		
		if(opcaoMenu != 0) {
			printf("Pressione qualquer tecla para continuar...");												
		/*
			getchar();
			getchar();  
		*/	
		}
		
	} while(opcaoMenu != 0);
	return 0;
}

/* 
Fun��o para inser��o crescente 
Come�ando na posi��o 1, pois a primeira n�o precisa verificar
 
*/
void insercaoCrescente (Clientes vetor[], int qntClientes) {  
	int i , j;
	Clientes cliente;
							
    for(i = 1; i < qntClientes; i++){																			/*Come�ar na posi��o 1, para fazer intera��o com a posi��o 0  */
        cliente = vetor[i];
        for(j = i - 1 ; j >= 0 && vetor[j].saldCliente > cliente.saldCliente; j--){								/* Se o saldo de origem for maior que o proximo, armazena em vetor temporario */
            vetor[j+1] = vetor[j];																				
        }
        vetor[j+1] = cliente;																					/* Retorna o saldo para a posi��o correta */
    }
}
	/*
	Fun��o de impress�o apenas da Inser��o 
	*/
void imprimeVetor (Clientes clientes[], int qntClientes) {														/*Fun��o de exibir Numero, nome e saldo . Exclusivo para o caso de inser��o */		
	for(int i = 0; i < qntClientes; i++) {
		printf("Cliente n�mero %d:\n  Nome:  %s\n  Saldo: %.2f\n\n", clientes[i].numbCliente, clientes[i].nameClientes, clientes[i].saldCliente);	
	}
}
	/*
	Fun��o de impress�o apenas da Sele��o
	*/

void imprimeVetor2 (Clientes clientes[], int qntClientes) {
	for(int i = 0; i < qntClientes; i++) {																		/*Fun��o de exibir Nome, e saldo .   Exclusiva para o caso de sele��o */
		printf("  Nome:  %s\n  Saldo: %.2f\n\n", clientes[i].nameClientes, clientes[i].saldCliente);
	}
}


void selecaoDescre(int qntClientes, Clientes clientes[]){
	
	for(int i = 0; i < qntClientes  ;i++){
		for(int j = i+1 ; j < qntClientes; j++){
			Clientes vetorTemp[25];	
			if(strcmp(clientes[j].nameClientes, clientes[i].nameClientes) > 0){			/* Compara as duas Strings, onde a j, vem ap�s da i                   */
				/*		DESTINO 						ORIGEM */
				strcpy(vetorTemp[i].nameClientes, clientes[i].nameClientes);			/* Armazena a string de maior valor na temporaria                     */
				vetorTemp[i].saldCliente = clientes[i].saldCliente;						/* Troca o valor do saldo,*                                           */
			    vetorTemp[i].numbCliente = clientes[i].numbCliente;						/* Troca o valor da conta ( sem isso a op��o 1 vai ficar bugada)**    */
				strcpy(clientes[i].nameClientes, clientes[j].nameClientes );			/* Realiza a troca entre duas Strings                                 */
				clientes[i].saldCliente = clientes[j].saldCliente;						/* *                                                                  */
				clientes[i].numbCliente = clientes[j].numbCliente;						/* **                                                                 */
				strcpy(clientes[j].nameClientes, vetorTemp[i].nameClientes);			/* A posi��o atual recebe o valor temporario                          */
				clientes[j].saldCliente = vetorTemp[i].saldCliente;						/* *                                                                  */
				clientes[j].numbCliente = vetorTemp[i].numbCliente;						/* **                                                                 */
			
			}
		}
	}	
}



