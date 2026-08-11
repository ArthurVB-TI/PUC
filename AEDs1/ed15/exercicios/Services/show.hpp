using namespace std;

void show_pilha ( Pilha &p ) {
    cout << "Tamanho da pilha: " << p.getTamanho ( ) << endl;
    p.show ( );
}

void show_fila ( Fila &f ) {
    cout << "Tamanho da fila: " << f.getTamanho ( ) << endl;
    f.show ( );
}
