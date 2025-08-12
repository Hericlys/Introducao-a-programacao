#include <stdio.h>
#include <windows.h>

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

bool verificarAprovacao(float media){
    return media >= 7.0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    float nota1, nota2, nota3, media;

    // solicitar notas ao usuário
    printf("Digite a primeira nota: \n");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: \n");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: \n");
    scanf("%f", &nota3);

    // calcular a média
    media = calcularMedia(nota1, nota2, nota3);
    printf("A média é: %.2f\n", media);

    // verificar se o aluno foi aprovado
    if (verificarAprovacao(media)) {
        printf("Aluno aprovado!\n");
    } else {
        printf("Aluno reprovado!\n");
    }

    printf("finalizando o programa...\n");
    Sleep(2000); // aguarda 2 segundos antes de fechar

    return 0;
}