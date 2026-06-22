using namespace std;

void e1() {
    Fila fila1;
    Fila fila2;

    cout << "Primeira fila (informe os valores em ordem crescente)" << endl;
    lerFila ( fila1, "Digite os valores da primeira fila" );

    cout << "Segunda fila (informe os valores em ordem crescente)" << endl;
    lerFila ( fila2, "Digite os valores da segunda fila" );

    ref_intQueue resultado = fila1.mergeUp ( fila2.getInicio ( ) );

    cout << endl << "Fila 1 - "; fila1.show ( );
    cout << "Fila 2 - "; fila2.show ( );
    cout << "Fila mesclada (crescente, sem repeticoes) - ";
    show_intQueue ( resultado );

    free_intQueue ( resultado );
}

void e2() {
    Fila fila1;
    Fila fila2;

    cout << "Primeira fila (informe os valores em ordem decrescente)" << endl;
    lerFila ( fila1, "Digite os valores da primeira fila" );

    cout << "Segunda fila (informe os valores em ordem decrescente)" << endl;
    lerFila ( fila2, "Digite os valores da segunda fila" );

    ref_intQueue resultado = fila1.intQueue_mergeDown ( fila2.getInicio ( ) );

    cout << endl << "Fila 1 - "; fila1.show ( );
    cout << "Fila 2 - "; fila2.show ( );
    cout << "Fila mesclada (decrescente, sem repeticoes) - ";
    show_intQueue ( resultado );

    free_intQueue ( resultado );
}
