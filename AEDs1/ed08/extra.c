#include "io.h"

#define MAX 100

void index_m1(int n, int *arranjo){
    int index = 0;
    IO_printf("\nO valor %d é divisivel pelos seguintes números ímpares:\n\t", n);

    while(index < n && arranjo[index] != 0){
        if(index < n-1 && arranjo[index+1] != 0){
            IO_printf("%d - ", arranjo[index]);
        } else {
            IO_printf("%d\n", arranjo[index]);
        }
        index = index + 1;
    }
}

void index_m2(int n, char **arranjo){
    int index = 0;
    IO_printf("\n%d primeiras palavras que não começam com f/F: \n", n);

    while(index < n && arranjo[index] != NULL){
        if(index < n-1){
            IO_printf("%s - ", arranjo[index]);
        } else {
            IO_printf("%s\n", arranjo[index]);
        }
        index = index + 1;
    }
}

// 08E1
void pegarQuantidade(int *qtde){
    bool v = false;
    do{
        IO_printf("Digite uma quantidade positiva e inteira: ");
        v = scanf("%d", qtde); getchar();

        if(!v || *qtde <= 0){
            IO_printf("Valor Invalido!\n");
        }
    }while(!v || *qtde <= 0);
}

int* acharDivisores(int value){
    int count = 0;
    int *retorno = (int*) malloc(sizeof(int) * (value+1));

    for(int i = 1; i <= value; i++){
        if(value % i == 0 && i % 2 != 0){
            retorno[count] = i;
            count = count + 1;
        }
    }

    retorno[count] = 0;
    return retorno;
}

// 08E2
void lerPalavras(int *n, char **arranjo, chars arquivo_nome)
{
    FILE* arquivo = fopen(arquivo_nome,"rt");
    if(arquivo == NULL){
        *n = 0;
        return;
    }
    int index = 0;
    int header = 0;
    int count = 0;
    bool v = false;
    char lixo[MAX];
    char Palavra_atual[MAX];

    v = fscanf(arquivo,"%d",&header);
    if(!v) header = 100;

    while(!feof(arquivo) && index < 100 && index < header && count < *n){
        v = fscanf(arquivo,"%s", Palavra_atual);

        if(v){
            int tamanho = strlen(Palavra_atual);

            if((Palavra_atual[0] != 'f' && Palavra_atual[0] != 'F') &&
               (Palavra_atual[tamanho-1] != 'f' && Palavra_atual[tamanho-1] != 'F')){

                arranjo[count] = (char*) malloc(strlen(Palavra_atual)+1);
                strcpy(arranjo[count], Palavra_atual);
                count = count + 1;
            }
        } else {
            fgets(lixo, sizeof(lixo), arquivo);
        }
        index = index + 1;
    }

    *n = count;
    arranjo[count] = NULL;

    fclose(arquivo);
}

// Extras
void m1()
{
    int qtde = 0;
    int *divisores;

    pegarQuantidade(&qtde);
    divisores = acharDivisores(qtde);
    index_m1(qtde, divisores);
}

void m2()
{
    int qtde = 10;
    char **palavras = (char**) malloc(sizeof(char*) * (qtde+1));

    lerPalavras(&qtde, palavras, "PALAVRAS.TXT");
    index_m2(qtde, palavras);
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