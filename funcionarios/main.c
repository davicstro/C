#include <stdio.h>

#define NUM_FUNCIONARIOS 3

// Estrutura para armazenar as informações de um funcionário
typedef struct
{
    float salario;
    int idade;
    int sexo;     // 1 - F, 2 - M
    int estCivil; // 1 - Casado, 2 - Solteiro
    int qtdFilhos;
} Funcionario;

int main()
{
    // Declaração do vetor de structs para armazenar os dados dos 10 funcionários
    Funcionario funcionarios[NUM_FUNCIONARIOS];

    // Variáveis para os cálculos
    int contPaisIdososSolt = 0;
    int qtPaisAdolNsAcima3k = 0;
    float somaSalarioPaisIdososSolt = 0.0;
    float maiorSalMulherSFilhos = 0.0;

    // Entrada de dados
    for (int i = 0; i < NUM_FUNCIONARIOS; i++)
    {
        printf("Digite os dados do funcionario %d:\n", i + 1);

        // Validação do salário (não pode ser negativo)
        do
        {
            printf("Salário: ");
            scanf("%f", &funcionarios[i].salario);
            if (funcionarios[i].salario < 0)
            {
                printf("Erro: O salário não pode ser negativo. Tente novamente.\n");
            }
        } while (funcionarios[i].salario < 0);

        // Validação da idade (deve estar entre 18 e 130)
        do
        {
            printf("Idade: ");
            scanf("%d", &funcionarios[i].idade);
            if (funcionarios[i].idade <= 12 || funcionarios[i].idade > 130)
            {
                printf("Erro: A idade deve estar entre 18 e 130. Tente novamente.\n");
            }
        } while (funcionarios[i].idade <= 12 || funcionarios[i].idade > 130);

        // Validação do sexo (1 - F, 2 - M)
        do
        {
            printf("Sexo (F -> 1 , M -> 2): ");
            if (scanf("%d", &funcionarios[i].sexo) != 1)
            {
                // Se o scanf não conseguir ler um número, limpar o buffer
                while (getchar() != '\n')
                    ; // Limpar o buffer do teclado
                printf("Erro: O valor deve ser um número (1 ou 2). Tente novamente.\n");
            }
            else if (funcionarios[i].sexo != 1 && funcionarios[i].sexo != 2)
            {
                printf("Erro: O valor deve ser 1 (Feminino) ou 2 (Masculino). Tente novamente.\n");
            }
        } while (funcionarios[i].sexo != 1 && funcionarios[i].sexo != 2);

        // Validação do estado civil (1 - Casado, 2 - Solteiro)
        do
        {
            printf("Estado civil (Casado -> 1, Solteiro -> 2): ");
            scanf("%d", &funcionarios[i].estCivil);
            if (funcionarios[i].estCivil != 1 && funcionarios[i].estCivil != 2)
            {
                printf("Erro: O valor deve ser 1 (Casado) ou 2 (Solteiro). Tente novamente.\n");
            }
        } while (funcionarios[i].estCivil != 1 && funcionarios[i].estCivil != 2);

        // Validação da quantidade de filhos (não pode ser negativa)
        do
        {
            printf("Quantidade de filhos: ");
            scanf("%d", &funcionarios[i].qtdFilhos);
            if (funcionarios[i].qtdFilhos < 0)
            {
                printf("Erro: A quantidade de filhos não pode ser negativa. Tente novamente.\n");
            }
        } while (funcionarios[i].qtdFilhos < 0);

        printf("\n");
    }

    // a) Média salarial dos pais idosos solteiros
    for (int i = 0; i < NUM_FUNCIONARIOS; i++)
    {
        if (funcionarios[i].idade >= 60 && funcionarios[i].estCivil == 2 && funcionarios[i].qtdFilhos > 0)
        {
            somaSalarioPaisIdososSolt += funcionarios[i].salario;
            contPaisIdososSolt++;
        }
    }

    if (contPaisIdososSolt > 0)
    {
        printf("A média salarial dos pais idosos solteiros é: %.2f\n", somaSalarioPaisIdososSolt / contPaisIdososSolt);
    }
    else
    {
        printf("Não há pais idosos solteiros.\n");
    }

    // b) Mostrar o salário da mulher que ganha o maior salário e que não tem filhos
    for (int i = 0; i < NUM_FUNCIONARIOS; i++)
    {
        if (funcionarios[i].sexo == 1 && funcionarios[i].qtdFilhos == 0)
        {
            if (funcionarios[i].salario > maiorSalMulherSFilhos)
            {
                maiorSalMulherSFilhos = funcionarios[i].salario;
            }
        }
    }

    if (maiorSalMulherSFilhos > 0)
    {
        printf("O maior salário da mulher que não tem filhos é: %.2f\n", maiorSalMulherSFilhos);
    }
    else
    {
        printf("Não há mulheres que não têm filhos.\n");
    }

    // c) Quantidade dos pais adolescentes (idade < 18) que não são solteiros que ganham acima de R$ 3000
    for (int i = 0; i < NUM_FUNCIONARIOS; i++)
    {

        if (funcionarios[i].idade <= 18 && funcionarios[i].estCivil == 1 && funcionarios[i].salario >= 3000)
        {
            qtPaisAdolNsAcima3k++;
        }
    }
    printf("A quantidade de pais adolescentes não solteiros que ganham acima de R$ 3000 é: %d\n", qtPaisAdolNsAcima3k);

    return 0;
}