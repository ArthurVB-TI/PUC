/*
 * lerQuantidade -> retornar uma quantidade natural
 * createValores -> criar valores pedindo a quantidade ao usuario
 * createValoresVazio -> criar valores sem quantidade inicial
 * verificarValores -> verificar se está tudo certo com seus valores
 * valoresIniciais -> atribuir valor inicial a seus valores
 * updateValores_valor -> atualizar um valor especifico
 * updateValores_tamanho -> atualizar seu tamanho
 * colocarValores -> preencher os valores manualmente pelo teclado
 * colocarValoresAleatorios -> preencher os valores com numeros aleatorios dentro de um intervalo
 * pegarValores -> ler os valores de um arquivo
 * indexValores -> mostrar todos os valores
 * deleteValores -> deletar os valores
**/

int lerQuantidade(){
    bool v = false;
    int tamanho = 0;

    do{
        IO_printf("Digite a quantidade de valores: ");
        v = scanf("%d",&tamanho); getchar( );
        if(!v){ IO_printf("Valor invalido!"); }
        else{ if(tamanho <= 0){ IO_printf("Digite um valor maior que 0!"); } }
    }while(!v || tamanho <= 0);

    return tamanho;
}

Valores* createValores(){
    Valores* retorno = (Valores*) malloc(sizeof(Valores)*1);
    int tamanho = lerQuantidade();
    
    if(tamanho > 0){
        retorno->length = tamanho;
        retorno->index = 0;
        retorno->valores = (int*) malloc(sizeof(int)*tamanho);
    } else {
        retorno = NULL;
    }
    return retorno;
}

Valores* createValoresVazio(){
    Valores* retorno = (Valores*) malloc(sizeof(Valores)*1);
    retorno->length = 0;
    retorno->index = 0;
    retorno->valores = NULL;
    return retorno;
}

bool verificarValores(Valores* v){
    bool retorno = true;
    bool verify = false;
    int valorAtual = 0;

    if(v != NULL){
        if(v->length <= 0){
            v->valores = NULL;
        } else {
            if(v->valores == NULL){
                v->valores = (int*) malloc(sizeof(int)*v->length);
            }
        }
    } else {
        IO_printf("Valores não criado!");
        retorno = false;
    }
    return retorno;
}

void valoresIniciais(Valores* v,int valorInicial){
    if(verificarValores(v)){
        v->index = 0;
        while(v->index < v->length){
            v->valores[v->index] = valorInicial;
            v->index = v->index + 1;
        }
        v->index = 0;
    } else {
        IO_printf("Não foi possivel Iniciar seus valores!");
    }
}

void updateValores_valor(Valores* v,int valor,int indice){
    if(verificarValores(v)){
        if(indice >= 0 && indice < v->length){
            v->valores[indice] = valor;
        } else {
            IO_printf("Indice precisa estar entre [%d,%d]!",0,v->length - 1);
        }
    } else {
        IO_printf("Não foi possivel atualizar seu valores!");
    }
}

void colocarValores(Valores* v){
    bool verify = false;
    int valorAtual = 0;

    if(verificarValores(v)){
        for(int i = 0; i < v->length; i = i + 1){
            do{
                IO_printf("Digite o valor [%d]: ",i);
                verify = scanf("%d",&valorAtual); getchar( );
                if(!verify){ IO_printf("Valor invalido!"); }
            }while(!verify);
            updateValores_valor(v,valorAtual,i);
        }
    }
}

void colocarValoresAleatorios(Valores* v,int min,int max){
    int valorAtual = 0;

    if(verificarValores(v)){
        for(int i = 0; i < v->length; i = i + 1){
            valorAtual = IO_random(min,max);
            updateValores_valor(v,valorAtual,i);
        }
    }
}

void updateValores_tamanho(Valores* v,int tamanho){
    int* newArranjo;
    int valorAtual = 0;
    bool verify = false;
    if(v != NULL){
        if(tamanho > 0){
            if(tamanho < v->length){
                IO_printf("Novo tamanho é menor que o antigo, isso fara você perder os valores antigos, gostaria de continuar (sim = 1/não = 0)?");
                do{
                    verify = scanf("%d",&valorAtual); getchar( );
                    if(!verify){ IO_printf("Digite um valor Inteiro!"); }
                }while(!verify);
                if(valorAtual > 0){
                    newArranjo = (int*) malloc(sizeof(int)*v->length);
                    for(int i = 0; i < v->length; i = i + 1){
                        newArranjo[i] = v->valores[i];
                    }
                    free(v->valores);
                    v->valores = (int*) malloc(sizeof(int)*tamanho);
                    v->length = tamanho;
                    for(int i = 0; i < tamanho; i = i + 1){
                        v->valores[i] = newArranjo[i];
                    }
                    free(newArranjo);
                    newArranjo = NULL;
                }
            } else {
                v->valores = realloc(v->valores,sizeof(int)*tamanho);
                v->length = tamanho;
            }
        } else {
            IO_printf("Tamanho invalido!");
        }
    } else {
        IO_printf("Valores não criado!");
    }
}

void pegarValores(Valores* v,char arquivo_nome[]){
    FILE* arquivo = fopen(arquivo_nome,"rt");
    bool verify = false;
    int valorAtual = 0;
    int n = 0;
    char lixo[STR_SIZE];

    fscanf(arquivo,"%d",&n);

    if(verificarValores(v)){
        updateValores_tamanho(v,n);
        while(!feof(arquivo) && v->index < v->length){
            verify = fscanf(arquivo,"%d",&valorAtual);
            if(verify){
                v->valores[v->index] = valorAtual;
            } else {
                fgets(lixo,sizeof(lixo),arquivo);
            }
            v->index = v->index + 1;
        }
        v->index = 0;
    }

    fclose(arquivo);
}

void indexValores(Valores* v){
    if(verificarValores(v)){
        v->index = 0;
        while(v->index < v->length){
            IO_printf("\t%d\n",v->valores[v->index]);
            v->index = v->index + 1;
        }
        v->index = 0;
    } else {
        IO_printf("Não foi possivel mostrar seu valores!");
    }
}

void deleteValores(Valores* v){
    if(verificarValores(v)){
        free(v->valores);
        v->valores = NULL;
        v->index = 0;
        v->length = 0;
        free(v);
        v = NULL;
    } else {
        IO_printf("Seus valores já estão excluidos!");
    }
}