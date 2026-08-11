/*
 * createProcurados -> criar procurados
 * verificarProcurados -> verificar se está tudo certo com seus procurados
 * updateProcurados_procurados -> atualizar os valores que você está procurando
 * updateProcurados_encontrados -> atualizar os valores que foram encontrados dentro dos valores procurados
 * indexProcurados -> mostrar todos os valores procurados e se foram encontrados
 * deleteProcurados -> deletar tudo
**/

Procurados* createProcurados(){
    Procurados* retorno = (Procurados*) malloc(sizeof(Procurados)*1);

    retorno->valoresProcurados = createValores();
    colocarValores(retorno->valoresProcurados);
    retorno->valoresEncontrados = (bool*) calloc(retorno->valoresProcurados->length, sizeof(bool));

    return retorno;
}

bool verificarProcurados(Procurados* p){
    bool retorno = true;
    if(p != NULL){
        if(verificarValores(p->valoresProcurados)){
            if(p->valoresEncontrados == NULL){
                p->valoresEncontrados = (bool*) malloc(sizeof(bool)*p->valoresProcurados->length);
            }
        } else {
            retorno = false;
        }
    } else {
        IO_printf("Procurados não criados!");
        retorno = false;
    }
    return retorno;
}

void updateProcurados_procurados(Procurados* p){
    bool v = false;
    int valorAtual = 0;

    if(verificarProcurados(p) && verificarValores(p->valoresProcurados)){
        do{
            IO_printf("Digite a quantidade de valores a procurar: ");
            v = scanf("%d",&valorAtual); getchar( );
        }while(!v || valorAtual < 0);
        updateValores_tamanho(p->valoresProcurados,valorAtual);
        colocarValores(p->valoresProcurados);
    } else {
        IO_printf("Não foi possivel atualizar seus procurados");
    }
}

void updateProcurados_encontrados(Procurados* p,Valores* v){
    if(verificarProcurados(p) && verificarValores(v)){
        for(int i = 0; i < v->length; i = i + 1){
            for(int j = 0; j < p->valoresProcurados->length; j = j + 1){
                if(p->valoresProcurados->valores[j] == v->valores[i]){
                    p->valoresEncontrados[j] = true;
                }
            }
        }
        v->index = 0;
        p->valoresProcurados->index = 0;
    } else {
        IO_printf("Não foi possivel atualizar seus encontrados!");
    }
}

void indexProcurados(Procurados* p){
    if(verificarProcurados(p)){
        for(int i = 0; i < p->valoresProcurados->length; i = i + 1){
            IO_printf("%d - %s\n",p->valoresProcurados->valores[i],(p->valoresEncontrados[i] ? "Encontrado" : "Não encontrado"));
        }
        p->valoresProcurados->index = 0;
    } else {
        IO_printf("Não foi possivel mostrar seu procurados!");
    }
}

void deleteProcurados(Procurados* p){
    if(verificarProcurados(p)){
        deleteValores(p->valoresProcurados);
        free(p->valoresEncontrados);
        p->valoresEncontrados = NULL;
        free(p);
        p = NULL;
    } else {
        IO_printf("Seus procurados já estão excluidos!");
    }
}