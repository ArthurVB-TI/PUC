#include "io.hpp"
#include "extras/routes.hpp"

using namespace std;

int main()
{
    int opcoes = 0;

    IO_id("Extras");
    do{
        cout << endl << "Opções: " << endl; 
        cout << "0 - Sair " << endl;
        cout << "1 - Metodo 1: " << endl;
        cout << "2 - Metodo 2: " << endl;

        opcoes = IO_readOpcao();
        switch(opcoes)
        {
            case 0: break;
            case 1: cout << endl; e1(); break;
            case 2: cout << endl; e2(); break;
            default: cout << "Opção inválida!" << endl; break;
        }
    }while(opcoes != 0);

    return 0;
}