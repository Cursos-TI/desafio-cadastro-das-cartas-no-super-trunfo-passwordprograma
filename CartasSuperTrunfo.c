#include <stdio.h>

// Definindo as propriedades que cada cidade vai ter
struct Cidade {
    char nome[50];       // Nome da cidade
    int populacao;       // População da cidade
    float area;          // Área da cidade
    float pib;           // PIB da cidade
    int pontos_turisticos; // Número de pontos turísticos
};

// Função para cadastrar uma cidade
void cadastrarCidade(struct Cidade* cidade) {
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade->nome);  // Lê o nome com espaços

    printf("Digite a população da cidade: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB da cidade (em milhões de R$): ");
    scanf("%f", &cidade->pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &cidade->pontos_turisticos);

    printf("Cidade cadastrada com sucesso!\n\n");
}

// Função para exibir os dados de uma cidade
void exibirCidade(struct Cidade cidade, char estado, int numero) {
    printf("\nCidade %s (%c%02d):\n", cidade.nome, estado, numero);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: R$ %.2f milhões\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("--------------------------\n");
}

int main() {
    struct Cidade cidades[8][4];  // Matriz de cidades: 8 estados e 4 cidades por estado
    int opcao;
    char estado;
    int cidade_numero;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar uma cidade\n");
        printf("2 - Exibir os dados de uma cidade\n");
        printf("3 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite a letra do estado (A-H): ");
            scanf(" %c", &estado);  // Lê o estado (A-H)
            estado = toupper(estado);  // Garantir que o estado esteja maiúsculo

            if (estado < 'A' || estado > 'H') {
                printf("Estado inválido. Tente novamente.\n");
                continue;
            }

            printf("Digite o número da cidade (1-4): ");
            scanf("%d", &cidade_numero);

            if (cidade_numero < 1 || cidade_numero > 4) {
                printf("Número de cidade inválido. Tente novamente.\n");
                continue;
            }

            // Cadastrar a cidade no estado e número escolhido
            int estado_index = estado - 'A';  // Convertendo a letra do estado para índice (A=0, B=1, ...)
            int cidade_index = cidade_numero - 1;  // Convertendo o número da cidade para índice (1=0, 4=3, ...)

            cadastrarCidade(&cidades[estado_index][cidade_index]);
        } else if (opcao == 2) {
            printf("Digite a letra do estado (A-H): ");
            scanf(" %c", &estado);  // Lê o estado (A-H)
            estado = toupper(estado);  // Garantir que o estado esteja maiúsculo

            if (estado < 'A' || estado > 'H') {
                printf("Estado inválido. Tente novamente.\n");
                continue;
            }

            printf("Digite o número da cidade (1-4): ");
            scanf("%d", &cidade_numero);

            if (cidade_numero < 1 || cidade_numero > 4) {
                printf("Número de cidade inválido. Tente novamente.\n");
                continue;
            }

            // Exibir os dados da cidade
            int estado_index = estado - 'A';  // Convertendo a letra do estado para índice (A=0, B=1, ...)
            int cidade_index = cidade_numero - 1;  // Convertendo o número da cidade para índice (1=0, 4=3, ...)

            exibirCidade(cidades[estado_index][cidade_index], estado, cidade_numero);
        } else if (opcao == 3) {
            printf("Saindo do sistema...\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}







 

