using namespace std;

const int SENTINELA = -9999;

void lerFila ( Fila &f, string mensagem ) {
    int valor = 0;

    cout << endl << mensagem << " (digite " << SENTINELA << " para terminar):" << endl;
    do {
        valor = IO_readint ( "Valor: " );
        if ( valor != SENTINELA ) f.push ( valor );
    } while ( valor != SENTINELA );
}
