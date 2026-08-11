#include "io.h"
#include "extras/routes.h"

int main()
{
    int opcao = 0;
    bool v = false;
    IO_id("Extras");
    
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
                IO_println("");
                break;
            case 2:
                m2();
                IO_println("");
                break;
            default:
                IO_println("Opção Invalida!");
                break;
        }
    }while(opcao != 0);

    return 0;
}