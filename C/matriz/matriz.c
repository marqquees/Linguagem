/*
    Escreva um programa que defina uma matriz quadrada de dimensão máxima [4] e implemente as seguintes funções: 
    
    1. Uma função que faça a leitura dos elementos da matriz, guardando os valores em memória RAM, com o seguinte protótipo:
        void leitura(int matriz[][MAX_C]);
    2. Uma função que devolva a média da diagonal principal, com o seguinte protótipo:
        float media_diagonal(int matriz[][MAX_C]);
    3. Uma função que devolva um vector com os elementos cujo valor seja superior à média da diagonal principal, com o seguinte protótipo:
        void superior_media(int matriz[][MAX_C], float mdiagonal);
    4.Uma função que devolva uma matriz com o número de ocorrências de cada elemento, com o seguinte protótipo:
        void ocorrencia(int matriz[][MAX_C], int matriz_ocorr[][2]);
    
    A função main deverá chamar uma função que apresente o menu com as opções aos utilizadores.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_L 2
#define MAX_C 2

void leitura(int matriz[][MAX_C]);
float media_diagonal(int matriz[][MAX_C]); 
void superior_media(int matriz[][MAX_C], float mdiagonal);
void ocorrencia(int matriz[][MAX_C], int matriz_ocorr[][2]);


int main()
{
    int matriz[MAX_L][MAX_C] = {0};
    int matriz_ocorr[MAX_L * MAX_C][2] = {0};
    int mdiagonal = 0;

    leitura(matriz);
    mdiagonal = media_diagonal(matriz);
    superior_media(matriz, mdiagonal);
    ocorrencia(matriz, matriz_ocorr);

    return 0;
}

void leitura(int matriz[][MAX_C])
{
    printf("\nDigite %d valores inteiros.\n", MAX_L * MAX_C);
    for (int linha = 0; linha < MAX_L; linha++)
    {   
        for (int coluna = 0; coluna < MAX_C; coluna++)
        {
            printf("Elemento [%d][%d]: ", linha, coluna);
            scanf("%d", &matriz[linha][coluna]);           
        }
    }
}

float media_diagonal(int matriz[][MAX_C])
{
    float soma = 0, media = 0;
    for (int linha = 0; linha < MAX_L; linha++)
        soma += matriz[linha][linha];

    media = soma / MAX_L;
    printf("\nMedia: %.1f", media);
    return media;
}

void superior_media(int matriz[][MAX_C], float m_diagonal)
{
    int vetor[MAX_L * MAX_C];
    int indice = 0;
    for (int linha = 0; linha < MAX_L; linha++)
    {   
        for (int coluna = 0; coluna < MAX_C; coluna++)
        {
            if (matriz[linha][coluna] > m_diagonal)
            {
                vetor[indice] = matriz[linha][coluna];   
                indice++;
            }
        }
    }

    printf("\nVetor: ");
    for (int i = 0; i < indice; i++)
        printf("%d | ", vetor[i]);
}

void ocorrencia(int matriz[][MAX_C], int matriz_ocorr[][2])
{
    int numero_elemento = 0;
    // Percorre todos os elementos da matriz.
    for (int linha = 0; linha < MAX_L; linha++) 
    {
        for (int coluna = 0; coluna < MAX_C; coluna++) 
        {
            bool encontrado = true;
            // Verifica se o valor já foi contado.
            for (int k = 0; k < numero_elemento; k++) 
            {
                if (matriz_ocorr[k][0] == matriz[linha][coluna]) 
                {
                    matriz_ocorr[k][1]++; // Incrementa a contagem do valor.
                    encontrado = true;
                    break;
                }
            }
            // Se o valor ainda não foi contado, adiciona à matriz_ocorr.
            if (!encontrado) 
            {
                matriz_ocorr[numero_elemento][0] = matriz[linha][coluna]; // Armazena o valor.
                matriz_ocorr[numero_elemento][1] = 1; // Inicializa a contagem como 1.
                numero_elemento++; // Incrementa o contador de elementos únicos.
            }
        }
    }

    printf("\nElemento(s) | Ocorrencia(s)");
    for (int i = 0; i < numero_elemento; i++)
        printf("\n%8d | %11d", matriz_ocorr[i][0], matriz_ocorr[i][1]);
}