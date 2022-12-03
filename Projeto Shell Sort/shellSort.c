/*********************************** IMPLEMENTAÇÃO DO ALGORITMO DE ORDENAÇÃO SHELL SORT	**********************************************************/


#include <stdio.h>
#include <stdlib.h>

void shellsort(int randArray[], int size)		//Protótipo da função ShellSort
	{
    int i, j, k, tmp;							//Declaração das variáveis de iteração i, j, k e do array temporário para realizar a comparação entre o array desordenado	
    for (i = size / 2; i > 0; i = i / 2)		//Primeiramente percorre o array até a metadade, como o princípio básico de algorítimo que é dividir o problema para solucioná-lo mais fácil
    {
        for (j = i; j < size; j++)				//Realiza a iteração da metade do vetor para trás atribuindo o tamanho de salto atual
        {
            for(k = j - i; k >= 0; k = k - i) 	//Realiza a iteração buscando o primeiro elemento ou seja j - i, após as próximas iterações ele ira percorrer elemento por elemento e os ordenando a partir da metade do vetor
            {
                if (randArray[k+i] >= randArray[k])	//Se o elemento visualizado, no caso da primeira iteração é o primeiro elemento do array e assim por diante for menor que o elemento que se encontra no meio do vetor ele permanecerá onde está e buscará o proximo elemento 
                    break;
                else								//Caso o elemento visualizado seja maior que o elemento apontado no fim do salto, em primeiro caso na metade do array, eles basicamente trocarão de lugar
                {
                    tmp = randArray[k];				//A variável temporária para o array aleatório agora é o elemento apontado, no caso o primeiro elemento. Ao atribuir esse valor à variável tmp ela funcionará como um espaço temporário para armazenar o elemento a ser trocado
                    randArray[k] = randArray[k+i];	//Agora o elemento que estava na metade do vetor é posicionado no lugar do elemento observado
                    randArray[k+i] = tmp;			//O elemento antes na posição observada agora ocupa a posição na metade do array e então desta forma os elementos são trocados de lugar
                	}
            	}
        	}										//Assim sendo, na próxima iteração o segundo elemento será observado como primeiro elemento do array desta forma a metade do array será o valor trocado mais uma posição, assim percorrendo todo o array e o ordenando 
    	}
	}

int main(void)										//Implementação do Shell Sort
{
    int size;
    printf("Insira o tamanho desejado para o Array: "); //Primeiro será definido o tamanho desejado para o array pelo usuário
    scanf("%d",&size);									//Armazena este valor
    int randArray[size], i;

    for(i=0;i<size;i++)
	{
        randArray[i]=rand()%100; 		//Popula o array com números aleatórios de 0 a 99
	}
	printf("\nArray com números aleatórios");    

	printf("\nElementos do Array: "); 
    for(i=0;i<size;i++)					//Exibe cada posição do array e seu respectivo elemento para que posteriormente a visualização da ordenação seja melhor
    {
        printf("\nNumero do Elemento %d : %d",i+1,randArray[i]);
    }
	printf("\n\n");
	
	shellsort(randArray, size);			//Algoritmo de ordenação Shell Sort é executado

	printf("Vetor agora ordenado pelo ShellSort\n\n");

	printf("\nElementos do Array: ");	//E agora o array será exibido, desta vez, ordenado pelo Shell Sort. A comparação pode ser feita através do output no terminal com o antes e depois do Array
    for(i=0;i<size;i++)
    {
        printf("\nNumero do Elemento %d : %d",i+1,randArray[i]);
    }
	printf("\n\n");

}