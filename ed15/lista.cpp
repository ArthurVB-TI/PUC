#include "io.hpp"

using namespace std;

void method_00 ( )
{
}

void method_01 ( )
{
    cout << "\nMethod_01 - v0.0\n" << endl;
    IO_pause ( "Apertar ENTER para continuar" );
}

int main ( int argc, char** argv )
{
    int x = 0;

    do
    {
        cout << "EXEMPLO1500 - Programa - v0.0\n" << endl;
        cout << "Opcoes" << endl;
        cout << " 0 - parar" << endl;
        cout << " 1 - testar definicoes" << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        switch ( x )
        {
            case 0:
                method_00 ( );
                break;
            case 1:
                method_01 ( );
                break;
            default:
                cout << endl << "ERRO: Valor invalido." << endl;
        }
    }
    while ( x != 0 );

    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}
