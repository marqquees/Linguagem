#include <stdio.h>

#include "assinatura.h"

void menu(void)
{
    int opcao = 0;
    do
    {
        puts("1. Casa");
        puts("2. Adicionar Consultor");
        puts("\n0. Sair");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                casa();
                break;
            case 2:
                consultor();
                break;
        }
    } while (opcao != 0);
    
    
}

void conexao_mysql(void)
{
    puts("Conexão a base de dados MySQL.");
}

void casa(void)
{
    puts("Adicionar Casa!");
}

void consultor(void)
{
    puts("Adicionar Consultor!");
}

void limpar_ecra(void)
{
    
}