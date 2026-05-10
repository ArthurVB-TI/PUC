#include "io.h"

chars e1()
{
    IO_printf("\nExtra 01\n");
    Modificacoes M = create_Modificacoes();
    Palavras P = create_Palavras(&M);
    
    chars txt = IO_readln("Escreva uma frase: ");
    
    M.Modificacoes_update(&M,txt);
    P.Palavras_Words_filter(&P);
    P.Palavras_map(&P);
    
    IO_printf("Count: %d\n\n",P.Palavras_count(&P));
}

chars e2()
{
    IO_printf("\nExtra 02\n");
    Modificacoes M1 = create_Modificacoes();
    Modificacoes M2 = create_Modificacoes();
    
    chars txt1 = IO_readstring("Escreva a primeria frase: ");
    chars txt2 = IO_readstring("Escreva a primeria frase: ");
    
    M1.Modificacoes_update(&M1,txt1);
    M2.Modificacoes_update(&M2,txt2);

    int qtde1 = M1.Modificacoes_count(&M1);
    int qtde2 = M2.Modificacoes_count(&M2);

    IO_println("");
    if(qtde1 == qtde2){
        IO_printf("Ambos possuem a mesma quantidade de caracteres [%d/%d]",qtde1,qtde2);
    } else {
        if(qtde1 > qtde2){
            IO_printf("A primeira frase possui %d caracteres a mais do que a segunda [%d/%d]",qtde1-qtde2,qtde1,qtde2);
        } else {
            IO_printf("A segunda frase possui %d caracteres a mais do que a primeira [%d/%d]",qtde2-qtde1,qtde2,qtde1);
        }
    }
}

int main()
{
    int opcoes = 0;
    IO_id("Extras");
    do{
        IO_println("");
        IO_println("0   -   Sair");
        IO_println("1   -   Extra 1");
        IO_println("2   -   Extra 2");
        IO_println("");
        opcoes = IO_readint("Selecione uma das opções: ");
        switch(opcoes){
            case 0: break;
            case 1: e1(); IO_println("Escolha outra opção"); break;
            case 2: e2(); IO_println("Escolha outra opção"); break;
            default: IO_println("Escolha outra opção"); break;
        }
    }while(opcoes != 0);

    IO_pause("Pressione ENTER para terminar");
    return(0);
}