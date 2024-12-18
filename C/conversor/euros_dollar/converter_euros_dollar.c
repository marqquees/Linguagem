#include <stdio.h>

float cambio_dollar(float valor_a_cambiar);
float cambio_euro(float valor_a_cambiar);

int main()
{
    float valor_a_cambiar;
    int op;

    printf("CAMBIO (EURO DOLLAR)\n");

    printf("\nValor a cambiar: ");
    scanf("%f", &valor_a_cambiar);

    printf("\n1. DOLLAR");
    printf("\n2. EURO\n");
    printf("\nOpcao: ");
    scanf("%d", &op);

    while (op < 1 || op > 2)
    {
        printf("\nDigite uma opcao valida (1 ou 2).");
        scanf("%d", &op);
    }
    switch (op)
    {
        case 1:
            printf("\n%.2f cambiado para dollar: %.2f", valor_a_cambiar, cambio_dollar(valor_a_cambiar));
            break;
        case 2:
            printf("\n%.2f cambiado para euro: %.2f", valor_a_cambiar, cambio_euro(valor_a_cambiar));
            break;
    }
    return 0;
}

float cambio_dollar(float valor_a_cambiar)
{
    return valor_a_cambiar * 0.95;
}

float cambio_euro(float valor_a_cambiar)
{
    return valor_a_cambiar * 1.05;
}