/*
    Autor: Arthur Victor Alves
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* E00(bool execute) { if(execute) printf("\nExecutando Exemplo 00\n"); return "Exemplo0000 - v0.0"; }
char* E01(bool execute) { if(execute) printf("\nExecutando Exemplo 01\n"); return "Exemplo0001 - v0.1"; }
char* E02(bool execute) { if(execute) printf("\nExecutando Exemplo 02\n"); return "Exemplo0002 - v0.2"; }
char* E03(bool execute) { if(execute) printf("\nExecutando Exemplo 03\n"); return "Exemplo0003 - v0.3"; }
char* E04(bool execute) { if(execute) printf("\nExecutando Exemplo 04\n"); return "Exemplo0004 - v0.4"; }
char* E05(bool execute) { if(execute) printf("\nExecutando Exemplo 05\n"); return "Exemplo0005 - v0.5"; }
char* E06(bool execute) { if(execute) printf("\nExecutando Exemplo 06\n"); return "Exemplo0006 - v0.6"; }
char* E07(bool execute) { if(execute) printf("\nExecutando Exemplo 07\n"); return "Exemplo0007 - v0.7"; }
char* E08(bool execute) { if(execute) printf("\nExecutando Exemplo 08\n"); return "Exemplo0008 - v0.8"; }
char* E09(bool execute) { if(execute) printf("\nExecutando Exemplo 09\n"); return "Exemplo0009 - v0.9"; }
char* E10(bool execute) { if(execute) printf("\nExecutando Exemplo 10\n"); return "Exemplo0010 - v1.0"; }
char* E11(bool execute) { if(execute) printf("\nExecutando Exemplo 11\n"); return "Exemplo0011 - v1.1"; }
char* E12(bool execute) { if(execute) printf("\nExecutando Exemplo 12\n"); return "Exemplo0012 - v1.2"; }
char* E13(bool execute) { if(execute) printf("\nExecutando Exemplo 13\n"); return "Exemplo0013 - v1.3"; }
char* E14(bool execute) { if(execute) printf("\nExecutando Exemplo 14\n"); return "Exemplo0014 - v1.4"; }
char* E15(bool execute) { if(execute) printf("\nExecutando Exemplo 15\n"); return "Exemplo0015 - v1.5"; }
char* E16(bool execute) { if(execute) printf("\nExecutando Exemplo 16\n"); return "Exemplo0016 - v1.6"; }
char* E17(bool execute) { if(execute) printf("\nExecutando Exemplo 17\n"); return "Exemplo0017 - v1.7"; }
char* E18(bool execute) { if(execute) printf("\nExecutando Exemplo 18\n"); return "Exemplo0018 - v1.8"; }
char* E19(bool execute) { if(execute) printf("\nExecutando Exemplo 19\n"); return "Exemplo0019 - v1.9"; }
char* E20(bool execute) { if(execute) printf("\nExecutando Exemplo 20\n"); return "Exemplo0019 - v1.9"; }

int main(int argc, char* argv[]) {
    printf("Autor: Arthur Victor Alves\n");
    printf("Tarefa Extra E1 - Indice de 20 Exemplos\n\n");

    typedef char* (*Metodo)(bool);

    int qtde = 20;
    Metodo metodos[] = {
        E00, E01, E02, E03, E04, E05, E06, E07, E08, E09, E10, E11, E12, E13, E14, E15, E16, E17, E18, E19, E20
    };
    
    for (int i = 0; i < qtde; i++) {
        int opcao;
        printf("\nQuestao: %s\n", metodos[i](false));
        printf("Deseja executar? (0 - Sim, 1 - Nao): ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 0) {
            metodos[i](true);
            printf("TESTE (OK)\n");
        } else {
            printf("PULADO\n");
        }
    }

    printf("\nDigite ENTER para sair");
    getchar();
    return 0;
}