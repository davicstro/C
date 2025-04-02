#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100
#define MAX_VENDAS 100

typedef struct {
    int id;
    char nome[50];
} Cliente;

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float valor;
} Produto;

typedef struct {
    int idVenda;
    int idCliente;
    int idProduto;
    int quantidade;
    float valorTotal;
} Venda;

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Venda vendas[MAX_VENDAS];

int totalClientes = 0;
int totalProdutos = 0;
int totalVendas = 0;

void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }
    printf("Digite o nome do cliente (max. 49 caracteres): ");
    scanf("%49s", clientes[totalClientes].nome);
    clientes[totalClientes].id = totalClientes + 1;
    printf("Cliente cadastrado com sucesso! ID: %d\n", clientes[totalClientes].id);
    totalClientes++;
}

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }
    printf("Digite o nome do produto (max. 49 caracteres): ");
    scanf("%49s", produtos[totalProdutos].nome);

    do {
        printf("Digite a quantidade (positiva): ");
        scanf("%d", &produtos[totalProdutos].quantidade);
    } while (produtos[totalProdutos].quantidade < 0);

    do {
        printf("Digite o valor (positivo): ");
        scanf("%f", &produtos[totalProdutos].valor);
    } while (produtos[totalProdutos].valor < 0);

    produtos[totalProdutos].id = totalProdutos + 1;
    printf("Produto cadastrado com sucesso! ID: %d\n", produtos[totalProdutos].id);
    totalProdutos++;
}

void consultarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("Clientes cadastrados:\n");
    int i;
    for (i = 0; i < totalClientes; i++) {
        printf("ID: %d, Nome: %s\n", clientes[i].id, clientes[i].nome);
    }
}

void consultarProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("Produtos cadastrados:\n");
    int i;
    for (i = 0; i < totalProdutos; i++) {
        printf("ID: %d, Nome: %s, Quantidade: %d, Valor: %.2f\n",
               produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].valor);
    }
}

void realizarVenda() {
    if (totalVendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido.\n");
        return;
    }

    int idCliente, idProduto, quantidade;

    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);
    if (idCliente < 1 || idCliente > totalClientes) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    printf("Digite o ID do produto: ");
    scanf("%d", &idProduto);
    if (idProduto < 1 || idProduto > totalProdutos) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);
    if (quantidade <= 0 || quantidade > produtos[idProduto - 1].quantidade) {
        printf("Quantidade invalida ou insuficiente em estoque.\n");
        return;
    }

    vendas[totalVendas].idVenda = totalVendas + 1;
    vendas[totalVendas].idCliente = idCliente;
    vendas[totalVendas].idProduto = idProduto;
    vendas[totalVendas].quantidade = quantidade;
    vendas[totalVendas].valorTotal = quantidade * produtos[idProduto - 1].valor;

    produtos[idProduto - 1].quantidade -= quantidade;

    printf("Venda realizada com sucesso! ID da Venda: %d\n", vendas[totalVendas].idVenda);
    totalVendas++;
}

void consultarVendas() {
    if (totalVendas == 0) {
        printf("Nenhuma venda realizada.\n");
        return;
    }
    printf("Vendas realizadas:\n");
    int i;
    for (i = 0; i < totalVendas; i++) {
        printf("ID Venda: %d, Cliente: %s, Produto: %s, Quantidade: %d, Valor Total: %.2f\n",
               vendas[i].idVenda,
               clientes[vendas[i].idCliente - 1].nome,
               produtos[vendas[i].idProduto - 1].nome,
               vendas[i].quantidade,
               vendas[i].valorTotal);
    }
}

void exibirMenu() {
    printf("\n");
    printf("+-------------------------------+\n");
    printf("|             MENU              |\n");
    printf("+-------------------------------+\n");
    printf("| 1 - Cadastrar Cliente         |\n");
    printf("| 2 - Cadastrar Produto         |\n");
    printf("| 3 - Consultar Clientes        |\n");
    printf("| 4 - Consultar Produtos        |\n");
    printf("| 5 - Realizar Venda            |\n");
    printf("| 6 - Consultar Vendas          |\n");
    printf("| 7 - Sair                      |\n");
    printf("+-------------------------------+\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                consultarClientes();
                break;
            case 4:
                consultarProdutos();
                break;
            case 5:
                realizarVenda();
                break;
            case 6:
                consultarVendas();
                break;
            case 7:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);
    return 0;
}