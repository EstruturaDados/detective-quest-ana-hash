#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a sala.\n");
        exit(1);
    }
    snprintf(novaSala->nome, sizeof(novaSala->nome), "%s", nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

void conectarSalas(Sala* origem, Sala* esquerda, Sala* direita) {
    origem->esquerda = esquerda;
    origem->direita = direita;
}

void explorarSalas(Sala* sala) {
    if (sala == NULL) {
        // saida
        printf("Voce chegou a uma sala inexistente. Saindo da exploracao.\n");
        return;
    }

    printf("Voce esta na sala: %s\n", sala->nome);
    char escolha;
    printf("Para onde deseja ir? (e: esquerda, d: direita, s: sair): ");
    scanf(" %c", &escolha);

    if (escolha == 'e') {
        explorarSalas(sala->esquerda);
    } else if (escolha == 'd') {
        explorarSalas(sala->direita);
    } else if (escolha == 's') {
        printf("Saindo da exploracao.\n");
    } else {
        printf("Opcao invalida. Tente novamente.\n");
        explorarSalas(sala);
    }
}

void inicio() {
    // Criar salas
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sotao");

    // Conectar salas
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, NULL, NULL);
    conectarSalas(cozinha, NULL, sotao);
    conectarSalas(sotao, NULL, NULL);

    // Iniciar exploração
    explorarSalas(hall);
}

int main() {

    inicio();

    return 0;
}