#include "io.hpp"
#include "exercicios/routes.hpp"

using namespace std;

int main()
{
    int opcoes = 0;

    IO_id("Exercicios");
    do{
        cout << endl << "Opções: " << endl; 
        cout << "0 - Sair " << endl;
        cout << "1 - Metodo 1: " << endl; 
        cout << "2 - Metodo 2: " << endl; 
        cout << "3 - Metodo 3: " << endl;
        cout << "4 - Metodo 4: " << endl;
        cout << "5 - Metodo 5: " << endl;
        cout << "6 - Metodo 6: " << endl;
        cout << "7 - Metodo 7: " << endl;
        cout << "8 - Metodo 8: " << endl;
        cout << "9 - Metodo 9: " << endl;
        cout << "10 - Metodo 10: " << endl;

        opcoes = IO_readint("Digite sua opção: ");
        switch(opcoes)
        {
            case 0: break;
            case 1: cout << endl; m1(); break;
            case 2: cout << endl; m2(); break;
            case 3: cout << endl; m3(); break;
            case 4: cout << endl; m4(); break;
            //case 5: cout << endl; m5(); break;
            //case 6: cout << endl; m6(); break;
            //case 7: cout << endl; m7(); break;
            //case 8: cout << endl; m8(); break;
            //case 9: cout << endl; m9(); break;
            //case 10: cout << endl; m10(); break;
            default: cout << "Opção inválida!" << endl; break;
        }
    }while(opcoes != 0);

    return 0;
}