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

        isDecrescent = is_arrayDecrescent(arranjo.valores,arranjo.length);
        index_p5(arranjo, isDecrescent);

        deleteValores(arranjo);
    }
    return "Programa 5";
}

char* p6(bool execute){
    if(execute){
        
    }
    return "Programa 6";
}