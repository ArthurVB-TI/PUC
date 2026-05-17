char* p1(bool execute){
    if(execute){
        Valores* v = createValores();
        Intervalo* i = createIntervalo();
        char* arquivo_nome = "DADOS.TXT";

        colocarValoresAleatorios(v,i->Intervalo_1,i->Intervalo_2);

        index_p1(i,v);
        gravar_p1(arquivo_nome,v);

        deleteValores(v);
        deleteIntervalo(i);
    }
    return "Programa 1";
}

char* p2(bool execute){
    if(execute){
        char* arquivo_nome = "DADOS.TXT";
        Valores* arranjo = createValoresVazio();
        pegarValores(arranjo,arquivo_nome);
        
        Procurados* valoresProcurado = createProcurados();

        updateProcurados_encontrados(valoresProcurado,arranjo);

        index_p2(valoresProcurado,arranjo);

        deleteValores(arranjo);
        deleteProcurados(valoresProcurado);
    }
    return "Programa 2";
}

char* p3(bool execute){
    if(execute){
        char* arquivo1_nome = "DADOS1.TXT";
        char* arquivo2_nome = "DADOS2.TXT";
        bool resposta = false;

        Valores* arranjo1 = createValoresVazio();
        Valores* arranjo2 = createValoresVazio();

        pegarValores(arranjo1,arquivo1_nome);
        pegarValores(arranjo2,arquivo2_nome);

        resposta = arrayCompare(arranjo1,arranjo2);

        index_p3(arranjo1,arranjo2,resposta);

        deleteValores(arranjo1);
        deleteValores(arranjo2);
    }
    return "Programa 3";
}

char* p4(bool execute){
    if(execute){
        const int constante = 3;
        char* arquivo1_nome = "DADOS1.TXT";
        char* arquivo2_nome = "DADOS2.TXT";

        Valores* arranjo1 = createValoresVazio();
        Valores* arranjo2 = createValoresVazio();
        Valores* arranjo3 = createValoresVazio();

        pegarValores(arranjo1,arquivo1_nome);
        pegarValores(arranjo2,arquivo2_nome);

        arrayAdd(arranjo1,arranjo2,arranjo3,constante);

        index_p4(arranjo1,arranjo2,arranjo3,constante);

        deleteValores(arranjo1);
        deleteValores(arranjo2);
    }
    return "Programa 4";
}

char* p5(bool execute){
    if(execute){
        char* arquivo_nome = "DADOS.TXT";
        bool isDecrescent = false;

        Valores* arranjo = createValoresVazio();

        pegarValores(arranjo, arquivo_nome);

        isDecrescent = is_arrayDecrescent(arranjo->valores,arranjo->length);
        index_p5(arranjo, isDecrescent);

        deleteValores(arranjo);
    }
    return "Programa 5";
}

char* p6(bool execute){
    if(execute){
        Matriz* matriz = createMatriz(false);
        Matriz* matrizTransposta = createMatriz(false);

        char* arquivo_nome = "DADOS1.TXT";

        pegarMatriz(matriz,arquivo_nome);
        pegarTransposta(matriz,matrizTransposta);

        index_p6(matriz,matrizTransposta);

        deleteMatriz(matriz);
        deleteMatriz(matrizTransposta);
    }
    return "Programa 6";
}

char* p7(bool execute){
    if(execute){
        Matriz* matriz = createMatriz(false);

        char* arquivo_nome = "DADOS1.TXT";
        bool contemSomenteZero = false;

        pegarMatriz(matriz,arquivo_nome);

        contemSomenteZero = is_matrizZero(matriz);

        index_p7(matriz,contemSomenteZero);

        deleteMatriz(matriz);
    }
    return "Programa 7";
}

char* p8(bool execute){
    if(execute){
        Matriz* matriz1 = createMatriz(false);
        Matriz* matriz2 = createMatriz(false);

        char* arquivo1_nome = "DADOS1.TXT";
        char* arquivo2_nome = "DADOS2.TXT";
        bool is_matrizIgual = false;

        pegarMatriz(matriz1,arquivo1_nome);
        pegarMatriz(matriz2,arquivo2_nome);

        is_matrizIgual = matrizCompare(matriz1,matriz2);

        index_p8(matriz1,matriz2,is_matrizIgual);

        deleteMatriz(matriz1);
        deleteMatriz(matriz2);
    }
    return "Programa 8";
}

char* p9(bool execute){
    if(execute){
        const int constante = 3;

        Matriz* matriz1 = createMatriz(false);
        Matriz* matriz2 = createMatriz(false);
        Matriz* matrizResultante = createMatriz(false);

        char* arquivo1_nome = "DADOS1.TXT";
        char* arquivo2_nome = "DADOS2.TXT";

        pegarMatriz(matriz1,arquivo1_nome);
        pegarMatriz(matriz2,arquivo2_nome);
        pegarResultante(matriz1,matriz2,matrizResultante,constante);

        index_p9(matriz1,matriz2,matrizResultante,constante);

        deleteMatriz(matriz1);
        deleteMatriz(matriz2);
        deleteMatriz(matrizResultante);
    }
    return "Programa 9";
}

char* p10(bool execute){
    if(execute){
        Matriz* matriz1 = createMatriz(false);
        Matriz* matriz2 = createMatriz(false);
        Matriz* matrizResultante = createMatriz(false);

        char* arquivo1_nome = "DADOS1.TXT";
        char* arquivo2_nome = "DADOS2.TXT";

        pegarMatriz(matriz1,arquivo1_nome);
        pegarMatriz(matriz2,arquivo2_nome);
        multiplicacaoDeMatrizes(matriz1,matriz2,matrizResultante);

        index_p10(matriz1,matriz2,matrizResultante);

        deleteMatriz(matriz1);
        deleteMatriz(matriz2);
        deleteMatriz(matrizResultante);
    }
    return "Programa 10";
}
