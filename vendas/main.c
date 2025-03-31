#include <stdio.h>
#include <stdlib.h>

#define TAMCli 3
#define TAMProd 3
#define TAMVendas 6

typedef struct
{
    int id;
    char nome[20];
    int quantidade;
    float valor;
} Produto;

typedef struct
{
    int id;
    char nome[20];
} Cliente;

typedef struct
{
    int idCliente;
    int idProduto;
    int quantProduto;
    float valorTotal;
} Venda;

void cadastrarCliente(Cliente c[])
{
    printf(">>> Cadastro de Cliente <<<\n");
    printf("\nAviso: Digite apenas o primeiro nome!\n\n");
    for (int i = 0; i < TAMCli; i++)
    {
        printf("Cliente %d: ", i + 1);
        scanf("%s", c[i].nome);
        c[i].id = i + 1;
    }
}

void cadastrarProduto(Produto p[])
{
    printf(">>> Cadastro de Produtos <<<\n");
    for (int i = 0; i < TAMProd; i++)
    {
        printf("\nProduto %d\nNome: ", i + 1);
        scanf("%s", p[i].nome);
        printf("Quantidade: ");
        scanf("%d", &p[i].quantidade);
        printf("Valor (R$): ");
        scanf("%f", &p[i].valor);
        p[i].id = i + 1;
    }
}

void consultarCliente(Cliente *c)
{
    printf(">>> Consulta Cliente <<<\n");
    for (int i = 0; i < TAMCli; i++)
    {
        printf("\nId%d Cliente: %s", c[i].id, c[i].nome);
    }
    printf("\n\n");
}

void consultarProduto(Produto p[], int exibirConsulta)
{

    if (exibirConsulta == 1)
    {
        printf(">>> Consulta de Produtos <<<");
    }

    printf("\n----------------------------------");
    for (int i = 0; i < TAMProd; i++)
    {
        printf("\nId%d", p[i].id);
        printf("\n\tNome do Produto: %s", p[i].nome);
        printf("\n\tQuantidade: %d", p[i].quantidade);
        printf("\n\tValor: R$ %.2f", p[i].valor);
        printf("\n----------------------------------");
    }
    printf("\n\n");
}

void realizarVenda(Cliente clientes[], Produto produtos[], Venda v[], int *numVendas)
{
    // Esta função tem como objetivo gerenciar o processo completo de uma venda.
    // O usuário deve fornecer o ID do cliente, o ID do produto e a quantidade desejada.
    // A função deve verificar a validade desses dados (se o cliente e o produto existem no sistema,
    // se há estoque disponível) e, caso a venda seja válida, registrar a transação,
    // atualizar o estoque e calcular o valor total da venda.
    int idCliente, idProduto, quantidade, exibirConsulta = 0;

    // Verificar se há espaço para mais vendas
    if (*numVendas >= TAMVendas)
    {
        printf("Limite de vendas atingido!\n");
        return;
    }

    // Mostrar clientes disponíveis
    printf("\nClientes disponiveis:\n");
    consultarCliente(clientes);

    // Selecionar cliente
    printf("\nDigite o ID do cliente: ");
    scanf("%d", &idCliente);

    // Verificar se cliente existe
    int clienteEncontrado = 0;
    for (int i = 0; i < TAMCli; i++)
    {
        if (clientes[i].id == idCliente)
        {
            clienteEncontrado = 1;
            break;
        }
    }
    if (!clienteEncontrado)
    {
        printf("Cliente nao encontrado!\n");
        return;
    }

    // Mostrar produtos disponíveis
    printf("\nProdutos disponiveis:\n");
    consultarProduto(produtos, exibirConsulta);

    // Selecionar produto
    printf("\nDigite o ID do produto: ");
    scanf("%d", &idProduto);

    // Verificar se produto existe e tem estoque
    int produtoIndex = -1;
    for (int i = 0; i < TAMProd; i++)
    {
        if (produtos[i].id == idProduto)
        {
            produtoIndex = i;
            break;
        }
    }
    if (produtoIndex == -1)
    {
        printf("\nProduto nao encontrado!\n");
        return;
    }

    // Selecionar quantidade
    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade invalida!\n");
        return;
    }

    if (produtos[produtoIndex].quantidade < quantidade)
    {
        printf("\nEstoque insuficiente! Disponivel: %d\n", produtos[produtoIndex].quantidade);
        return;
    }

    // Atualizar estoque => subtraindo a quantidade
    produtos[produtoIndex].quantidade -= quantidade;

    // Registrar venda
    v[*numVendas].idCliente = idCliente;
    v[*numVendas].idProduto = idProduto;
    v[*numVendas].quantProduto = quantidade;
    v[*numVendas].valorTotal = quantidade * produtos[produtoIndex].valor;

    (*numVendas)++;

    printf("\nVenda realizada com sucesso!\n");
}

void consultarVendas(Venda v[])
{
    // Esta função será responsável por exibir todas as vendas realizadas até o momento. Para cada venda,
    // devem ser apresentados o ID do cliente, o ID do produto, a quantidade comprada e o valor total da venda.
    // Esta funcionalidade será essencial para acompanhamento e controle das transações realizadas no sistema.

    for (int i = 0; i < TAMVendas; i++)
    {

        printf("\nVenda %d:", i + 1);
        printf("\n\tID do Cliente: %d", v[i].idCliente);
        printf("\n\tID do Produto: %d", v[i].idProduto);
        printf("\n\tQuantidade do Produto: %d", v[i].quantProduto);
        printf("\n\tValor Total: R$ %.2f", v[i].valorTotal);
    }
    printf("\n\n");
}
int main()
{
    int opcao, sair = 0; // sair inicialmente falso
    int numVendas = 0;   // Initialize the number of sales outside the loop
    int exibirConsulta = 0;
    Cliente clientes[5];
    Produto produtos[5];
    Venda vendas[5];

    system("cls");
    do
    {
        printf(">>> Sistema de Vendas <<<\n");
        printf("\n1 - Cadastrar Clientes");
        printf("\n2 - Cadastrar Produtos");
        printf("\n3 - Consultar Clientes");
        printf("\n4 - Consultar Produtos");
        printf("\n5 - Realizar Vendas");
        printf("\n6 - Consultar Vendas");
        printf("\n7 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("\n%d", &opcao);
        system("cls");

        if (opcao == 1)
        {
            cadastrarCliente(clientes);
            system("cls");
        }
        else if (opcao == 2)
        {
            cadastrarProduto(produtos);
            system("cls");
        }
        else if (opcao == 3)
        {
            consultarCliente(clientes);
        }
        else if (opcao == 4)
        {
            system("cls");
            consultarProduto(produtos, exibirConsulta = 1);
        }
        else if (opcao == 5)
        {
            system("cls");
            realizarVenda(clientes, produtos, vendas, &numVendas);
        }
        else if (opcao == 6)
        {
            consultarVendas(vendas); 
        }
        else if (opcao == 7)
        {
            sair = 1;
        }
        else
        {
            printf("\n\nOpcao Invalida!");
        }

    } while (sair != 1);

    return 0;
}