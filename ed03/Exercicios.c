#include "io.h"

char* p1( bool execute )
{
    if (execute){
        chars palavra;
        int x = 0;
        int qtde = 0;

        palavra = IO_readstring("Escreva uma palavra: ");
        qtde = strlen(palavra);

        for(int y = x; y < qtde; y = y + 1){
            if(palavra[y] >= 'A' && palavra[y] < 'K'){
                IO_printf("%d - [%c]\n",(y + 1), palavra[y]);
            }
        }
        IO_println("");
    }
    return "Programa 1";
}

char* p2( bool execute )
{
    if (execute){
        chars palavra;
        int x = 0;
        int qtde = 0;

        palavra = IO_readstring("Escreva uma palavra: ");
        qtde = strlen(palavra);

        for(int y = x; y < qtde; y = y + 1){
            if(palavra[y] <= 'z' && palavra[y] > 'k'){
                IO_printf("%d - [%c]\n",(y + 1), palavra[y]);
            }
        }
        IO_println("");
    }
    return "Programa 2";
}

char* p3( bool execute )
{
    if (execute){
        chars palavra;
        int x = 0;
        int qtde = 0;
        int count = 0;

        palavra = IO_readstring("Escreva uma palavra: ");
        qtde = strlen(palavra);

        for(int y = qtde - 1; y >= x; y = y - 1){
            if(palavra[y] >= 'A' && palavra[y] < 'K'){
                count = count + 1;
                IO_printf("%d - [%c]\n",(y + 1), palavra[y]);
            }
        }
        IO_printf("%s%d\n","Counter: ",count);
    }
    return "Programa 3";
}

char* p4( bool execute )
{
    if (execute){
        chars palavra;
        int x = 0;
        int qtde = 0;
        int count = 0;

        palavra = IO_readstring("Escreva uma palavra: ");
        qtde = strlen(palavra);

        for(int y = x; y < qtde; y = y + 1){
            if((palavra[y] >= 'A' && palavra[y] <= 'Z') || (palavra[y] >= 'a' && palavra[y] <= 'z')){
                count = count + 1;
                IO_printf("%d - [%c]\n",(y + 1), palavra[y]);
            }
        }
        IO_printf("%s%d\n","Counter: ",count);
    }
    return "Programa 4";
}

char* p5( bool execute )
{
    if (execute){
        chars palavra;
        int x = 0;
        int qtde = 0;
        int count = 0;

        palavra = IO_readstring("Escreva uma palavra: ");
        qtde = strlen(palavra);

        for(int y = qtde - 1; y >= x; y = y - 1){
            int num = palavra[y] - '0';
            if(palavra[y] >= '0' && palavra[y] <= '9' && IO_par(num)){
                count = count + 1;
                IO_printf("%d - [%c]\n",(y + 1), palavra[y]);
            }
        }
        IO_printf("%s%d\n","Counter: ",count);
    }
    return "Programa 5";
}

char* p6( bool execute )
{
    if (execute){
        chars palavra;
        int x = 0;
        int qtde = 0;
        int count = 0;

        palavra = IO_readstring("Escreva uma palavra: ");
        qtde = strlen(palavra);

        for(int y = qtde - 1; y >= x; y = y - 1){
            int num = palavra[y] - '0';
            if(!(palavra[y] >= 'A' && palavra[y] <= 'Z') && !(palavra[y] >= 'a' && palavra[y] <= 'z') && !IO_par(num)){
                count = count + 1;
                IO_printf("%d - [%c]\n",(y + 1), palavra[y]);
            }
        }
        IO_printf("%s%d\n","Counter: ",count);
    }
    return "Programa 6";
}

char* p7( bool execute )
{
    if (execute){
        int x = 0;
        int y = 0;
        int z = 0;
        int count = 0;

        x = IO_readint("Digite o inicio do intervalo: ");

        do{
            y = IO_readint("Digite o valor do final do intervalo: ");
            if(y <= x){
                IO_println("(Digite um valor maior do que o inicio do intervalo)");
            }
        }while(y <= x);

        do{
            z = IO_readint("Digite o valor da quantidade: ");
            if(z <= 0){
                IO_println("(Digite um valor maior do que 0)");
            }
        }while(z <= 0);

        int array[z];
        IO_printf("\n%s\n","Digite os valores:");

        for(int i = 0; i < z; i = i + 1){
            IO_printf("%d - ",i);
            array[i] = IO_readint("");
        }
        IO_println("");

        for(int i = 0; i < z; i = i + 1){
            if((array[i] >= x && array[i] <= y) && array[i] % 5 == 0){
                count = count + 1;
                IO_printf("\n%s%d%s%d:%d%s\n","O valor ",array[i]," pertence ao intervalo [",x,y,"] e é divisivel por 5");
            }
        }
        IO_printf("\n%s[%d/%d]\n","count: ",count,z);
    }
    return "Programa 7";
}

char* p8( bool execute )
{
    if (execute){
        int x = 0;
        int y = 0;
        int z = 0;
        int count = 0;

        x = IO_readint("Digite o inicio do intervalo: ");

        do{
            y = IO_readint("Digite o valor do final do intervalo: ");
            if(y <= x){
                IO_println("(Digite um valor maior do que o inicio do intervalo)");
            }
        }while(y <= x);

        do{
            z = IO_readint("Digite o valor da quantidade: ");
            if(z <= 0){
                IO_println("(Digite um valor maior do que 0)");
            }
        }while(z <= 0);

        int array[z];
        IO_printf("\n%s\n","Digite os valores:");

        for(int i = 0; i < z; i = i + 1){
            IO_printf("%d - ",i);
            array[i] = IO_readint("");
        }
        IO_println("");

        for(int i = 0; i < z; i = i + 1){
            if((array[i] >= x && array[i] <= y) && !(array[i] % 5 == 0) && array[i] % 3 == 0){
                count = count + 1;
                IO_printf("\n%s%d%s%d:%d%s\n","O valor ",array[i]," pertence ao intervalo [",x,y,"], é divisivel por 3 e não é divisivel por 5");
            }
        }
        IO_printf("\n%s[%d/%d]\n","count: ",count,z);
    }
    return "Programa 8";
}

char* p9( bool execute )
{
    if (execute){
        double a = 0.0;
        double b = 0.0;
        int qtde = 0;
        int count = 0;

        a = IO_readdouble("Digite o valor real do inicio do intervalo: ");

        do{
            b = IO_readdouble("Digite o valor real do final do intervalo: ");
            if(b <= a){
                IO_println("(Digite um valor maior do que o inicio do intervalo)");
            }
        }while(b <= a);

        do{
            qtde = IO_readint("Digite o valor da quantidade: ");
            if(qtde <= 0){
                IO_println("(Digite um valor maior do que 0)");
            }
        }while(qtde <= 0);

        double array[qtde];
        IO_printf("\n%s\n","Digite os valores:");

        for(int i = 0; i < qtde; i = i + 1){
            IO_printf("%d - ",i);
            array[i] = IO_readdouble("");
        }
        IO_println("");

        for(int i = 0; i < qtde; i = i + 1){
            if((array[i] > a && array[i] < b) && array[i] < 6 && IO_par((int)array[i])){
                count = count + 1;
                IO_printf("\n%s%lf%s%lf:%lf%s\n","O valor ",array[i]," pertence ao intervalo  (",a,b,"), é menor do que 6 e sua parte inteira é par");
            }
        }
        IO_printf("\n%s[%d/%d]\n","count: ",count,qtde);
    }
    return "Programa 9";
}

char* p10( bool execute )
{
    if (execute){
        double a = 0.0;
        double b = 0.0;
        int qtde = 0;
        int count = 0;

        do{
            a = IO_readdouble("Digite o valor real do inicio do intervalo: ");
            if(a <= 0 || a >= 1){
                IO_println("(Digite um valor maior do 0 e menor do que 1)");
            }
        }while(a <= 0 || a >= 1);

        do{
            b = IO_readdouble("Digite o valor real do final do intervalo: ");
            if(b <= a || b <= 0 || b >= 1){
                IO_println("(Digite um valor maior do que o inicio do intervalo, maior do que 0 e menor do que 1)");
            }
        }while(b <= a || b <= 0 || b >= 1);

        do{
            qtde = IO_readint("Digite o valor da quantidade: ");
            if(qtde <= 0){
                IO_println("(Digite um valor maior do que 0)");
            }
        }while(qtde <= 0);

        double array[qtde];
        IO_printf("\n%s\n","Digite os valores:");

        for(int i = 0; i < qtde; i = i + 1){
            IO_printf("%d - ",i);
            double num = 0.0;
            num = IO_readdouble("");
            array[i] = num - (int)num;
        }
        IO_println("");

        for(int i = 0; i < qtde; i = i + 1){
            if(array[i] > a && array[i] < b){
                count = count + 1;
                IO_printf("\n%s%lf%s%lf:%lf%s\n","O valor ",array[i]," pertence ao intervalo  (",a,b,")");
            }
        }
        IO_printf("\n%s[%d/%d]\n","count: ",count,qtde);
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