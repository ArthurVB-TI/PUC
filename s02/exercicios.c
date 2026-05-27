#include "io.h"
#include "pares.h"
#include "array.h"

void method_01(){
    pares* par = createPares();
    char* arquivo_nome1 = "DADOS_1.TXT";
    char* arquivo_nome2 = "SAIDA_1.TXT";
    int n = 0;

    n = IO_readint("Digite uma quantidade: ");
    updatePares(par,n);

    randomPares(par);
    updateDistancia(par);

    indexPares(par);
    indexParesDistancia(par);

    gravarPares(par,arquivo_nome1);
    gravarDistancias(par, arquivo_nome2);

    deletePares(par);
}

void method_02(){
    array* arranjo = createArray();
    char* arquivo_nome = "SAIDA_1.TXT";

    getArray(arranjo,arquivo_nome);
}

void method_03(){

}

void method_04(){

}

void method_05(){

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
