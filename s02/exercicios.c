#include "io.h"
#include "pares.h"
#include "array.h"
#include "logic.h"

void method_01(){
    pares* par = createPares();
    char* arquivo_nome1 = "DADOS_1.TXT";
    char* arquivo_nome2 = "SAIDA_1.TXT";

    lerParesDeArquivo(par, arquivo_nome1);
    calcularDistanciasConsecutivas(par);

    indexPares(par);
    for(int i = 0; i < par->length - 1; i = i + 1){
        IO_printf("dist(%d,%d): %lf\n", i, i+1, par->distancia[i]);
    }

    gravarDistanciasConsecutivas(par, arquivo_nome2);
    deletePares(par);
}

void method_02(){
    array* arranjo = createArray();
    char* arquivo_nome = "SAIDA_1.TXT";
    double maior = 0.0;
    double menor = 0.0;

    getArray(arranjo, arquivo_nome);
    maior = getMaior(arranjo);
    menor = getMenor(arranjo);

    index_m2(arranjo, maior, menor);
    deleteArray(arranjo);
}

void method_03(){
    array* arranjo = createArray();
    char* arquivo_nome = "SAIDA_1.TXT";
    double media = 0.0;

    getArray(arranjo, arquivo_nome);
    media = getMediaSemExtremos(arranjo);

    index_m3(arranjo, media);
    deleteArray(arranjo);
}

void method_04(){
    matrizPares* m = createMatrizPares();
    char* arquivo_nome = "DADOS_1.TXT";

    lerMatrizParesDeArquivo(m, arquivo_nome);
    IO_printf("Antes da ordenacao:\n");
    indexMatrizPares(m);

    ordenarMatrizPares(m);
    IO_printf("\nApos a ordenacao:\n");
    indexMatrizPares(m);

    deleteMatrizPares(m);
}

void method_05(){
    matrizPares* m = createMatrizPares();
    char* arquivo_nome = "DADOS_1.TXT";

    lerMatrizParesDeArquivo(m, arquivo_nome);
    ordenarMatrizPares(m);
    indexMatrizPares(m);

    double dist = distanciaPrimeiroUltimo(m);
    IO_printf("\nDistancia entre primeiro e ultimo par ordenados: %lf\n", dist);

    deleteMatrizPares(m);
}

int main ( int argc, char* argv [ ] )
{
    int opcao = 0;

    printf ( "%s\n", "Exemplo0100 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Arthur Victor Alves" );
    printf ( "\n" );

    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
        printf ( "\n%s" , "2 - Method_02" );
        printf ( "\n%s" , "3 - Method_03" );
        printf ( "\n%s" , "4 - Method_04" );
        printf ( "\n%s" , "5 - Method_05" );
        printf ( "\n" );

        printf ( "\n%s", "Opcao = " );
        scanf ( "%d", &opcao ); getchar( );

        IO_println ("");

        switch ( opcao )
        {
            case 0: break;
            case 1: method_01 ( ); break;
            case 2: method_02 ( ); break;
            case 3: method_03 ( ); break;
            case 4: method_04 ( ); break;
            case 5: method_05 ( ); break;
            default:
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        }
    }
    while ( opcao != 0 );

    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return ( 0 );
}
