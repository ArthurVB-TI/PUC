/*
 * lerDimensoes -> ler linhas e colunas
 * createMatriz -> criar matriz pedindo dimensoes ao usuario
 * verificarMatriz -> verificar se está tudo certo com sua matriz
 * updateMatriz_valor -> atualizar um valor especifico
 * updateMatriz_tamanho -> atualizar as dimensoes da matriz
 * colocarMatriz -> preencher a matriz manualmente pelo teclado
 * colocarMatrizAleatorio -> preencher a matriz com numeros aleatorios dentro de um intervalo
 * indexMatriz -> mostrar todos os valores da matriz
 * deleteMatriz -> deletar a matriz
**/

void lerDimensoes(int *linhas, int *colunas){
    bool v = false;
    int l = 0;
    int c = 0;

    do{
        IO_printf("Digite a quantidade de linhas: ");
        v = scanf("%d",&l); getchar();
        if(!v || l <= 0){ IO_printf("Valor invalido!"); }
    }while(!v || l <= 0);

    do{
        IO_printf("Digite a quantidade de colunas: ");
        v = scanf("%d",&c); getchar();
        if(!v || c <= 0){ IO_printf("Valor invalido!"); }
    }while(!v || c <= 0);

    *linhas = l;
    *colunas = c;
}

Matriz* createMatriz(bool valorInicial){
    Matriz* retorno = (Matriz*) malloc(sizeof(Matriz)*1);
    int linhas = 0;
    int colunas = 0;

    if(retorno != NULL){
        if(valorInicial){
            lerDimensoes(&linhas, &colunas);
        } else {
            linhas = 0;
            colunas = 0;
        }

        retorno->linhasLength = linhas;
        retorno->colunasLength = colunas;
        retorno->index = 0;
        retorno->matriz = (int**) malloc(sizeof(int*)*linhas);
        for(int i = 0; i < linhas; i = i + 1){
            retorno->matriz[i] = (int*) malloc(sizeof(int)*colunas);
        }
    }

    return retorno;
}

bool verificarMatriz(Matriz* m){
    bool retorno = true;
    if(m != NULL){
        if(m->linhasLength <= 0 || m->colunasLength <= 0){
            retorno = false;
        }
    } else {
        IO_printf("Matriz não criada!");
        retorno = false;
    }
    return retorno;
}

void updateMatriz_valor(Matriz* m, int valor, int linha, int coluna){
    if(verificarMatriz(m)){
        if(linha >= 0 && linha < m->linhasLength && coluna >= 0 && coluna < m->colunasLength){
            m->matriz[linha][coluna] = valor;
        } else {
            IO_printf("Indice invalido!");
        }
    } else {
        IO_printf("Não foi possivel atualizar sua matriz!");
    }
}

void updateMatriz_tamanho(Matriz* m, int linhas, int colunas){
    if(m != NULL){
        for(int i = 0; i < m->linhasLength; i = i + 1){
            free(m->matriz[i]);
        }
        free(m->matriz);
        m->linhasLength = linhas;
        m->colunasLength = colunas;
        m->matriz = (int**) malloc(sizeof(int*)*linhas);
        for(int i = 0; i < linhas; i = i + 1){
            m->matriz[i] = (int*) malloc(sizeof(int)*colunas);
        }
    } else {
        IO_printf("Não foi possivel atualizar o tamanho da sua matriz!");
    }
}

void colocarMatriz(Matriz* m){
    bool verify = false;
    int valorAtual = 0;

    if(verificarMatriz(m)){
        for(int i = 0; i < m->linhasLength; i = i + 1){
            for(int j = 0; j < m->colunasLength; j = j + 1){
                do{
                    IO_printf("Digite o valor [%d][%d]: ",i,j);
                    verify = scanf("%d",&valorAtual); getchar();
                    if(!verify){ IO_printf("Valor invalido!"); }
                }while(!verify);
                updateMatriz_valor(m,valorAtual,i,j);
            }
        }
    }
}

void pegarMatriz(Matriz* m, char arquivo_nome[]){
    int linhas = 0;
    int colunas = 0;
    int** dados = IO_fIndexMatriz_Int(arquivo_nome, &linhas, &colunas);
    if(verificarMatriz(m) && linhas > 0 && colunas > 0){
        updateMatriz_tamanho(m, linhas, colunas);
        for(int i = 0; i < linhas; i = i + 1){
            for(int j = 0; j < colunas; j = j + 1){
                m->matriz[i][j] = dados[i][j];
            }
            free(dados[i]);
        }
        free(dados);
    } else {
        IO_printf("Não foi possivel pegar sua matriz!");
    }
}

void colocarMatrizAleatorio(Matriz* m, int min, int max){
    if(verificarMatriz(m)){
        for(int i = 0; i < m->linhasLength; i = i + 1){
            for(int j = 0; j < m->colunasLength; j = j + 1){
                updateMatriz_valor(m,IO_random(min,max),i,j);
            }
        }
    }
}

void indexMatriz(Matriz* m){
    if(verificarMatriz(m)){
        for(int i = 0; i < m->linhasLength; i = i + 1){
            for(int j = 0; j < m->colunasLength; j = j + 1){
                IO_printf("\t%d",m->matriz[i][j]);
            }
            IO_printf("\n");
        }
        m->index = 0;
    } else {
        IO_printf("Não foi possivel mostrar sua matriz!");
    }
}

void deleteMatriz(Matriz* m){
    if(verificarMatriz(m)){
        for(int i = 0; i < m->linhasLength; i = i + 1){
            free(m->matriz[i]);
            m->matriz[i] = NULL;
        }
        free(m->matriz);
        m->matriz = NULL;
        m->linhasLength = 0;
        m->colunasLength = 0;
        m->index = 0;
        free(m);
        m = NULL;
    } else {
        IO_printf("Sua matriz já está excluida!");
    }
}
