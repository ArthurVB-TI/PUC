namespace std;

void m1(){
    matriz<int>* Matriz = new matriz<int>();
    string arquivo_nome = "MATRIZ1.TXT";
    
    Matriz->setMatrizLength();
    Matriz->setRandomMatriz();

    index_m1(Matriz);
    gravar_m1(Matriz,arquivo_nome);
}