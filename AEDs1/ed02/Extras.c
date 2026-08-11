#include "io.h"

void e1()
{
    char a = '_';
    char b = '_';
    char c = '_';

    a = IO_readchar("Digite o valor do primeiro caracter: ");
    b = IO_readchar("Digite o valor do segundo caracter: ");
    c = IO_readchar("Digite o valor do terceiro caracter: ");

    if(a == b){
        IO_println("O primeiro caracter é igual ao segundo");
    } else {
        if(a == c){
            IO_println("O primeiro caracter é igual ao terceiro");
        } else {
            if(a == b && b == c && c == a) {
                IO_println("Todos os 3 caracteres são iguais");
            } else {
                if(b == c){ 
                    IO_println("O segundo e o tercerio caracter são iguais"); 
                    return; 
                }
                if(b < c){
                    if(a > b && a < c){
                        IO_println("O primeiro caracter esta entre o segundo e o terceiro");
                    } else {
                        IO_println("O primeiro caracter não esta entre o segundo e o terceiro");
                    }
                } else {
                    if(a < b && a > c){
                        IO_println("O primeiro caracter esta entre o segundo e o terceiro");
                    } else {
                        IO_println("O primeiro caracter não esta entre o segundo e o terceiro");
                    }
                }
            }
        }
    }
}

void e2()
{
    char a = '_';
    char b = '_';
    char c = '_';

    a = IO_readchar("Digite o valor do primeiro caracter: ");
    b = IO_readchar("Digite o valor do segundo caracter: ");
    c = IO_readchar("Digite o valor do terceiro caracter: ");

    if(a == b){
        IO_println("O primeiro caracter é igual ao segundo");
    } else {
        if(a == c){
            IO_println("O primeiro caracter é igual ao terceiro");
        } else {
            if(a == b && b == c && c == a) {
                IO_println("Todos os 3 caracteres são iguais");
            } else {
                if(b == c){ 
                    IO_println("O segundo e o tercerio caracter são iguais"); 
                    return; 
                }
                if(b < c){
                    if(a > b && a < c){
                        IO_println("O primeiro caracter esta entre o segundo e o terceiro");
                    } else {
                        IO_println("O primeiro caracter não esta entre o segundo e o terceiro");
                    }
                } else {
                    if(a < b && a > c){
                        IO_println("O primeiro caracter esta entre o segundo e o terceiro");
                    } else {
                        IO_println("O primeiro caracter não esta entre o segundo e o terceiro");
                    }
                }
            }
        }
    }
}

void main( void )
{
    int opcao = 0;
    
    IO_println("Escolha alguma das ações para ser executada");
    IO_println("0  -  Finalizar");
    IO_println("1  -  Metodo 1");
    IO_println("2  -  Metodo 2");

    printf("\n");

    opcao = IO_readint("Opção: ");

    do
    {
        switch(opcao)
        {
            case 0:
                break;
            case 1:
                e1();
                printf("\n");
                IO_println("Selecione outra opção");
                opcao = IO_readint("Opção: ");
                break;
            case 2:
                e2();
                printf("\n");
                IO_println("Selecione outra opção");
                opcao = IO_readint("Opção: ");
                break;
            default:
                IO_println("");
                IO_println("opção invalida!");
                IO_println("");
                break;
        }
    }
    while (opcao != 0);

    printf("\n");
    printf("Pressione ENTER para finalizar");
    getchar();
}