/*
    Criem um programa que leia dez números inteiro se permita ao utilizador escolher a opção pretendida.
    
    1. Maior número.
    2. Menor número.
    3. Média.
    4. Altera um valor lido indicando a posição.
    5. Imprimir o vetor com todos os valores inseridos.
    6. Sair
    
    Cada uma das opções deve ser desenvolvida numa função à parte.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX 4

void leitura(int vetor[]);
void maior(int vetor[]);
void menor(int vetor[]);
void media(int vetor[]);
void posicao(int vetor[]);
void imprime(int vetor[]);
void limpa_ecra();

int main(void)
{
    int vetor[MAX] = {0};
    int opcao;

    do
    {
        puts("1. Maior");
        puts("2. Menor");
        puts("3. Media");
        puts("4. Posicao");
        puts("5. Imprimir os Valores");
        puts("6. Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                maior(vetor);
                break;
            case 2:
                menor(vetor);
                break;
            case 3:
                media(vetor);
                break;
            case 4: 
                posicao(vetor);
                break;
            case 5:
                imprime(vetor);
                break;
            case 6:
                break;
        }

        limpa_ecra();
        return 0;
    } while (opcao != 6);
}

void leitura(int vetor[])
{
    printf("\nDigite %d valores inteiros.\n", MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("Valor [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}

void maior(int vetor[]) 
{
    leitura(vetor);
    int maior = vetor[0];
    for (int i = 1; i < MAX; i++)
        if (vetor[i] > maior)
            maior = vetor[i];
    printf("\nMaior: %d", maior);
}

void menor(int vetor[])
{
    leitura(vetor);
    int menor = vetor[0];
    for (int i = 1; i < MAX; i++)
        if (vetor[i] < menor)
            menor = vetor[i];
    printf("\nMenor: %d", menor);
}

void media(int vetor[])
{
    float soma = 0, media;

    leitura(vetor);
    for (int i = 0; i < MAX; i++)
        soma += vetor[i];
    media = soma / MAX;
    printf("\nMedia: %.2f", media);
}

void posicao(int vetor[])
{
    int posicao = 0, valor = 0;
    bool substituir = false;

    leitura(vetor);
    printf("\nPosicao (0 a %d): ", MAX - 1);
    scanf("%d", &posicao);

    if (posicao >= 0 && posicao < MAX) 
    {
        printf("\nValor para substituir na posicao [%d]: ", posicao);
        scanf("%d", &valor);
        vetor[posicao] = valor;
        substituir = true;
    }
    if (substituir)
        imprime(vetor);
    else
        puts("Posicao invalida! Tente novamente.\n");
    //Falta loop de verificação.
}

void imprime(int vetor[])
{
    printf("\nVetor: ");
    for (int i = 0; i < MAX; i++)
        printf("%d ", vetor[i]);
    puts("");
}

void limpa_ecra()
{
    // Delay de 4 segundos antes de limpar o ecrã.
    #ifdef _WIN32
        Sleep(4000);  
    #else
        sleep(3);
    #endif

    //Limpa o ecrã.
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
    
    