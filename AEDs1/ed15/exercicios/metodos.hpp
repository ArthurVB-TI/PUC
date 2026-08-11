using namespace std;

Pilha pilha;
Fila fila;

void m1() {
    int valor = IO_readint ( "Digite o valor a inserir no topo da pilha: " );

    pilha.push ( valor );
    show_pilha ( pilha );
}

void m2() {
    if ( pilha.getTamanho ( ) == 0 ) {
        cout << "ERRO: a pilha esta vazia, nao ha valor para remover." << endl;
        return;
    }

    int valor = pilha.getTopo ( )->value;
    pilha.pop ( );

    cout << "Valor removido do topo: " << valor << endl;
    show_pilha ( pilha );
}

void m3() {
    if ( pilha.getTamanho ( ) == 0 ) {
        cout << "ERRO: a pilha esta vazia, nao ha valor para duplicar." << endl;
        return;
    }

    pilha.dup ( );
    show_pilha ( pilha );
}

void m4() {
    if ( pilha.getTamanho ( ) < 2 ) {
        cout << "ERRO: e necessario pelo menos dois valores na pilha para trocar." << endl;
        return;
    }

    pilha.swap ( );
    show_pilha ( pilha );
}

void m5() {
    if ( pilha.getTamanho ( ) < 2 ) {
        cout << "ERRO: e necessario pelo menos dois valores na pilha para inverter." << endl;
        return;
    }

    pilha.invert ( );
    show_pilha ( pilha );
}

void m6() {
    int valor = IO_readint ( "Digite o valor a inserir no final da fila: " );

    fila.push ( valor );
    show_fila ( fila );
}

void m7() {
    if ( fila.getTamanho ( ) == 0 ) {
        cout << "ERRO: a fila esta vazia, nao ha valor para remover." << endl;
        return;
    }

    int valor = fila.getInicio ( )->value;
    fila.pop ( );

    cout << "Valor removido do inicio: " << valor << endl;
    show_fila ( fila );
}

void m8() {
    Fila outra;
    lerFila ( outra, "Digite os valores da segunda fila" );

    int resultado = fila.compare ( outra.getInicio ( ) );

    cout << endl << "Fila 1 - "; fila.show ( );
    cout << "Fila 2 - "; outra.show ( );

    if ( resultado == 0 )
        cout << "Resultado: " << resultado << " (as filas sao iguais)" << endl;
    else {
        if( resultado < 0 )
            cout << "Resultado: " << resultado << " (a primeira fila e menor)" << endl;
        else
            cout << "Resultado: " << resultado << " (a primeira fila e maior)" << endl;
    }
}

void m9() {
    Fila outra;
    lerFila ( outra, "Digite os valores da fila a ser unida ao final" );

    fila.join ( outra.getInicio ( ) );
    show_fila ( fila );
}

void m10() {
    int valor = IO_readint ( "Digite o valor a procurar na fila: " );
    int resultado = fila.search ( valor );

    if ( resultado == 1 )
        cout << "Valor " << valor << " ENCONTRADO na fila." << endl;
    else
        cout << "Valor " << valor << " NAO encontrado na fila." << endl;
}
