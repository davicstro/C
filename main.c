#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("\n");
    printf(" _   _  _   _ ______   ___   _   _  _   __ \n");
    printf("| \\ | || | | || ___ \\ / _ \\ | \\ | || | / / \n");
    printf("|  \\| || | | || |_/ // /_\\ \\|  \\| || |/ /  \n");
    printf("| . ` || | | || ___ \\|  _  || . ` ||    \\  \n");
    printf("| |\\  || |_| || |_/ /| | | || |\\  || |\\  \\ \n");
    printf("\\_| \\_/ \\___/ \\____/ \\_| |_/\\_| \\_/\\_| \\_/ \n");
    printf("\n");

    float salarioMensal, dividas, taxaEndividamento, limiteParcela, valorEmprestimo, parcela;
    int tempoEmprego, numParcelas, maxParcela;
    int opcao;

    printf("\n=== Sistema de Liberacao de Emprestimos ===\n");

    do
    {

        printf("1. Iniciar\n2. Sair\nEscolha: ");
        if (opcao == 1)
        {
            system("clear");
            printf("Digite seu salario mensal: ");
            scanf("%f", &salarioMensal);

            if (salarioMensal <= 0)
            {
                printf("Erro! O salario deve ser maior que zero.\n");
                return 1;
            }

            printf("Digite o total de suas dividas: ");
            scanf("%f", &dividas);

            printf("Digite seu tempo de emprego (anos): ");
            scanf("%d", &tempoEmprego);

            // Cálculo da taxa de endividamento
            taxaEndividamento = dividas / salarioMensal;

            // Definição do limite de parcelas baseado no tempo de emprego
            if (tempoEmprego < 1)
                maxParcela = 12;
            else if (tempoEmprego <= 3)
                maxParcela = 24;
            else
                maxParcela = 60;

            // Verificação da taxa de endividamento
            if (taxaEndividamento > 0.5)
            {
                printf("\nEmprestimo Recusado!\nSua taxa de endividamento e: %.2f%% (esta maior que o limite de 50%%)\n", taxaEndividamento * 100);
                return 0;
            }

            // Definição do limite da parcela (30% do salário)
            limiteParcela = salarioMensal * 0.30;

            // Entrada do empréstimo e número de parcelas
            printf("Digite o valor do emprestimo desejado: ");
            scanf("%f", &valorEmprestimo);

            if (valorEmprestimo <= 0)
            {
                printf("Erro! O valor do emprestimo deve ser maior que zero.\n");
                return 1;
            }

            printf("Digite o numero de parcelas desejadas: ");
            scanf("%d", &numParcelas);

            if (numParcelas <= 0)
            {
                printf("Erro! O numero de parcelas deve ser maior que zero.\n");
                return 1;
            }

            // Cálculo do valor da parcela
            parcela = valorEmprestimo / numParcelas;

            // Verificações finais
            if (numParcelas > maxParcela)
            {
                printf("\nErro! O numero maximo de parcelas permitido e: %d.\n", maxParcela);
                return 0;
            }

            if (parcela > limiteParcela)
            {
                printf("\nErro! O valor da parcela (%.2f) excede o limite permitido (%.2f).\n", parcela, limiteParcela);
                return 0;
            }

            // Aprovação do empréstimo
            do
            {
                system("cls");
                printf("\nEmprestimo aprovado!\n");
                printf("Valor: %.2f\nParcelas: %d\nValor da parcela: %.2f\n", valorEmprestimo, numParcelas, parcela);
                printf("\nDeseja realizar outro emprestimo?\n1. Sim\n2. Nao\nEscolha: ");
                scanf("%d", &opcao);
            } while (opcao != 1);
        }
        scanf("%d", &opcao);
    } while (opcao != 2);

    // Entrada de dados

    return 0;
}
