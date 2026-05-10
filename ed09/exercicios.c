#include "io.h"
#include "update.h"
#include "index.h"

/*
 * Nova função criada na biblioteca (Para ler matrizes):
 *  Linha 303
*/

char* p1(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        IO_indexMatriz(i,j,matriz);
    }
    return "Programa 1";
}

char* p2(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;
        double** matriz_lida;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);
        fprintDoubleMatrix("MATRIX_01.TXT",i,j,matriz);

        matriz_lida = freadDoubleMatrix("MATRIX_01.TXT",&i,&j);
        IO_indexMatriz(i,j,matriz_lida);
        index_p2(i,j,matriz_lida);
    }
    return "Programa 2";
}

char* p3(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p3(i,j,matriz);
    }
    return "Programa 3";
}

char* p4(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p4(i,j,matriz);
    }
    return "Programa 4";
}

char* p5(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p5(i,j,matriz);
    }
    return "Programa 5";
}

char* p6(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p6(i,j,matriz);
    }
    return "Programa 6";
}

char* p7(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p7(i,j,matriz);
    }
    return "Programa 7";
}

char* p8(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p8(i,j,matriz);
    }
    return "Programa 8";
}

char* p9(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p9(i,j,matriz);
    }
    return "Programa 9";
}

char* p10(bool execute)
{
    if(execute){
        int i = 0;
        int j = 0;
        double** matriz;

        IO_lerMatriz(&i,&j);
        matriz = ler_Valores_da_Matriz(i,j);

        index_p10(i,j,matriz);
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