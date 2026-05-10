#include "io.h"

void findex_matriz(char arquivo_nome[],int n,int m,int** matriz){
    FILE* arquivo = fopen(arquivo_nome,"wt");

    for(int i = 0; i < n; i = i + 1){
        for(int j = 0; j < m; j = j + 1){
            if(j + 1 < m){
                fprintf(arquivo,"%d\t",matriz[i][j]);
            } else {
                fprintf(arquivo,"%d",matriz[i][j]);
            }
        }
        fprintf(arquivo,"\n");
    }

    fclose(arquivo);
}

// 09E1
int** ler_valores_matriz1(int n,int m){
    int** retorno = (int**) malloc(sizeof(int*)*n);
    int valorAtual = 0;
    bool v = false;

    for(int i = 0; i < n; i = i + 1){
        retorno[i] = (int*) malloc(sizeof(int)*m);
        IO_printf("Digite valores positivo ou zero na linha %d\n",i+1);
        for(int j = 0; j < m; j = j + 1){
            do{
                IO_printf("Coluna [%d] - ",j+1);
                v = scanf("%d",&valorAtual); getchar( );
                if(!v){
                    IO_printf("Digite um numero real!\n");
                } else {
                    if(valorAtual < 0){
                        IO_printf("Valor Invalido!\n");
                    }
                }
            }while(!v || valorAtual < 0);
            retorno[i][j] = valorAtual;
        }
    }

    return retorno;
}

// 09E2
int** ler_valores_matriz2(int n,int m){
    int** retorno = (int**) malloc(sizeof(int*)*n);
    int valorAtual = 0;
    bool v = false;

    for(int i = 0; i < n; i = i + 1){
        retorno[i] = (int*) malloc(sizeof(int)*m);
    }

    for(int j = m - 1; j >= 0; j = j - 1){
        IO_printf("Digite valores positivo ou zero na coluna %d\n",j+1);
        for(int i = n - 1; i >= 0; i = i - 1){
            do{
                IO_printf("Linha [%d] - ",i+1);
                v = scanf("%d",&valorAtual); getchar( );
                if(!v){
                    IO_printf("Digite um numero real!\n");
                } else {
                    if(valorAtual < 0){
                        IO_printf("Valor Invalido!\n");
                    }
                }
            }while(!v || valorAtual < 0);
            retorno[i][j] = valorAtual;
        }
    }    

    return retorno;
}

void m1()
{
    int linhas = 0;
    int colunas = 0;
    int** matriz;

    IO_lerMatriz(&linhas,&colunas);
    matriz = ler_valores_matriz1(linhas,colunas);

    findex_matriz("EXTRA1.TXT",linhas,colunas,matriz);
}

void m2()
{
    int linhas = 0;
    int colunas = 0;
    int** matriz;

    IO_lerMatriz(&linhas,&colunas);
    matriz = ler_valores_matriz2(linhas,colunas);

    findex_matriz("EXTRA2.TXT",linhas,colunas,matriz);
}

int main()
{
    int opcao = 0;
    do{
        IO_println("Opções:");
        IO_println("0 - SAIR");
        IO_println("1 - METODO 1");
        IO_println("2 - METODO 2");
        opcao = IO_readint("Escolha uma das opções  -   ");

        switch(opcao){
            case 0: break;
            case 1:
                m1();
                break;
            case 2:
                m2();
                break;
            default:
                opcao = IO_readint("Escolha outra opção: ");
                break;
        }
    }while(opcao != 0);

    return 0;
}