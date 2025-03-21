#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    float salario;
    int idade;
    char sexo;
    char estCivil;
    int qtdFilhos;

} Funcionario;

int ehIdoso(int idade)
{
    return idade >= 60;
}

int main()
{

    Funcionario funcionarios[3]; // mudar o valor dentro do []

    for (int i = 0; i < 10; i++)
    {
        printf("Funcionário %d: \n", i + 1);

        printf("Nome: "); 
        fgets(funcionarios[i].nome, 100, stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';

        printf("Digite o salário do funcionário (R$): ");
        scanf("%f", &funcionarios[i].salario);
        getchar();

        printf("Digite o sexo do funcionário (M/F): ");
        scanf("%c", &funcionarios[i].sexo);
        getchar();

        printf("Digite a idade do funcionário: ");
        scanf("%d", &funcionarios[i].idade);
        getchar();

        printf("Digite a quantidade de filhos: ");
        scanf("%d", &funcionarios[i].qtdFilhos);
        getchar();

        printf("Digite o estado civil (C/S): ");
        scanf("%c", &funcionarios[i].estCivil);
        printf(" \n");
    }

    // A média salarial dos pais idosos solteiros;

    // Exibindo as informações dos 10 funcionários

    float somaSalario = 0;
    int contIdoso = 0;

    printf("Informações dos Funcionários:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\nFuncionário %d: \n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Sexo: %c\n", funcionarios[i].sexo);
        printf("Salário: %.2f\n", funcionarios[i].salario);

        if (ehIdoso(funcionarios[i].idade))
        {
            somaSalario = +funcionarios[i].salario;
            contIdoso++;
        }
        else
        {
            printf("O Funcionario %s não é idoso(a).\n", funcionarios[i].nome);
        }
    }

    return 0;
}
