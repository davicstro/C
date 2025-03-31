#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>


#define NUM_FUNCIONARIOS 10

typedef struct
{
    float salario;
    int idade;
    int qtdFilhos;
    int estCivil; // 1 -> Casado, 2 -> Solteiro
    int sexo;    // 1 -> Feminino, 2 -> Masculino
} Funcionario;

int main()
{
    setlocale(LC_ALL, "en_US.utf8");

    Funcionario funcionarios[NUM_FUNCIONARIOS];

    int contPaisIdososSolt = 0;
    int qtPaisAdolNsAcima3k = 0;
    float somaSalarioPaisIdososSolt = 0.0;
    float maiorSalMulherSFilhos = 0.0;

    for (int i = 0; i < NUM_FUNCIONARIOS; i++)
    {
        //printf("%s", setlocale(LC_ALL,""));

        printf("Digite os dados do funcionario %d:\n", i + 1);

        do
        {
            printf("Salário: ");
            scanf("%f", &funcionarios[i].salario);
            if (funcionarios[i].salario < 0)
            {
                printf("Erro: O salário não pode ser negativo. Tente novamente.\n");
            }
        } while (funcionarios[i].salario < 0);

        do
        {
            printf("Idade: ");
            scanf("%d", &funcionarios[i].idade);
            if (funcionarios[i].idade <= 12 || funcionarios[i].idade > 130)
            {
                printf("Erro: A idade deve estar entre 18 e 130. Tente novamente.\n");
            }
        } while (funcionarios[i].idade <= 12 || funcionarios[i].idade > 130);

        do
        {
            printf("Sexo (F -> 1 , M -> 2): ");
            if (scanf("%d", &funcionarios[i].sexo) != 1)
            {
                while (getchar() != '\n')
                printf("Erro: O valor deve ser um número (1 ou 2). Tente novamente.\n");
            }
            else if (funcionarios[i].sexo != 1 && funcionarios[i].sexo != 2)
            {
                printf("Erro: O valor deve ser 1 (Feminino) ou 2 (Masculino). Tente novamente.\n");
            }
        } while (funcionarios[i].sexo != 1 && funcionarios[i].sexo != 2);

        do
        {
            printf("Estado civil (Casado -> 1, Solteiro -> 2): ");
            scanf("%d", &funcionarios[i].estCivil);
            if (funcionarios[i].estCivil != 1 && funcionarios[i].estCivil != 2)
            {
                printf("Erro: O valor deve ser 1 (Casado) ou 2 (Solteiro). Tente novamente.\n");
            }
        } while (funcionarios[i].estCivil != 1 && funcionarios[i].estCivil != 2);

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