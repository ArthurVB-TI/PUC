#include "io.h"

void Multiplos_de_3(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        for(int i = 0;i < qtde;i = i + 1){
            if(i + 1 < qtde){
                IO_printf("%d, ",i*3);
            }else{
                IO_printf("%d",i*3);
            }
        }
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Multiplos_de_3e5(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        for(int i = 0;i < qtde;i = i + 1){
            if(i + 1 < qtde){
                IO_printf("%d, ",i*3*5);
            }else{
                IO_printf("%d",i*3*5);
            }
        }
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Potencia_de_3_Decrescente(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        for(int i = (qtde - 1);i >= 0;i = i - 1){
            if(i - 1 >= 0){
                IO_printf("%f, ",pow(3,i));
            }else{
                IO_printf("%f",pow(3,i));
            }
        }
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Divido_por_3(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        for(int i = 1;i <= qtde;i = i + 1){
            if(i + 1 <= qtde){
                IO_printf("%lf, ",1.0 / ((double) i * 3.0));
            }else{
                IO_printf("%lf",1.0 / ((double) i * 3.0));
            }
        }
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Potencia_de_X(int qtde, double valor)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        for(int i = 0;i < qtde;i = i + 1){
            if(i + 1 < qtde){
                IO_printf("%lf, ",pow(1.0/valor,i*2));
            }else{
                IO_printf("%lf",pow(1.0/valor,i*2));
            }
        }
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void SomaDeValoresDe3_DiferenteDe5(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        int x = 0;
        int resultado = 0;
        for(int i = 0;i < qtde;i = i + 1){
            x = x + 3;
            if(x % 5 == 0){
                x = x + 3;
            }
            resultado = resultado + x;
        }
        IO_printf("%d",resultado);
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Divisores_de_4(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        int x = 0;
        double resultado = 0;
        for(int i = 0;i < qtde;i = i + 1){
            x = x + 4;
            if(x % 5 == 0){
                x = x + 4;
            }
            resultado = resultado + (1.0 / (double) x);
        }
        IO_printf("%lf",resultado);
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Soma_apartir_de_5(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        int x = 5;
        int resultado = 0;
        for(int i = 0;i <= qtde;i = i + 1){
            x = x + i;
            resultado = resultado + x;
        }
        IO_printf("%d",resultado);
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Soma_da_potencia(int qtde)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        int x = 5;
        long long resultado = 0;
        for(int i = 3;i <= qtde+3;i = i + 1){
            x = pow(i,2);
            resultado = resultado + x;
        }
        IO_printf("%lli",resultado);
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

void Soma_do_inverso(int qtde,int valor)
{
    if(qtde > 0){
        IO_printf("\n{ ");
        double x = 0;
        double resultado = 1.0/valor;
        for(int i = qtde-1;i > 0;i = i - 1){
            x = 1.0/(valor - i);
            resultado = resultado + x;
        }
        IO_printf("%lf",resultado);
        IO_printf(" }\n");
    }else{
        IO_println("Quantidade abaixo de 0");
    }
}

char* p1(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Multiplos_de_3(qtde);
        IO_println("");
    }
    return "Programa 1";
}

char* p2(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Multiplos_de_3e5(qtde);
        IO_println("");
    }
    return "Programa 2";
}

char* p3(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Potencia_de_3_Decrescente(qtde);
        IO_println("");
    }
    return "Programa 3";
}

char* p4(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Divido_por_3(qtde);
        IO_println("");
    }
    return "Programa 4";
}

char* p5(bool execute)
{
    if(execute){
        int qtde = 0;
        double valor = 0.0;
        valor = IO_readdouble("Escreva um valor real: ");
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Potencia_de_X(qtde,valor);
        IO_println("");
    }
    return "Programa 5";
}

char* p6(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        SomaDeValoresDe3_DiferenteDe5(qtde);
        IO_println("");
    }
    return "Programa 6";
}

char* p7(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Divisores_de_4(qtde);
        IO_println("");
    }
    return "Programa 7";
}

char* p8(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Soma_apartir_de_5(qtde);
        IO_println("");
    }
    return "Programa 8";
}

char* p9(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Soma_da_potencia(qtde);
        IO_println("");
    }
    return "Programa 9";
}

char* p10(bool execute)
{
    if(execute){
        int qtde = 0;
        int valor = 0;
        chars num = IO_new_chars(STR_SIZE);
        bool verificado = false;
        valor = IO_readint("Escreva um valor inteiro terminado em 3: ");
        while(!verificado){
            num = IO_toString_d(valor);
            if(num[strlen(num)-1] != '3'){
                IO_println("Valor não é terminado em 3");
                valor = IO_readint("Escreva um valor inteiro terminado em 3: ");
            } else {
                verificado = true;
            }
        }
        qtde = IO_readint("Selecione uma quantidade inteira: ");
        Soma_do_inverso(qtde,valor);
        IO_println("");
    }
    return "Programa 10";
}

int main()
{
    IO_id("Exercicios");
    Metodo metodos[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    IO_execute(10,metodos);
    return (0);
}