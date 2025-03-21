#include <stdio.h>
#include <string.h>

struct funcionario
{
    char nome[100];
    float salario;
    int idade;
    char sexo;
    char estCivil;
    int qtdFilhos;
};


int pessoaIdosa(struct funcionario *pessoa)
{
    if (pessoa->idade >= 60)
    {
        return 1; // Verdadeiro: é idoso
    }
    else
    {
        return 0; // Falso: não é idoso
    }
}

int main()
{
    struct funcionario funcionarios[1];
    for (int i = 0; i < 10; i++)
    {
        printf("Funcionário %d:\nnome: ", i + 1);

        fgets(funcionarios[i].nome, 100, stdin);                          // Usando fgets para ler nomes com espaços
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0'; // Remover a nova linha gerada pelo fgets

        printf("Digite o salário do funcionário (R$): ");
        scanf("%f", &funcionarios[i].salario);

        printf("Digite o sexo do funcionário (M/F): ");
        getchar();
        scanf("%c", &funcionarios[i].sexo);

        printf("Digite a idade do funcionário: ");
        scanf("%d", &funcionarios[i].idade);

        printf("Digite a quantidade de filhos: ");
        scanf("%d", &funcionarios[i].qtdFilhos);

        printf("Digite o estado civil (C/S): ");
        scanf(" %c", &funcionarios[i].estCivil);
        printf("\n");
    }

    // pessoa idosa ja esta validada, porem
    // necessito que esta condicao  esponha
    // a média salarial dos pais idosos solteiros;

    for (int i = 0; i < 10; i++)
    {
        if (pessoaIdosa(&funcionarios[i]) && funcionarios[i].estCivil == 'S')
        {
            float media = funcionarios[i].salario;
            printf("A salarial dos pais idosos solteiros: ");
        }

        // Exibindo as informações dos 10 funcionários
        printf("Informações dos Funcionários:\n");
        for (int i = 0; i < 10; i++)
        {
            printf("\nFuncionário %d:\n", i + 1);
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Salário: %.2f\n", funcionarios[i].salario);
            printf("Sexo: %c\n", funcionarios[i].sexo);
            printf("Idade: %d\n", funcionarios[i].idade);
        }

        return 0;
    }
}