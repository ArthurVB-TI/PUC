#include "io.h"

long long Metodo_01(int qtde, int valor)
{
    if(qtde > 0){
        long long resultado = Metodo_01(qtde - 1,valor);
        if(qtde == 1){
            IO_printf("%d + %d = %d\n",0,1,1);
            return 1;
        } else {
            long long r = pow(valor,(qtde*2)-1);
            IO_printf("%lld + %lld = %lld\n",resultado,r,resultado + r);
            return resultado + r;
        }
    }
    return 0LL;
}

int Soma(int value,int resultado){
    if(value > 0){
        resultado = Soma(value-1,resultado) + value-1;
        return resultado;
    }
    return 1;
}

int Fatorial(int value){
    int resultado = 1;
    for(int i = 1; i <= value; i = i + 1){
        resultado = resultado * i;
    }
    return resultado;
}

double Metodo_02(int qtde)
{
    if(qtde > 0){
        double resultado = Metodo_02(qtde-1);
        if(qtde == 1){
            IO_printf("%lf + %lf = %lf\n",0.0,1.0,1.0);
            return 1;
        } else {
            double r = (double)Soma(qtde,0)/(double)Fatorial(pow(3,qtde-1));
            IO_printf("%lf + %lf = %lf\n",resultado,r,resultado + r);
            return resultado + r;
        }
    }
    return 0;
}

int main()
{
    IO_id("Extras");
    int opcoes = 0;
    int qtde = 0;
    int valor = 0;

    IO_println("Opções:");
    IO_println("0 - SAIR");
    IO_println("1 - METODO 1");
    IO_println("2 - METODO 2");
    opcoes = IO_readint("Escolha uma das opções  -   ");
    do{
        switch(opcoes){
            case 0: break;
            case 1:
                valor = IO_readint("Escreva um numero inteiro: ");
                qtde = IO_readint("Escreva uma quantidade inteira: ");
                Metodo_01(qtde,valor); 
                IO_println("");
                opcoes = IO_readint("Escolha outra opção: ");
                break;
            case 2:
                qtde = IO_readint("Escreva uma quantidade inteira: ");
                
                Metodo_02(qtde); 
                IO_println("");
                opcoes = IO_readint("Escolha outra opção: ");
                break;
            default: opcoes = IO_readint("Escolha outra opção: "); break;
        }
    }while(opcoes != 0);
    return(0);
}