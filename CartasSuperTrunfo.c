#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void cadastroCartas(
    char estado1[], char codigoCidade1[], char cidade1[], unsigned long int *populacao1, float *areaKm1, int *pontosTuristicos1, float *pib1, float *desenPopulacional1, float *pibCapita1, float *superPoder1,
    char estado2[], char codigoCidade2[], char cidade2[], unsigned long int *populacao2, float *areaKm2, int *pontosTuristicos2, float *pib2, float *desenPopulacional2, float *pibCapita2, float *superPoder2) 
{
    printf("Nome estado1: ");
    fgets(estado1, 50, stdin);
    strtok(estado1, "\n"); 

    printf("Codigo cidade1: "); 
    fgets(codigoCidade1, 10, stdin);
    strtok(codigoCidade1, "\n");

    printf("Nome cidade1: ");
    fgets(cidade1, 50, stdin);
    strtok(cidade1, "\n");

    printf("Populacao1: ");
    scanf("%lu", populacao1);
    
    printf("Area1: ");
    scanf("%f", areaKm1);
    
    printf("Pontos turisticos1: ");
    scanf("%d", pontosTuristicos1);
    
    *desenPopulacional1 = (float)(*populacao1) / *areaKm1;

    printf("PIB1: ");    
    scanf("%f", pib1);

    *pibCapita1 = *pib1 / *populacao1;
    *superPoder1 = *populacao1 + *areaKm1 + *pib1 + *pontosTuristicos1 + *pibCapita1 + (1 / *desenPopulacional1);

    getchar();
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
    scanf("%lu", populacao2);
    
    printf("Area2: ");
    scanf("%f", areaKm2);
    
    printf("Pontos turisticos2: ");
    scanf("%d", pontosTuristicos2);
    
    printf("PIB2: ");    
    scanf("%f", pib2);

    *pibCapita2 = *pib2 / *populacao2;
    *desenPopulacional2 = (float)(*populacao2) / *areaKm2;
    *superPoder2 = *populacao2 + *areaKm2 + *pib2 + *pontosTuristicos2 + *pibCapita2 + (1 / *desenPopulacional2);
}

void compararCartas(unsigned long int pop1, unsigned long int pop2, float area1, float area2, int pontos1, int pontos2, float pib1, float pib2, float dens1, float dens2, float pibCapita1, float pibCapita2, float superPoder1, float superPoder2) {
    printf("\nComparacao de Cartas:\n");
    printf("Populacao: Carta %d venceu\n", pop1 > pop2 ? 1 : 2);
    printf("Area: Carta %d venceu\n", area1 > area2 ? 1 : 2);
    printf("PIB: Carta %d venceu\n", pib1 > pib2 ? 1 : 2);
    printf("Pontos Turisticos: Carta %d venceu\n", pontos1 > pontos2 ? 1 : 2);
    printf("Densidade Populacional: Carta %d venceu\n", dens1 < dens2 ? 1 : 2);
    printf("PIB per Capita: Carta %d venceu\n", pibCapita1 > pibCapita2 ? 1 : 2);
    printf("Super Poder: Carta %d venceu\n", superPoder1 > superPoder2 ? 1 : 2);
}

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");

    char estado1[50], estado2[50];
    char codigoCidade1[10], codigoCidade2[10];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float areaKm1, areaKm2, pib1, pib2, desenPopulacional1, desenPopulacional2;
    int pontosTuristicos1, pontosTuristicos2;
    float pibCapita1, pibCapita2, superPoder1, superPoder2;

    cadastroCartas(estado1, codigoCidade1, cidade1, &populacao1, &areaKm1, &pontosTuristicos1, &pib1, &desenPopulacional1, &pibCapita1, &superPoder1,
                   estado2, codigoCidade2, cidade2, &populacao2, &areaKm2, &pontosTuristicos2, &pib2, &desenPopulacional2, &pibCapita2, &superPoder2);
    
    compararCartas(populacao1, populacao2, areaKm1, areaKm2, pontosTuristicos1, pontosTuristicos2, pib1, pib2, desenPopulacional1, desenPopulacional2, pibCapita1, pibCapita2, superPoder1, superPoder2);
    
    return 0;
}
