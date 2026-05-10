#include "io.h"

void criarArquivoTeste()
{
    FILE* arquivo = fopen("teste.txt","wt");
    fprintf(arquivo,"Kibodsa aisugbds\nksoiaydviad iasibd\nK9subyadosa\naoiybgsdia iawhbo\nKisyavdutsavfdyuatvwvdyawvdsawbdusvafuwydtuasgwuduas\nk8asubd8iywds6arvdwf6rdvasfdusyavtdwyfvsuadvwuads\nKdisb auusad ayd\nk aayvduias\n");
    fclose(arquivo);
}

void m1()
{
    int valor = 0;
    FILE* arquivo = fopen("extra1.txt","at");

    valor = IO_readint("Escreva um valor: ");
    fprintf(arquivo,"Divisiveis impares do valor %d: \n",valor);
    for(int i = valor - 1; i > 0; i = i - 1){
        if(i % 2 == 1 && valor % i == 0){
            fprintf(arquivo,"\t[%d] - %lf",i,(double)(valor/i));
        }
    }
    fclose(arquivo);
}

void m2()
{
    FILE* read_arquivo = fopen("teste.txt","rt");
    chars arquivo_linha = IO_new_chars(STR_SIZE);
    int count = 0;

    printf("Textos que começam com k/K e tem menos de 12 caracteres: \n");
    while( !feof(read_arquivo) && fgets(arquivo_linha,STR_SIZE,read_arquivo)){
        if((arquivo_linha[0] == 'k' || arquivo_linha[0] == 'K') && strlen(arquivo_linha) <= 12){
            printf("\t%s\n",arquivo_linha);
            count = count + 1;
        }
    }
    printf("count [%d]\n",count);
    fclose(read_arquivo);
}

int main()
{
    IO_id("Extras");
    int opcao = 0;

    criarArquivoTeste();

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
            default: opcao = IO_readint("Escolha outra opção: "); break;
        }
    }while(opcao != 0);

    return 0;
}