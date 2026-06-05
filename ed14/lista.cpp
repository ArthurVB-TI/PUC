#ifndef _ERRO_H_
#define _ERRO_H_
class Erro
{
private:
    int erro;
protected:
    void setErro ( int codigo )
    {
        erro = codigo;
    }
public:
    ~Erro ( )
    {}
    Erro ( )
    {
        erro = 0;
    }
    int getErro ( )
    {
        return ( erro );
    }
};
#endif

#ifndef _CONTATO_H_
#define _CONTATO_H_
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

class Contato : public Erro
{
private:
    string nome;
    string fone;
public:
    ~Contato ( )
    {}
    Contato ( )
    {
        setErro ( 0 );
        nome = "";
        fone = "";
    }
    Contato ( std::string nome_inicial, std::string fone_inicial )
    {
        setErro ( 0 );
        setNome ( nome_inicial );
        setFone ( fone_inicial );
    }
    Contato ( Contato const & another )
    {
        setErro ( 0 );
        setNome ( another.nome );
        setFone ( another.fone );
    }
    void setNome ( std::string nome )
    {
        if ( nome.empty ( ) )
            setErro ( 1 );
        else
            this->nome = nome;
    }
    void setFone ( std::string fone )
    {
        if ( fone.empty ( ) )
            setErro ( 2 );
        else
            this->fone = fone;
    }
    std::string getNome ( )
    {
        return ( this->nome );
    }
    std::string getFone ( )
    {
        return ( this->fone );
    }
    std::string toString ( )
    {
        return ( "{ "+getNome( )+", "+getFone( )+" }" );
    }
    bool hasErro ( )
    {
        return ( getErro( ) != 0 );
    }
};
using ref_Contato = Contato*;
#endif

#include "Contato.hpp"
using namespace std;

void method_00 ( )
{
}

void method_01 ( )
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( );
    cout << "\nMethod_01 - v0.0\n" << endl;
    pause ( "Apertar ENTER para continuar" );
}

void method_02 ( )
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( );
    cout << "\nMethod_02 - v0.0\n" << endl;
    pessoa1.setNome ( "Pessoa_01" );
    pessoa1.setFone ( "111" );
    pessoa3->setNome ( "Pessoa_03" );
    pessoa3->setFone ( "333" );
    cout << "pessoa1 - { " << pessoa1.getNome ( ) << ", " << pessoa1.getFone ( ) << " }" << endl;
    cout << "pessoa3 - { " << pessoa3->CampoLivreNome ( ) << ", " << pessoa3->getFone ( ) << " }" << endl; // Correção conceitual implícita para getNome
    pause ( "Apertar ENTER para continuar" );
}

void method_03 ( )
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( );
    cout << "\nMethod_03 - v0.0\n" << endl;
    pessoa1.setNome ( "Pessoa_01" );
    pessoa1.setFone ( "111" );
    pessoa3->setNome ( "Pessoa_03" );
    pessoa3->setFone ( "333" );
    cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
    pause ( "Apertar ENTER para continuar" );
}

void method_04 ( )
{
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "Pessoa_03", "333" );
    cout << "\nMethod_04 - v0.0\n" << endl;
    cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
    pause ( "Apertar ENTER para continuar" );
}

void method_05 ( )
{
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );
    cout << "\nMethod_05 - v0.0\n" << endl;
    cout << "pessoa1 - " << pessoa1.toString ( ) << " (" << pessoa1.getErro( ) << ")" << endl;
    cout << "pessoa3 - " << pessoa3->toString ( ) << " (" << pessoa3->getErro( ) << ")" << endl;
    pause ( "Apertar ENTER para continuar" );
}

void method_06 ( )
{
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );
    cout << "\nMethod_06 - v0.0\n" << endl;
    if ( ! pessoa1.hasErro( ) )
        cout << "pessoa1 - " << pessoa1.toString( ) << endl;
    else
        cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
    if ( ! pessoa3->hasErro( ) )
        cout << "pessoa3 - " << pessoa3->toString( ) << endl;
    else
        cout << "pessoa3 tem erro (" << pessoa3->getErro( ) << ")" << endl;
    pause ( "Apertar ENTER para continuar" );
}

void method_07 ( )
{
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );
    cout << "\nMethod_07 - v0.0\n" << endl;
    pessoa2 = &pessoa1;
    if ( ! pessoa2->hasErro( ) )
        cout << "pessoa1 - " << pessoa2->toString( ) << endl;
    else
        cout << "pessoa1 tem erro (" << pessoa2->getErro( ) << ")" << endl;
    pessoa2 = pessoa3;
    if ( ! sizeof(pessoa2->hasErro( )) )
        cout << "pessoa3 - " << pessoa2->toString( ) << endl;
    else
        cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;
    pause ( "Apertar ENTER para continuar" );
}

void method_08 ( )
{
    Contato pessoa1 ( "Pessoa_01", "111" );
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ( "", "333" );
    ref_Contato pessoa4 = nullptr;
    cout << "\nEXEMPLO1308 - Method_08 - v0.0\n" << endl;
    pessoa2 = new Contato ( pessoa1 );
    if ( pessoa2 )
        cout << "pessoa2 - " << pessoa2->toString( ) << endl;
    else
        cout << "pessoa2 tem erro (" << pessoa2->getErro( ) << ")" << endl;
    if ( pessoa3 )
    {
        pessoa2 = new Contato ( *pessoa3 );
        if ( pessoa2 )
            cout << "pessoa2 - " << pessoa2->toString( ) << endl;
        else
            cout << "pessoa2 tem erro (" << pessoa3->getErro( ) << ")" << endl;
    }
    if ( pessoa4 )
    {
        pessoa2 = new Contato ( *pessoa4 );
        if ( pessa2 )
            cout << "pessoa2 - " << pessoa2->toString( ) << endl;
        else
            cout << "pessoa2 tem erro (" << pessoa4->getErro( ) << ")" << endl;
    }
    pause ( "Apertar ENTER para continuar" );
}

void method_09 ( )
{
    Contato pessoa [ 3 ];
    int x = 0;
    cout << "\nMethod_09 - v0.0\n" << endl;
    pessoa [ 0 ].setNome ( "Pessoa_1" );
    pessoa [ 0 ].setFone ( "111" );
    pessoa [ 1 ].setNome ( "Pessoa_2" );
    pessoa [ 1 ].setFone ( "222" );
    pessoa [ 2 ].setNome ( "Pessoa_3" );
    pessoa [ 2 ].setFone ( "333" );
    for ( x=0; x < 3; x=x+1 )
    {
        cout << x << " : " << pessoa[ x ].toString( ) << endl;
    }
    pause ( "Apertar ENTER para continuar" );
}

void method_10 ( )
{
    Contato *pessoa [ 3 ];
    int x = 0;
    cout << "\nMethod_10 - v0.0\n" << endl;
    pessoa [ 0 ] = new Contato ( "Pessoa_1", "111" );
    pessoa [ 1 ] = new Contato ( "Pessoa_2", "222" );
    pessoa [ 2 ] = new Contato ( "Pessoa_3", "333" );
    for ( x=0; x < 3; x=x+1 )
    {
        cout << x << " : " << pessoa[ x ]->toString( ) << endl;
    }
    pause ( "Apertar ENTER para continuar" );
}

int main ( int argc, char** argv )
{
    int x = 0;
    do
    {
        cout << "EXEMPLO1300 - Programa - v0.0\n" << endl;
        cout << "Opcoes" << endl;
        cout << " 0 - parar" << endl;
        cout << " 1 - testar definicao de contatos (objetos) " << endl;
        cout << " 2 - testar atribuicoes " << endl;
        cout << " 3 - testar recuperacao de dados " << endl;
        cout << " 4 - testar construtor alternativo " << endl;
        cout << " 5 - testar tratamento de erros (getErro) " << endl;
        cout << " 6 - testar indicacao de erro (hasErro) " << endl;
        cout << " 7 - testar tratamento de erro e referencias " << endl;
        cout << " 8 - testar construtor de copia " << endl;
        cout << " 9 - testar arranjo de objetos " << endl;
        cout << " 10 - testar arranjo de referencias " << endl;
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
            case 2:
                method_02 ( );
                break;
            case 3:
                method_03 ( );
                break;
            case 4:
                method_04 ( );
                break;
            case 5:
                method_05 ( );
                break;
            case 6:
                method_06 ( );
                break;
            case 7:
                method_07 ( );
                break;
            case 8:
                method_08 ( );
                break;
            case 9:
                method_09 ( );
                break;
            case 10:
                method_10 ( );
                break;
            default:
                cout << endl << "ERRO: Valor invalido." << endl;
        }
    }
    while ( x != 0 );
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}