using namespace std;

void show_intQueue ( ref_intQueue inicio ) {
    ref_intQueue atual = inicio;

    if ( atual == NULL ) {
        cout << "(vazia)" << endl;
        return;
    }

    while ( atual != NULL ) {
        cout << atual->value;
        if ( atual->next != NULL ) cout << " -> ";
        atual = atual->next;
    }
    cout << endl;
}

void free_intQueue ( ref_intQueue inicio ) {
    ref_intQueue atual = inicio;

    while ( atual != NULL ) {
        ref_intQueue proximo = atual->next;
        delete atual;
        atual = proximo;
    }
}
