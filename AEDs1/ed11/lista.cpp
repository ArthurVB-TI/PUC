#include <iostream>
#include <limits>
#include <string>

using namespace std;

void pause ( string text )
{
    string dummy;

    cin.clear ( );

    cout << endl << text;

    cin.ignore ( );

    getline ( cin, dummy );

    cout << endl << endl;
}

#include "myarray.hpp"

void method_00 ( )
{
}

void method_01 ( )
{
    Array<int> int_array ( 5, 0 );

    int_array.set ( 0, 1 );
    int_array.set ( 1, 2 );
    int_array.set ( 2, 3 );
    int_array.set ( 3, 4 );
    int_array.set ( 4, 5 );

    cout << "\nMethod_01 - v0.0\n" << endl;

    int_array.print ( );

    int_array.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_02 ( )
{
    Array<int> int_array ( 5, 0 );

    cout << endl << "Method_02 - v0.0" << endl;

    int_array.read ( );

    int_array.print ( );

    int_array.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_03 ( )
{
    Array<int> int_array ( 5, 0 );

    cout << endl << "Method_03 - v0.0" << endl;

    int_array.read ( );

    int_array.fprint ( "INT_ARRAY1.TXT" );

    int_array.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_04 ( )
{
    Array<int> int_array ( 5, 0 );

    cout << endl << "Method_04 - v0.0" << endl;

    int_array.fread ( "INT_ARRAY1.TXT" );

    int_array.print ( );

    int_array.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_05 ( )
{
    int other [ ] = { 1, 2, 3, 4, 5 };

    Array<int> int_array ( 5, other );

    cout << endl << "Method_05 - v0.0" << endl;

    cout << "\nCopia\n" << endl;

    int_array.print ( );

    int_array.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_06 ( )
{
    Array<int> int_array1 ( 1, 0 );

    cout << endl << "Method_06 - v0.0" << endl;

    int_array1.fread ( "INT_ARRAY1.TXT" );

    cout << "\nOriginal\n" << endl;

    int_array1.print ( );

    Array<int> int_array2 ( int_array1 );

    cout << "\nCopia\n" << endl;

    int_array2.print ( );

    int_array1.free ( );
    int_array2.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_07 ( )
{
    Array<int> int_array1 ( 1, 0 );
    Array<int> int_array2 ( 1, 0 );

    cout << endl << "Method_07 - v0.0" << endl;

    int_array1.fread ( "INT_ARRAY1.TXT" );

    cout << "\nOriginal\n" << endl;

    int_array1.print ( );

    int_array2 = int_array1;

    cout << "\nCopia\n" << endl;

    int_array2.print ( );

    int_array1.free ( );
    int_array2.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_08 ( )
{
    int other [ ] = { 1, 2, 3 };

    Array<int> int_array1 ( 3, other );
    Array<int> int_array2 ( 3, other );

    cout << endl << "Method_08 - v0.0" << endl;

    cout << endl;

    cout << "Array_1";

    int_array1.print ( );

    cout << "Array_2";

    int_array2.print ( );

    cout << "Igualdade = "
         << ( int_array1 == int_array2 )
         << endl;

    int_array2.set ( 0, (-1) );

    cout << endl;

    cout << "Array_1" << endl;

    int_array1.print ( );

    cout << "Array_2" << endl;

    int_array2.print ( );

    cout << "Igualdade = "
         << ( int_array1 == int_array2 )
         << endl;

    int_array1.free ( );
    int_array2.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_09 ( )
{
    Array<int> int_array1 ( 1, 0 );
    Array<int> int_array2 ( 1, 0 );
    Array<int> int_array3 ( 1, 0 );

    cout << endl
         << "EXEMPLO1110 - Method_09 - v0.0"
         << endl;

    int_array1.fread ( "INT_ARRAY1.TXT" );

    int_array2 = int_array1;

    int_array3 = int_array2 + int_array1;

    cout << endl;

    cout << "Original" << endl;

    int_array1.print ( );

    cout << "Copia" << endl;

    int_array2.print ( );

    cout << "Soma" << endl;

    int_array3.print ( );

    int_array1.free ( );
    int_array2.free ( );
    int_array3.free ( );

    pause ( "Apertar ENTER para continuar" );
}

void method_10 ( )
{
    int other [ ] = { 1, 2, 3, 4, 5 };

    Array<int> int_array ( 5, other );

    int x;

    cout << endl << "Method_10 - v0.0" << endl;

    cout << "\nAcesso externo" << endl;

    for ( x = 0; x < int_array.getLength ( ); x = x + 1 )
    {
        cout << endl
             << setw ( 3 )
             << x
             << " : "
             << int_array [ x ];
    }

    cout << endl << "\nFora dos limites:";

    cout << endl
         << "[-1]: "
         << int_array.get ( -1 )
         << endl;

    cout << endl
         << "["
         << int_array.getLength ( )
         << "]: "
         << int_array [ int_array.getLength ( ) ]
         << endl;

    int_array.free ( );

    pause ( "Apertar ENTER para continuar" );
}

int main ( int argc, char** argv )
{
    int x = 0;

    do
    {
        cout << "EXEMPLO1101 - Programa - v0.0\n"
             << endl;

        cout << "Opcoes\n" << endl;

        cout << " 0 - parar\n" << endl;
        cout << " 1 - mostrar dados inteiros em arranjo" << endl;
        cout << " 2 - ler dados para arranjo" << endl;
        cout << " 3 - gravar dados em arquivo" << endl;
        cout << " 4 - ler dados de arquivo" << endl;
        cout << " 5 - copiar arranjo comum" << endl;
        cout << " 6 - copiar objeto arranjo" << endl;
        cout << " 7 - operador de atribuicao" << endl;
        cout << " 8 - comparar arranjos" << endl;
        cout << " 9 - somar arranjos" << endl;
        cout << "10 - acessar posicoes externamente" << endl;

        cout << endl
             << "Entrar com uma opcao: ";

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
                cout << endl
                     << "ERRO: Valor invalido."
                     << endl;
        }

    } while ( x != 0 );

    pause ( "Apertar ENTER para terminar" );

    return ( 0 );
}