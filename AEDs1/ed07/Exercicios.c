#include "io.h"

void gravar_multiplos_de_5(int qtde, FILE* arquivo){
    if(qtde > 0){
        gravar_multiplos_de_5(qtde-1, arquivo);
        fprintf(arquivo,"%d\n",qtde*5);
    }
}

void gravar_multiplos_de_3(int qtde, FILE* arquivo){
    if(qtde > 0){
        fprintf(arquivo,"%d\n",(qtde+1) * 3);
        gravar_multiplos_de_3(qtde-1, arquivo);
    }
}

void gravar_potencias_de_3(int qtde, FILE* arquivo){
    if(qtde > 0){
        gravar_potencias_de_3(qtde-1, arquivo);
        fprintf(arquivo,"%lf\n",pow(3.0,qtde-1));
    }
}

void gravar_inversas_de_5(int qtde, FILE* arquivo){
    if(qtde > 0){
        fprintf(arquivo,"%lf\n",1/pow(5,qtde-1));
        gravar_inversas_de_5(qtde-1, arquivo);
    }
}

void gravar_inversas_de_X(int qtde, double valor, FILE* arquivo){
    if(qtde > 0){
        if(qtde > 1){
            fprintf(arquivo,"%lf\n",1/pow(valor,(qtde*2)-1));
        } else {
            fprintf(arquivo,"%d\n",1);
        }
        gravar_inversas_de_X(qtde-1, valor, arquivo);
    }
}

double Ler_Valores(chars fileRead){
    double resultado = 0.0;
    chars valorAtual = IO_new_chars(100);
    FILE* arquivo = fopen(fileRead,"rt");
    while(!feof(arquivo) && fgets(valorAtual,sizeof(valorAtual),arquivo)){
        resultado = resultado + atof(valorAtual);
    }
    fclose(arquivo);
    return resultado;
}

int fibonacci(int qtde)
{
    int resultado = 0;
    if(qtde > 0){
        if(qtde == 1 || qtde == 2){
            return 1;
        }
        else{
            resultado = fibonacci(qtde-1) + fibonacci(qtde-2);
        }
    }
    return resultado;
}

int contarMaiusculas(chars palavra, int i)
{
    int resultado = 0;
    int count = 0;
    if(i < strlen(palavra)){
        if(palavra[i] >= 'A' && palavra[i] <= 'Z'){
            count = 1;
        }
        resultado = contarMaiusculas(palavra, i + 1) + count;
    }
    return resultado;
}

char* p1(bool execute)
{
    if(execute){
        int x = 0;
        FILE* arquivo = fopen("dados1.txt", "wt");
        x = IO_readint("Escreva uma quantidade: ");
        gravar_multiplos_de_5(x, arquivo);
        fclose(arquivo);
    }
    return "Programa 1";
}

char* p2(bool execute)
{
    if(execute){
        int x = 0;
        FILE* arquivo = fopen("dados2.txt", "wt");
        x = IO_readint("Escreva uma quantidade: ");
        gravar_multiplos_de_3(x, arquivo);
        fclose(arquivo);
    }
    return "Programa 2";
}

char* p3(bool execute)
{
    if(execute){
        int x = 0;
        FILE* arquivo = fopen("dados3.txt", "wt");
        x = IO_readint("Escreva uma quantidade: ");
        gravar_potencias_de_3(x, arquivo);
        fclose(arquivo);
    }
    return "Programa 3";
}

char* p4(bool execute)
{
    if(execute){
        int x = 0;
        FILE* arquivo = fopen("dados4.txt", "wt");
        x = IO_readint("Escreva uma quantidade: ");
        gravar_inversas_de_5(x, arquivo);
        fclose(arquivo);
    }
    return "Programa 4";
}

char* p5(bool execute)
{
    if(execute){
        int x = 0;
        double y = 0;
        FILE* arquivo = fopen("dados5.txt", "wt");
        x = IO_readint("Escreva uma quantidade: ");
        y = IO_readint("Escreva um valor real: ");
        gravar_inversas_de_X(x, y, arquivo);
        fclose(arquivo);
    }
    return "Programa 5";
}

char* p6(bool execute)
{
    if(execute){
        chars read_arquivo = "dados5.txt";
        FILE* arquivo = fopen("dados6.txt", "at");
        int qtde = 0;
        double resultado = 0.0;

        qtde = IO_readint("Escreva uma quantidade: ");
        resultado = Ler_Valores(read_arquivo);
        fprintf(arquivo,"%lf\n",resultado);
        fclose(arquivo);
    }
    return "Programa 6";
}

char* p7(bool execute)
{
    if(execute){
        chars read_arquivo = "dados4.txt";
        FILE* arquivo = fopen("dados7.txt", "at");
        int qtde = 0;
        double resultado = 0.0;

        qtde = IO_readint("Escreva uma quantidade: ");
        resultado = Ler_Valores(read_arquivo);
        fprintf(arquivo,"%lf\n",resultado);
        fclose(arquivo);
    }
    return "Programa 7";
}

char* p8(bool execute)
{
    if(execute){
        int fibonacci_number = 0;
        int qtde = 0;
        int count = 0;
        int fibonacci_count = 0;
        FILE* arquivo = fopen("dados8.txt","wt");

        qtde = IO_readint("Escreva uma quantidade: ");

        do{
            fibonacci_number = fibonacci(fibonacci_count);
            if(fibonacci_number % 2 == 0 && fibonacci_number != 0){
                count = count + 1;
                fprintf(arquivo,"%d\n",fibonacci_number);
            }
            fibonacci_count = fibonacci_count + 1;
        }while(count < qtde);

        fclose(arquivo);
    }
    return "Programa 8";
}

char* p9(bool execute)
{
    if(execute){
        chars palavra = IO_new_chars(STR_SIZE);
        FILE* arquivo = fopen("dados9.txt","at");
        int resultado = 0;

        IO_flush();
        palavra = IO_readln("Escreva um texto: ");
        resultado = contarMaiusculas(palavra,0);

        fprintf(arquivo,"%s: Quantidade de Maiusculas - %d\n\n",palavra,resultado);
        fclose(arquivo);
    }
    return "Programa 9";
}

char* p10(bool execute)
{
    if(execute){
        chars palavra = IO_new_chars(STR_SIZE);
        FILE* arquivo = fopen("dados10.txt","at");
        int resultado = 0;
        int count = 0;

        IO_flush();
        palavra = IO_readln("Escreva um texto: ");
        fprintf(arquivo,"%s: \n",palavra);

        for(int i = 0; i < strlen(palavra); i = i + 1){
            if(palavra[i] >= '3' && palavra[i] <= '9'){
                fprintf(arquivo,"\t[%d] - %c\n",i,palavra[i]);
                count = count + 1;
            }
        }
        fprintf(arquivo,"count - %d\n\n",count);
        
        fclose(arquivo);
    }
    return "Programa 10";
}

int main()
{
    IO_id("Exercicios");
    Metodo metodos[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    IO_execute(10,metodos);
    return 0;
}