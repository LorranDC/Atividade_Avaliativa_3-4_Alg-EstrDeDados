/************************************************** Implementação do Algorítmo de Busca Binária ***********************************************/
#include <stdio.h>
// OBS: Presupõe-se que o array já esteja ordenado

//É basicamente a lógica que ficou famosa por ser usada no Império Romano 'Dividir para conquistar' aplicada à Computação 

int binaryChop(int arr[], int l, int r, int x)	//Protótipo do método de Busca Binária a qual retorna a posição do elemento a ser encontrado dentro do array ou informa caso não esteja presente no array
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		if (arr[m] == x)	//Primeiramente verifica se o elemento desejado está presente no meio do array
		{			
		return m;
		}
		if (arr[m] < x)		//Se o elemento desejado é maior que o elemento presente no meio do array (no caso, localizado à direira) o lado esquerdo é ignorado, facilitando a busca (Dividir para conquistar)
		{
			l = m + 1;
		}
		else				//Se o elemento desejado é menor que o elemento presente no meio do array, o lado direiro é ignorado
			r = m - 1;
		}
	return -1;				//Caso nenhuma das opções seja satisfeita é porque o elemento desejado não está presente, então é retornado -1 
}

int main(void)				//Implementação do Algorítmo de Busca Binária
{
	int arr[] = { 1, 2, 3, 4, 5, 10, 20, 30, 60, 120, 240};	//Primeiro o array é declarado (Previamente ordenado para que a busca seja efetiva)
	int n = sizeof(arr) / sizeof(arr[0]);					//Declaraçao da variavel referente ao tamanho do array sem precisar que seu tamanho seja explicitamente especificado 	
	int x;													//Valor o qual o usuário deseja encontrar
	printf("\nQual valor deseja buscar no array?\n:");		//Pede ao usuário algum elemento a ser encontrado no array
	scanf(" %i", &x);										//Valor é armazenado
	int result = binaryChop(arr, 0, n - 1, x);			//Variável referente ao resultado da busca

	(result == -1) ? printf("O elemento desejado não está presente no array") : printf("O elemento está presente na posição %d \n",result); //Informa a posição do array ou se ele não está presente no array
	return 0;
}
