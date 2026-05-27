using namespace std;

void m1(){
    matriz<int>* Matriz = new matriz<int>();
    string arquivo_nome = "DADOS.TXT";
    
    Matriz->setMatrizLength();
    Matriz->setRandomMatriz();

    index_m1(Matriz);
    gravar_m1(Matriz,arquivo_nome);
}

void m2(){
    matriz<int>* Matriz = new matriz<int>();
    matriz<int>* Matriz_Resultante = new matriz<int>();

    const int constante = 3;
    string arquivo_nome = "DADOS.TXT";

    Matriz->fgetMatriz(arquivo_nome);
    scalar(Matriz,Matriz_Resultante,constante);
    
    index_m2(Matriz,Matriz_Resultante,constante);
}

void m3(){
    matriz<int>* Matriz = new matriz<int>();

    bool isIdentidade = false;
    string arquivo_nome = "DADOS.TXT";

    Matriz->fgetMatriz(arquivo_nome);
    isIdentidade = identidade(Matriz);

    index_m3(Matriz,isIdentidade);
}

void m4(){
    matriz<int>* Matriz1 = new matriz<int>();
    matriz<int>* Matriz2 = new matriz<int>();

    bool isIdentica = false;
    string arquivo_nome1 = "DADOS1.TXT";
    string arquivo_nome2 = "DADOS2.TXT";

    gerar_dados_m4(arquivo_nome1, arquivo_nome2);

    Matriz1->fgetMatriz(arquivo_nome1);
    Matriz2->fgetMatriz(arquivo_nome2);

    isIdentica = identica(Matriz1,Matriz2);

    index_m4(Matriz1, Matriz2, isIdentica);
}

void m5(){
    matriz<int>* Matriz1 = new matriz<int>();
    matriz<int>* Matriz2 = new matriz<int>();
    matriz<int>* Matriz3 = new matriz<int>();

    bool isIdentica = false;
    string arquivo_nome1 = "DADOS1.TXT";
    string arquivo_nome2 = "DADOS2.TXT";

    gerar_dados_m4(arquivo_nome1, arquivo_nome2);

    Matriz1->fgetMatriz(arquivo_nome1);
    Matriz2->fgetMatriz(arquivo_nome2);

    somaDeMatrizes(Matriz1,Matriz2,Matriz3);

    index_m5(Matriz1, Matriz2, Matriz3);
}

void m6(){
    matriz<int>* Matriz = new matriz<int>();

    const int constante = -1;
    string arquivo_nome = "DADOS.TXT";

    Matriz->fgetMatriz(arquivo_nome);
    Matriz->addRows(1,2,constante);

    index_m6(Matriz);
}

void m7(){
    matriz<int>* Matriz = new matriz<int>();

    const int constante = -1;
    string arquivo_nome = "DADOS.TXT";

    Matriz->fgetMatriz(arquivo_nome);
    Matriz->subtractRows(1,2,constante);

    index_m7(Matriz);
}

void m8(){
    matriz<int>* Matriz = new matriz<int>();

    const int valorProcurado = 3;
    bool isExistente = false;
    int n = 0;
    string arquivo_nome = "DADOS.TXT";

    Matriz->fgetMatriz(arquivo_nome);
    isExistente = Matriz->searchRow(valorProcurado,&n);

    index_m8(Matriz,valorProcurado,isExistente,n);
}

void m9(){
    matriz<int>* Matriz = new matriz<int>();

    const int valorProcurado = 3;
    bool isExistente = false;
    int n = 0;
    string arquivo_nome = "DADOS.TXT";

    Matriz->fgetMatriz(arquivo_nome);
    isExistente = Matriz->searchColumn(valorProcurado,&n);

    index_m9(Matriz,valorProcurado,isExistente,n);
}

void m10(){
    matriz<int>* Matriz = new matriz<int>();
    string arquivo_nome = "DADOS.TXT";

    Matriz->fgetMatriz(arquivo_nome);
    Matriz->transposta();

    index_m10(Matriz);
}