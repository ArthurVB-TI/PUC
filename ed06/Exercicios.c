#include "io.h"
void Somar3(int x)
{
    if(x > 0){
        Somar3(x-1);
        IO_printf("Resultado é: %d\n", x);
    }
}

void Sub5(int x)
{
    if(x > 0){
        IO_printf("Resultado é: %d\n", x);
        Sub5(x-1);
    }
}

void Div3(int x)
{
    if(x > 0){
        double resultado = 0.0;
        if(x - 1 == 0){
            resultado = 1.0;
        } else {
            resultado = 1.0/((x - 1.0) * 3.0);
        }
        Div3(x-1);
        IO_printf("Resultado é: %lf\n", resultado);
    }
}

void Div5(int x)
{
    if(x > 0){
        double resultado = 0.0;
        if(x - 1 == 0){
            resultado = 1.0;
        } else {
            resultado = 1.0/((x - 1.0) * 5.0);
        }
        IO_printf("Resultado é: %lf\n", resultado);
        Div5(x-1);
    }
}

int Soma_Continua(int x)
{
    if(x > 0){
        int resultado = 0;
        int retorno = 0;
        if(x - 1 > 0){
            resultado = 3 + pow(x-1,2);
        } else {
            resultado = 3;
        }
        retorno = Soma_Continua(x-1);
        IO_printf("%d + %d = %d\n",resultado, retorno, resultado + retorno);
        resultado = resultado + retorno;
        return resultado;
    }
    return 0;
}

double Soma_Fracao(int x)
{
    if(x > 0){
        double resultado = 1.0 / (4.0 * x);
        double retorno = Soma_Fracao(x-1);
        
        IO_printf("%lf + %lf = %lf\n",resultado, retorno, resultado + retorno);
        return resultado + retorno;
    }
    return 0.0;
}

void Inverter(chars caracts,int x)
{
    if(x > 0){
        char caractere = caracts[x-1];
        IO_printf("Char[%d]: %c\n",x-1,caractere);
        Inverter(caracts,x-1);
    }
}

void Char_par(chars caracts,int x)
{
    if(x >= 0){
        char caractere = caracts[x];
        if(x == 0 OR x % 2 == 0){
            IO_printf("Char[%d]: %c\n",x,caractere);
        }
        Char_par(caracts,x-1);
    }
}

void Intervalo_K_P(chars caracts,int x,int count)
{
    if(x > 0){
        char caractere = caracts[x];
        if(caractere > 'K' AND caractere < 'P'){
            IO_printf("Char[%d]: %c\n",x,caractere);
            count = count + 1;
        }
        Intervalo_K_P(caracts,x-1,count);
    }
}

int fibonacci(int x){
    int retorno = 0;
    if(x == 1 || x == 2){
        retorno = 1;
    }else {
        if(x > 1){
            retorno = fibonacci(x - 1) + fibonacci(x - 2);
        }
    }
    return retorno;
}

typedef struct{
    int qtde;
    int ultimo_valor;
    int resultado;
} retorno_fibonacci;

retorno_fibonacci Soma_Fibonacci_Par(retorno_fibonacci f)
{
    if(f.qtde > 0){
        retorno_fibonacci new_f = {f.qtde - 1, f.ultimo_valor,f.resultado};
        f = Soma_Fibonacci_Par(new_f);
        int r_fibonacci = 0;
        int i = 1;
        
        do{
            r_fibonacci = fibonacci(i);
            i = i + 1;
        }while(r_fibonacci % 2 != 0 OR r_fibonacci <= f.ultimo_valor);
        
        f.ultimo_valor = r_fibonacci;
        IO_printf("%d + %d = %d\n", r_fibonacci, f.resultado, f.resultado + r_fibonacci);
        f.resultado = f.resultado + r_fibonacci;
        return(f);
    }
    retorno_fibonacci old_f = {0,0,0};
    return(old_f);
}

char* p1(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Escreva uma quantidade inteira: ");
        Somar3(qtde);
    }
    return "Programa 1";
}

char* p2(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Escreva uma quantidade inteira: ");
        Sub5(qtde);
    }
    return "Programa 2";
}

char* p3(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Escreva uma quantidade inteira: ");
        Div3(qtde);
    }
    return "Programa 3";
}

char* p4(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Escreva uma quantidade inteira: ");
        Div5(qtde);
    }
    return "Programa 4";
}

char* p5(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Escreva uma quantidade inteira: ");
        Soma_Continua(qtde);
    }
    return "Programa 5";
}

char* p6(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Escreva uma quantidade inteira: ");
        Soma_Fracao(qtde);
    }
    return "Programa 6";
}

char* p7(bool execute)
{
    if(execute){
        chars cadeia = IO_new_chars(STR_SIZE);
        cadeia = IO_readstring("Escreva um texto para ser invertido: ");
        Inverter(cadeia,strlen(cadeia));
    }
    return "Programa 7";
}

char* p8(bool execute)
{
    if(execute){
        chars cadeia = IO_new_chars(STR_SIZE);
        cadeia = IO_readstring("Escreva um texto: ");
        Char_par(cadeia,strlen(cadeia)-1);
    }
    return "Programa 8";
}

char* p9(bool execute)
{
    if(execute){
        chars cadeia = IO_new_chars(STR_SIZE);
        cadeia = IO_readstring("Escreva um texto: ");
        Intervalo_K_P(cadeia,strlen(cadeia),0);
    }
    return "Programa 9";
}

char* p10(bool execute)
{
    if(execute){
        int qtde = 0;
        qtde = IO_readint("Escreva uma quantidade inteira: ");
        retorno_fibonacci f = {qtde,0,0};
        Soma_Fibonacci_Par(f);
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