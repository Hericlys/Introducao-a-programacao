#include <stdio.h>
#include <string.h>
#include <Windows.h>


typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;


void CadastrarCarta(Carta *c) {
    printf("Digite o estado (uma letra): ");
    scanf(" %c", &c->estado); // espaço antes de %c evita problema de buffer

    printf("Digite o codigo (3 letras/numeros): ");
    scanf("%3s", c->codigo); // limita a 3 caracteres + '\0'

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->nomeCidade); // lê até o Enter (inclusive espaços)

    printf("Digite a populacao: ");
    scanf("%d", &c->populacao);

    printf("Digite a area (km2): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &c->pib);

    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%d", &c->pontosTuristicos);

    printf("\n--- Carta cadastrada com sucesso! ---\n\n");
}


float CalcularDensidadePopulacional(Carta *c) {
    // evitar divisão por Zero
    if (c -> populacao == 0 || c -> area == 0) {
        return 0.0;
    } else {
        // calculando a densidade populacional
        float resultado = (float)c->populacao / c -> area;
        return resultado;
    }
}


float CalcularPIBPerCapita(Carta *c) {
    // evitar divisão por Zero
    if (c -> pib == 0 || c -> populacao == 0) {
        return 0.0;
    } else {
        // calculando o PIB per capita
        float resultado = (c -> pib * 1e9) / c -> populacao;
        return resultado;
    }
}


void ExibirCarta(Carta *c) {
    printf("Estado: %c\n", c->estado);
    printf("Código: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->nomeCidade);
    printf("População: %d\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2f bilhões de reais\n", c->pib);
    printf("Número de Pontos Turísticos: %d\n", c->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", CalcularDensidadePopulacional(c));
    printf("PIB per Capita: R$ %.2f \n\n", CalcularPIBPerCapita(c));
}


int main() {
    // configuração do terminal em UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Execução do fluxo do sistema
    int n = 2;

    // printf("Quantas cartas deseja cadastrar? ");
    // scanf("%d", &n);

    Carta cartas[n];

    // Cadastro de cartas
    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastro da carta %d ---\n", i + 1);
        CadastrarCarta(&cartas[i]);
    }

    // Exibição das cartas
    printf("\n--- Exibição das cartas ---\n");
    for (int i = 0; i < n; i++) {
        ExibirCarta(&cartas[i]);
        printf("\n--- ------ ------ ------ ---\n");
    }

    return 0;
}