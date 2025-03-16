#include <stdio.h>    // Biblioteca necessária para usar funções de entrada e saída (ex: printf, scanf)
#include <locale.h>    // Biblioteca para definir o idioma e região (nesse caso, português)
#include <stdlib.h>    // Biblioteca padrão para funções gerais (como alocar memória)
#include <string.h>    // Biblioteca para manipulação de strings (ex: fgets, strtok)

// Função para cadastrar os dados das duas cidades (cartas)
void cadastroCartas(
    char estado1[], char codigoCidade1[], char cidade1[], unsigned long int *populacao1, float *areaKm1, int *pontosTuristicos1, float *pib1, float *desenPopulacional1, float *pibCapita1, float *superPoder1,
    char estado2[], char codigoCidade2[], char cidade2[], unsigned long int *populacao2, float *areaKm2, int *pontosTuristicos2, float *pib2, float *desenPopulacional2, float *pibCapita2, float *superPoder2) 
{
    // Entrada de dados para a cidade 1
    printf("Nome estado1: ");
    fgets(estado1, 50, stdin);  // Recebe o nome do estado da cidade 1
    strtok(estado1, "\n");  // Remove a quebra de linha do final da string

    printf("Codigo cidade1: "); 
    fgets(codigoCidade1, 10, stdin);  // Recebe o código da cidade 1
    strtok(codigoCidade1, "\n");  // Remove a quebra de linha

    printf("Nome cidade1: ");
    fgets(cidade1, 50, stdin);  // Recebe o nome da cidade 1
    strtok(cidade1, "\n");  // Remove a quebra de linha

    printf("Populacao1: ");
    scanf("%lu", populacao1);  // Recebe a população da cidade 1
    
    printf("Area1: ");
    scanf("%f", areaKm1);  // Recebe a área da cidade 1
    
    printf("Pontos turisticos1: ");
    scanf("%d", pontosTuristicos1);  // Recebe o número de pontos turísticos da cidade 1
    
    *desenPopulacional1 = (float)(*populacao1) / *areaKm1;  // Calcula a densidade populacional (população/área)

    printf("PIB1: ");    
    scanf("%f", pib1);  // Recebe o PIB da cidade 1

    *pibCapita1 = *pib1 / *populacao1;  // Calcula o PIB per capita (PIB/população)
    // Calcula o super poder, que é uma soma dos atributos da cidade
    *superPoder1 = *populacao1 + *areaKm1 + *pib1 + *pontosTuristicos1 + *pibCapita1 + (1 / *desenPopulacional1);

    getchar();  // Limpa o buffer de entrada (para evitar problemas com fgets depois)
    
    // Entrada de dados para a cidade 2 (seguindo o mesmo padrão de cadastro da cidade 1)
    printf("Nome estado2: ");
    fgets(estado2, 50, stdin);
    strtok(estado2, "\n");

    printf("Codigo cidade2: "); 
    fgets(codigoCidade2, 10, stdin);
    strtok(codigoCidade2, "\n");

    printf("Nome cidade2: ");
    fgets(cidade2, 50, stdin);
    strtok(cidade2, "\n");

    printf("Populacao2: ");
    scanf("%lu", populacao2);  // Recebe a população da cidade 2
    
    printf("Area2: ");
    scanf("%f", areaKm2);  // Recebe a área da cidade 2
    
    printf("Pontos turisticos2: ");
    scanf("%d", pontosTuristicos2);  // Recebe o número de pontos turísticos da cidade 2
    
    printf("PIB2: ");    
    scanf("%f", pib2);  // Recebe o PIB da cidade 2

    *pibCapita2 = *pib2 / *populacao2;  // Calcula o PIB per capita da cidade 2
    *desenPopulacional2 = (float)(*populacao2) / *areaKm2;  // Calcula a densidade populacional da cidade 2
    // Calcula o super poder da cidade 2 da mesma forma que o de cidade 1
    *superPoder2 = *populacao2 + *areaKm2 + *pib2 + *pontosTuristicos2 + *pibCapita2 + (1 / *desenPopulacional2);
}

// Função para comparar os atributos das duas cidades (cartas)
void compararCartas(int escolha, unsigned long int pop1, unsigned long int pop2, float area1, float area2, int pontos1, int pontos2, float pib1, float pib2, float dens1, float dens2, float pibCapita1, float pibCapita2, float superPoder1, float superPoder2) {
    printf("\nComparacao de Cartas:\n");
    switch (escolha) {
        case 1:
            // Comparação de população
            if (pop1 > pop2) {
                printf("Populacao: Carta 1 venceu\n");
            } else if (pop1 < pop2) {
                printf("Populacao: Carta 2 venceu\n");
            } else {
                printf("Populacao: Empate\n");
            }
            break;
        case 2:
            // Comparação de área
            if (area1 > area2) {
                printf("Area: Carta 1 venceu\n");
            } else if (area1 < area2) {
                printf("Area: Carta 2 venceu\n");
            } else {
                printf("Area: Empate\n");
            }
            break;
        case 3:
            // Comparação de PIB
            if (pib1 > pib2) {
                printf("PIB: Carta 1 venceu\n");
            } else if (pib1 < pib2) {
                printf("PIB: Carta 2 venceu\n");
            } else {
                printf("PIB: Empate\n");
            }
            break;
        case 4:
            // Comparação de pontos turísticos
            if (pontos1 > pontos2) {
                printf("Pontos Turisticos: Carta 1 venceu\n");
            } else if (pontos1 < pontos2) {
                printf("Pontos Turisticos: Carta 2 venceu\n");
            } else {
                printf("Pontos Turisticos: Empate\n");
            }
            break;
        case 5:
            // Comparação de densidade populacional
            if (dens1 < dens2) {  // A densidade menor é considerada melhor
                printf("Densidade Populacional: Carta 1 venceu\n");
            } else if (dens1 > dens2) {
                printf("Densidade Populacional: Carta 2 venceu\n");
            } else {
                printf("Densidade Populacional: Empate\n");
            }
            break;
        case 6:
            // Comparação de PIB per capita
            if (pibCapita1 > pibCapita2) {
                printf("PIB per Capita: Carta 1 venceu\n");
            } else if (pibCapita1 < pibCapita2) {
                printf("PIB per Capita: Carta 2 venceu\n");
            } else {
                printf("PIB per Capita: Empate\n");
            }
            break;
        case 7:
            // Comparação de super poder
            if (superPoder1 > superPoder2) {
                printf("Super Poder: Carta 1 venceu\n");
            } else if (superPoder1 < superPoder2) {
                printf("Super Poder: Carta 2 venceu\n");
            } else {
                printf("Super Poder: Empate\n");
            }
            break;
        default:
            // Caso o usuário escolha uma opção inválida
            printf("Opcao invalida.\n");
    }
}

// Função principal onde tudo acontece
int main() {
    setlocale(LC_ALL, "pt_BR.utf8");  // Define a linguagem para português

    // Declaração de variáveis para armazenar os dados das duas cidades
    char estado1[50], estado2[50];
    char codigoCidade1[10], codigoCidade2[10];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float areaKm1, areaKm2, pib1, pib2, desenPopulacional1, desenPopulacional2;
    int pontosTuristicos1, pontosTuristicos2;
    float pibCapita1, pibCapita2, superPoder1, superPoder2;

    // Chama a função para cadastrar as cartas (dados das cidades)
    cadastroCartas(estado1, codigoCidade1, cidade1, &populacao1, &areaKm1, &pontosTuristicos1, &pib1, &desenPopulacional1, &pibCapita1, &superPoder1,
                   estado2, codigoCidade2, cidade2, &populacao2, &areaKm2, &pontosTuristicos2, &pib2, &desenPopulacional2, &pibCapita2, &superPoder2);
    
    // Escolha do atributo para comparar
    int escolha;
    printf("Escolha o atributo para comparacao:\n1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade Populacional\n6. PIB per Capita\n7. Super Poder\n");
    scanf("%d", &escolha);

    // Chama a função para comparar as cartas com base na escolha do usuário
    compararCartas(escolha, populacao1, populacao2, areaKm1, areaKm2, pontosTuristicos1, pontosTuristicos2, pib1, pib2, desenPopulacional1, desenPopulacional2, pibCapita1, pibCapita2, superPoder1, superPoder2);
    
    return 0;  // Finaliza o programa
}
