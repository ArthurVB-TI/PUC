#include <iostream>
using std::cin ;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

void pause ( std::string text )
{
    std::string dummy;
    std::cin.clear ( );
    std::cout << std::endl << text;
    std::cin.ignore( );
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

#include "Erro.hpp"

class MyString : public Erro
{
public:
    std::string getErroMsg ( )
    {
        if ( !hasError ( ) )
            return ( NO_ERROR );
        return ( "[ERRO] Erro desconhecido." );
    }
};

using namespace std;

void method_00 ( )
{
}

void method_01 ( )
{
    MyString *s = new MyString ( );

    cout << "\nMethod_01 - v0.1\n" << endl;
    cout << "Codigo de erro : " << s->getErro    ( ) << endl;
    cout << "Tem erro?      : " << (s->hasError  ( ) ? "sim" : "nao") << endl;
    cout << "Mensagem       : " << s->getErroMsg ( ) << endl;

    delete s;

    pause ( "Apertar ENTER para continuar" );
}

int main ( int argc, char** argv )
{
    int x = 0;

    do
    {
        cout << "EXEMPLO1400 - Programa - v0.1\n " << endl;
        cout << "Opcoes "     << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - testar definicoes " << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin  >> x;

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

    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}
