void m1()
{
    Valores* arranjo = createValoresVazio();
    Valores* arranjoDecrescente = createValoresVazio();

    char* arquivo_nome = "DADOS1.TXT";

    pegarValores(arranjo,arquivo_nome);
    decrescente(arranjo,arranjoDecrescente);

    index_e1(arranjo,arranjoDecrescente);

    deleteValores(arranjo);
    deleteValores(arranjoDecrescente);
}

void m2()
{
    Matriz* matriz1 = createMatriz(false);
    Matriz* matriz2 = createMatriz(false);
    Matriz* matrizResultante = createMatriz(false);

    char* arquivo1_nome = "DADOS1.TXT";
    char* arquivo2_nome = "DADOS2.TXT";
    bool is_matrizIdentidade = false;

    pegarMatriz(matriz1,arquivo1_nome);
    pegarMatriz(matriz2,arquivo2_nome);
    multiplicacaoDeMatrizes(matriz1,matriz2,matrizResultante);

    is_matrizIdentidade = verificarMatrizIdentidade(matrizResultante);

    index_e2(matrizResultante,is_matrizIdentidade);

    deleteMatriz(matriz1);
    deleteMatriz(matriz2);
    deleteMatriz(matrizResultante);
}
