#include "io.hpp"
#include "exercicios/routes.hpp"

using namespace std;

int main()
{
    int opcoes = 0;

    IO_id("Exercicios");
    do{
        cout << endl << "Opções: " << endl;
        cout << "0  - Sair" << endl;
        cout << "1  - getInt" << endl;
        cout << "2  - getDouble" << endl;
        cout << "3  - getBoolean" << endl;
        cout << "4  - contains" << endl;
        cout << "5  - toUpperCase" << endl;
        cout << "6  - toLowerCase" << endl;
        cout << "7  - replace" << endl;
        cout << "8  - encrypt" << endl;
        cout << "9  - decrypt" << endl;
        cout << "10 - split (espacos)" << endl;
        cout << "11 - split (delimitador)" << endl;
        cout << "12 - invertido" << endl;

        opcoes = IO_readint("Digite sua opção: ");
        switch(opcoes)
        {
            case 0:  break;
            case 1:  cout << endl; m1();  break;
            case 2:  cout << endl; m2();  break;
            case 3:  cout << endl; m3();  break;
            case 4:  cout << endl; m4();  break;
            case 5:  cout << endl; m5();  break;
            case 6:  cout << endl; m6();  break;
            case 7:  cout << endl; m7();  break;
            case 8:  cout << endl; m8();  break;
            case 9:  cout << endl; m9();  break;
            case 10: cout << endl; m10(); break;
            case 11: cout << endl; mE1(); break;
            case 12: cout << endl; mE2(); break;
            default: cout << "Opção inválida!" << endl; break;
        }
    }while(opcoes != 0);

    return 0;
}
