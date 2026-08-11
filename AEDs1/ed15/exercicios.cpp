#include "io.hpp"
#include "exercicios/routes.hpp"

using namespace std;

int main() {
    int opcoes = 0;

    IO_id("Exercicios");
    do {
        cout << endl << "Opções: " << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Pilha: push (inserir no topo)" << endl;
        cout << "2 - Pilha: pop (remover do topo)" << endl;
        cout << "3 - Pilha: dup (duplicar o topo)" << endl;
        cout << "4 - Pilha: swap (trocar os 2 primeiros)" << endl;
        cout << "5 - Pilha: invert(inverter a pilha)" << endl;
        cout << "6 - Fila : push (inserir no final)" << endl;
        cout << "7 - Fila : pop (remover do inicio)" << endl;
        cout << "8 - Fila : compare (comparar duas filas)" << endl;
        cout << "9 - Fila : join (unir duas filas)" << endl;
        cout << "10 - Fila : search (procurar um valor)" << endl;

        opcoes = IO_readint("Digite sua opção: ");
        switch(opcoes) {
            case 0: break;
            case 1: cout << endl; m1(); break;
            case 2: cout << endl; m2(); break;
            case 3: cout << endl; m3(); break;
            case 4: cout << endl; m4(); break;
            case 5: cout << endl; m5(); break;
            case 6: cout << endl; m6(); break;
            case 7: cout << endl; m7(); break;
            case 8: cout << endl; m8(); break;
            case 9: cout << endl; m9(); break;
            case 10: cout << endl; m10(); break;
            default: cout << "Opção inválida!" << endl; break;
        }
    } while(opcoes != 0);

    return 0;
}
