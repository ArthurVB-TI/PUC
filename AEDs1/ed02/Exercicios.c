#include "io.h"
// Criei alguns metodos dentro da biblioteca pra me ajudar com as atividades
// Metodos apartir da linha 250

char* p1(bool execute)
{
    if(execute){ 
        int x = 0;
        x = IO_readint("Digite um número inteiro: ");
        if(IO_par(x)){ 
            IO_println("Valor é par"); 
        } else {
            IO_println("Valor é impar");
        }
        if(IO_positivo(x)){ 
            IO_println("Valor é positivo"); 
        } else {
            IO_println("Valor é negativo");
        }
    }
    return "Programa 1";
}

char* p2(bool execute)
{
    if(execute){ 
        int x = 0;
        x = IO_readint("Digite um número inteiro: ");
        if(IO_par(x) && x > -12){
            IO_println("Valor é par e maior do que -12");
        } else {
            if (!IO_par(x) && x < 25){
                IO_println("Valor é impar e menor que 25");
            } else {
                IO_println("Seu valor é um numero normal");
            }
        }
    }
    return "Programa 2";
}

char* p3(bool execute)
{
    if(execute){ 
        int x = 0;
        x = IO_readint("Digite um número inteiro: ");
        if(x > 15 && x < 54){
            IO_println("Valor esta entre o intervalo (15:54)");
        } else {
            IO_println("Valor esta fora do intervalo (15:54)");
        }
    }
    return "Programa 3";
}

char* p4(bool execute)
{
    if(execute){ 
        int x = 0;
        x = IO_readint("Digite um número inteiro: ");
        if(x >= 15 && x <= 54){
            IO_println("Valor esta entre o intervalo [15:54]");
        } else {
            IO_println("Valor esta fora do intervalo [15:54]");
        }
    }
    return "Programa 4";
}

char* p5(bool execute)
{
    if(execute){ 
        int x = 0;
        int count = 0;
        x = IO_readint("Digite um número inteiro: ");
        if(x >= 12 && x <= 24){
            count = count + 1;
        }
        if(x > 20 && x < 50){
            count = count + 1;
        }
        if(count == 2){
            IO_print("Valor pertence a uma intersenção entre [12:24] e (20:50)");
        } else {
            if(count == 1){
                IO_println("Valor pertence a apenas um dos intervalos ( [12:24] , (20:50) )");
            } else {
                IO_println("Valor não pertence a nenhum dos intervalos");
            }
        }
    }
    return "Programa 5";
}

char* p6(bool execute)
{
    if(execute){ 
        int x = 0;
        int y = 0;
        
        x = IO_readint("Digite um número inteiro: ");
        y = IO_readint("Digite outro número inteiro: ");
        
        if(!IO_par(x)){
            IO_println("Primeiro valor é impar");
        } else {
            IO_println("Primeiro valor não é impar");
        }
        if(IO_par(x)){
            IO_println("Primeiro valor é par");
        } else {
            IO_println("Primeiro valor não é par");
        }
    }
    return "Programa 6";
}

char* p7(bool execute)
{
    if(execute){ 
        int x = 0;
        int y = 0;
        
        x = IO_readint("Digite um número inteiro: ");
        y = IO_readint("Digite outro número inteiro: ");
        
        if(!IO_par(x) && x > 0){
            IO_println("Primeiro valor é impar e positivo");
        } else {
            IO_println("Primeiro valor não é impar e positivo");
        }
        if(IO_par(x) && x < 0){
            IO_println("Primeiro valor é par e negativo");
        } else {
            IO_println("Primeiro valor não é par e negativo");
        }
    }
    return "Programa 7";
}

char* p8(bool execute)
{
    if(execute){ 
        double x = 0.0;
        double y = 0.0;
        
        x = IO_readdouble("Digite um número real: ");
        y = IO_readdouble("Digite outro número real: ");
        
        if(x < y){
            IO_println("Primeiro valor é menor que o segundo");
        } else {
            if(x == y) {
                IO_println("Primeiro valor é igual ao segundo");
            } else {
                IO_println("Primeiro valor é menor que o segundo");
            }
        }
    }
    return "Programa 8";
}

char* p9(bool execute)
{
    if(execute){ 
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
        
        x = IO_readdouble("Digite o primeiro número real: ");
        y = IO_readdouble("Digite o segundo número real: ");
        z = IO_readdouble("Digite o terceiro número real: ");
        
        if(x != z){
            if(z - x > 0){
                if(y <= z && y >= x){
                    IO_println("O segundo valor esta entre o primeiro e o ultimo");
                } else {
                    IO_println("O segundo valor não esta entre o primeiro e o ultimo");
                }
            } else {
                if(y >= z && y <= x){
                    IO_println("O segundo valor esta entre o primeiro e o ultimo");
                } else {
                    IO_println("O segundo valor não esta entre o primeiro e o ultimo");
                }
            }
        } else {
            IO_println("O primeiro e o ultimo valor são iguais");
        }
    }
    return "Programa 9";
}

char* p10(bool execute)
{
    if(execute){ 
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;
        
        x = IO_readdouble("Digite o primeiro número real: ");
        y = IO_readdouble("Digite o segundo número real: ");
        z = IO_readdouble("Digite o terceiro número real: ");
        
        if(x != z && z != y && y != x){
            if(z - x > 0){
                if(y <= z && y >= x){
                    IO_println("O segundo valor esta entre o primeiro e o ultimo");
                } else {
                    IO_println("O segundo valor não esta entre o primeiro e o ultimo");
                }
            } else {
                if(y >= z && y <= x){
                    IO_println("O segundo valor esta entre o primeiro e o ultimo");
                } else {
                    IO_println("O segundo valor não esta entre o primeiro e o ultimo");
                }
            }
        } else {
            IO_println("Todos os valores são iguais");
        }
    }
    return "Programa 10";
}

void main( void )
{
    Metodo metodos[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10}; 
    IO_execute(10, metodos);
}