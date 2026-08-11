#include "io.h"

void metodo1()
{
    chars linha = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    int count = 0;

    linha = IO_readln("Digite uma linha de texto: ");
    tamanho = strlen(linha);

    for(int i = 0; i < tamanho; i = i + 1){
        if(!IO_readLetra(linha[i]) && !IO_readNumero(linha[i])){
            IO_printf("%d\t - \t %c\n",i + 1,linha[i]);
            count = count + 1;
        }
    }
    IO_printf("\n%s[%d/%d]\n","count: ",count,tamanho);
}

void metodo2()
{
    chars linha = IO_new_chars(STR_SIZE);
    struct array {
        bool ver;
        chars texto;
    };
    struct array a[STR_SIZE / 2];
    int tamanho = 0;
    int A_len = 0;
    int count = 0;

    linha = IO_readln("Digite uma linha de texto: ");
    tamanho = strlen(linha);
    
    for(int i = 0; i < tamanho; i = i + 1){
        if(IO_readLetra(linha[i]) && IO_readNumero(linha[i])){
            a[A_len].ver = false;
        }
        if(linha[i] == ' '){
            a[A_len + 1].ver = true;
            A_len = A_len + 1;
        } else {
            if(a[A_len].texto == NULL){
                a[A_len].texto = IO_toString_c(linha[i]);
            }
            a[A_len].texto = a[A_len].texto + linha[i];
        }
    }

    for(int i = 0; i < A_len; i = i + 1){
        if(a[i].ver){
            IO_printf("Cadeia %d\t - \t%s\n",i + 1,a[i].texto);
            count = count + 1;
        }
    }
    IO_printf("\n%s[%d/%d]\n","count: ",count,A_len + 1);
    IO_flush();
}

int main()
{
    int opcao = 0;
    IO_id("Atividades extras");

    IO_println("Escolha uma das seguintes opções ");
    IO_printf("%s\t - \t%s\n","0","Sair");
    IO_printf("%s\t - \t%s\n","1","Metodo 1");
    IO_printf("%s\t - \t%s\n","2","Metodo 2");
    IO_println("");

    opcao = IO_readint("opção:");
    

    do{
        switch(opcao)
        {
            case 0: break;
            case 1: metodo1(); opcao = IO_readint("Escolha outra opção: "); break;
            case 2: metodo2(); opcao = IO_readint("Escolha outra opção: "); break; 
            default: opcao = IO_readint("Escolha outra opção: "); break;
        }
    }while(opcao != 0);

    IO_pause("Pressione ENTER para terminar");
    
    return (0);
}