#include <stdio.h>

int main() {
    // 1. Declaração das variáveis (2,0 pontos)
    float salario_mensal, total_dividas, valor_emprestimo, parcela_mensal;
    float taxa_endividamento, percentual_parcela;
    int tempo_emprego_anos, numero_parcelas;
    const float LIMITE_PERCENTUAL_PARCELA = 0.30; // 30% do salário como limite máximo da parcela

    // 2. Entrada de Dados (2,0 pontos)
    printf("Bem-vindo ao Sistema de Liberacao de Emprestimos!\n");
    printf("Digite seu salario mensal (R$): ");
    scanf("%f", &salario_mensal);

    printf("Digite o total de suas dividas atuais (R$): ");
    scanf("%f", &total_dividas);

    printf("Digite o tempo de estabilidade no emprego (em anos): ");
    scanf("%d", &tempo_emprego_anos);

    printf("Digite o valor do emprestimo desejado (R$): ");
    scanf("%f", &valor_emprestimo);

    printf("Digite o numero de parcelas desejado: ");
    scanf("%d", &numero_parcelas);

    // 3. Cálculo da Taxa de Endividamento (2,0 pontos)
    taxa_endividamento = (total_dividas / salario_mensal) * 100;
    if (taxa_endividamento > 50) {
        printf("\nEmprestimo RECUSADO!\n");
        printf("Taxa de endividamento (%.2f%%) superior ao limite de 50%%\n", taxa_endividamento);
        return 0;
    }

    // 4. Limitação do Percentual do Empréstimo (2,0 pontos)
    parcela_mensal = valor_emprestimo / numero_parcelas;
    percentual_parcela = parcela_mensal / salario_mensal;

    if (percentual_parcela > LIMITE_PERCENTUAL_PARCELA) {
        printf("\nEmprestimo RECUSADO!\n");
        printf("Parcela mensal (R$ %.2f) excede 30%% do salario (R$ %.2f)\n",
               parcela_mensal, salario_mensal * LIMITE_PERCENTUAL_PARCELA);
        return 0;
    }

    // 5. Tempo de Estabilidade no Emprego (2,0 pontos)
    int max_parcelas;
    if (tempo_emprego_anos < 1) {
        max_parcelas = 12;
    } else if (tempo_emprego_anos <= 3) {
        max_parcelas = 24;
    } else {
        max_parcelas = 60;
    }

    if (numero_parcelas > max_parcelas) {
        printf("\nEmprestimo RECUSADO!\n");
        printf("Numero de parcelas (%d) excede o maximo permitido (%d) para seu tempo de emprego\n",
               numero_parcelas, max_parcelas);
        return 0;
    }

    // Se chegou até aqui, o empréstimo é aprovado
    printf("\nEmprestimo APROVADO!\n");
    printf("Taxa de endividamento: %.2f%%\n", taxa_endividamento);
    printf("Valor do emprestimo: R$ %.2f\n", valor_emprestimo);
    printf("Parcela mensal: R$ %.2f (%d parcelas)\n", parcela_mensal, numero_parcelas);

    return 0;
}
