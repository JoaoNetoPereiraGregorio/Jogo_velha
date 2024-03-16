#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char trocarJogador(char);
int verificarVitoria(char[3][3], char);
typedef struct _jogador
{
    char nome[40];
} jogador;

int main()
{

    jogador j[2];
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char jogador = 'X';
    int jogoEmAndamento = 1;
    int linha, coluna;

    for (int i = 0; i < 2; i++)
    {
        printf("Digite o nome do jogador %d:", i + 1);
        scanf("%s", &(j[i]));
    }

    while (jogoEmAndamento == 1)
    {
        printf("%s joga com o X.\n%s joga com a O.\n", j[0].nome, j[1].nome);
        imprimirTabuleiro(tabuleiro);

        printf("Jogador %c, digite a linha e a coluna onde deseja jogar: ", jogador);
        scanf("%d %d", &linha, &coluna);

        while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ')
        {
            printf("Jogada inválida. Tente novamente.\n");
            printf("Jogador %c, digite a linha e a coluna onde deseja jogar: ", jogador);
            scanf("%d %d", &linha, &coluna);
        }

        tabuleiro[linha][coluna] = jogador;

        int resultado = verificarVitoria(tabuleiro, jogador);

        if (resultado == 1)
        {
            imprimirTabuleiro(tabuleiro);
            if (jogador == 'X')
            {
                printf("Jogador %s venceu! Parabéns!\n", j[0].nome);
            }
            else
            {
                printf("Jogador %s venceu! Parabéns!\n", j[1].nome);
            }
            jogoEmAndamento = 0;
        }
        else if (resultado == 0)
        {
            imprimirTabuleiro(tabuleiro);
            printf("Empate! Parabens, %s e %s voces sao bons jogadores.", j[0].nome, j[1].nome);
            jogoEmAndamento = 0;
        }
        jogador = trocarJogador(jogador);
    }

    return 0;
}

void imprimirTabuleiro(char tabuleiro[3][3])
{
    printf("0   1   2\n");
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            printf("%c", tabuleiro[i][j]);
            if (j < 2)
            {
                printf(" | ");
            }
        }
        printf("  %d", i);
        printf("\n");
        if (i < 2)
        {
            printf("--+---+--\n");
        }
    }
    printf("\n");
}

char trocarJogador(char jogador)
{
    if (jogador == 'X')
    {
        return 'O';
    }
    else
    {
        return 'X';
    }
}

int verificarVitoria(char tabuleiro[3][3], char jogador)
{

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) // verifica linhas
        {
            return 1;
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) // verifica coluna
        {
            return 1;
        }
    }
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) // verifica uma diagonal
    {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) // verifica outra diagonal
    {
        return 1;
    }

    int empate = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O')
            {
                empate = 0;
                break;
            }
        }
    }
    if (empate == 1)
    {
        return 0; // Empate
    }

    return -1; // O jogo ainda está em andamento
}
