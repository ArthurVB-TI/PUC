/*
    Autor: Arthur Victor Alves
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* E00(bool execute) { if(execute) printf("\n[Metodo 00] Iniciado... Finalizado.\n"); return "Metodo 00"; }
char* E01(bool execute) { if(execute) printf("\n[Metodo 01] Iniciado... Finalizado.\n"); return "Metodo 01"; }
char* E02(bool execute) { if(execute) printf("\n[Metodo 02] Iniciado... Finalizado.\n"); return "Metodo 02"; }
char* E03(bool execute) { if(execute) printf("\n[Metodo 03] Iniciado... Finalizado.\n"); return "Metodo 03"; }
char* E04(bool execute) { if(execute) printf("\n[Metodo 04] Iniciado... Finalizado.\n"); return "Metodo 04"; }
char* E05(bool execute) { if(execute) printf("\n[Metodo 05] Iniciado... Finalizado.\n"); return "Metodo 05"; }
char* E06(bool execute) { if(execute) printf("\n[Metodo 06] Iniciado... Finalizado.\n"); return "Metodo 06"; }
char* E07(bool execute) { if(execute) printf("\n[Metodo 07] Iniciado... Finalizado.\n"); return "Metodo 07"; }
char* E08(bool execute) { if(execute) printf("\n[Metodo 08] Iniciado... Finalizado.\n"); return "Metodo 08"; }
char* E09(bool execute) { if(execute) printf("\n[Metodo 09] Iniciado... Finalizado.\n"); return "Metodo 09"; }

int main(int argc, char* argv[]) {
    printf("Autor: Arthur Victor Alves\n");
    printf("Tarefa Extra E2 - Chamada Sequencial de 10 Metodos\n\n");

    typedef char* (*Metodo)(bool);

    int qtde = 10;
    Metodo metodos[] = {E00, E01, E02, E03, E04, E05, E06, E07, E08, E09};
    
    printf("Executando metodos em sequencia (variacao crescente):\n");
    
    for (int i = 0; i < qtde; i++) {
        printf("\nChamando: %s", metodos[i](false));
        metodos[i](true);
        printf("TESTE (OK)\n");
    }

    printf("\n\nExecucao sequencial concluida.");
    printf("\nDigite ENTER para sair");
    getchar();
    return 0;
}