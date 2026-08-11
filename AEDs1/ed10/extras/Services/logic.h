int* sortArrayDown(int* array,int tamanho){
    int* retorno;
    if(array != NULL && tamanho > 0){
        retorno = (int*) malloc(sizeof(int) * tamanho);
        for(int i = 0; i < tamanho; i = i + 1){
            retorno[i] = array[i];
        }

        // Variaveis para encontrar o maior valor do array
        int maiorValor = INT_MIN; // Menor valor inteiro
        int indexAtual = 0;
        int index = 0;

        // Variaveis para verificar se está tudo em ordem decrescente
        int countValores = 0;
        int menorValor = INT_MAX; // Maior valor inteiro

        // For para pecorrer todos os elementos
        // ou executar pelomenos até encontrar que todos os valores estão em ordem decrescente
        for(int i = 0; i < tamanho && !(countValores + i == tamanho - 1); i = i + 1){

            // Zerar valores para cada execução
            maiorValor = INT_MIN;
            menorValor = INT_MAX;
            countValores = 0;

            // Para cada execução desse for, eu pego o indice atual (i) e substituo pelo maior valor encontrado no array
            for(index = i; index < tamanho; index = index + 1){
                // Pegar o maior valor encontrado
                if(retorno[index] > maiorValor){
                    indexAtual = index;
                    maiorValor = retorno[index];
                }

                // Contar quantas vezes eu encontrei um menor valor
                if(retorno[index] <= menorValor){
                    countValores = countValores + 1;
                    menorValor = retorno[index];
                }
            }

            // Se eu encontrar um maior valor que seja na posição diferente do atual, eu troco
            if(i != indexAtual){
                retorno[indexAtual] = retorno[i];
                retorno[i] = maiorValor;
            }
        }
    } else {
        retorno = NULL;
    }
    return retorno;
}

void decrescente(Valores* v, Valores* v_decrescente){
    if(verificarValores(v) && v_decrescente != NULL){
        v_decrescente->valores = sortArrayDown(v->valores,v->length);
        v_decrescente->length = v->length;
        v_decrescente->index = 0;
    } else {
        IO_printf("Não foi possivel ordenar seus valores!");
    }
}

void multiplicacaoDeMatrizes(Matriz* m1,Matriz* m2,Matriz* m3){
    if(verificarMatriz(m1) && verificarMatriz(m2) && m3 != NULL){
        if(m1->colunasLength == m2->linhasLength){
            updateMatriz_tamanho(m3,m1->linhasLength,m2->colunasLength);
            for(int i = 0; i < m1->linhasLength; i = i + 1){
                for(int j = 0; j < m2->colunasLength; j = j + 1){
                    int resultado = 0;
                    for(int k = 0; k < m1->colunasLength; k = k + 1){
                        resultado = resultado + (m1->matriz[i][k] * m2->matriz[k][j]);
                    }
                    m3->matriz[i][j] = resultado;
                }
            }
        } else {
            IO_printf("O numero de colunas da matriz 1 precisa ser igual ao numero de linhas da matriz 2 para multiplicar as matrizes!");
        }
    } else {
        IO_printf("Não foi possivel multiplicar as matrizes!");
    }
}

bool verificarMatrizIdentidade(Matriz* m){
    bool retorno = true;
    if(verificarMatriz(m)){
        if(m->linhasLength == m->colunasLength){
            for(int i = 0; i < m->linhasLength; i = i + 1){
                for(int j = 0; j < m->colunasLength; j = j + 1){
                    if(i == j){
                        if(m->matriz[i][j] != 1){
                            retorno = false;
                        }
                    } else {
                        if(m->matriz[i][j] != 0){
                            retorno = false;
                        }
                    }
                }
            }
        } else {
            IO_printf("Matriz precisa ser quadrada para ser identidade!");
            retorno = false;
        }
    } else {
        IO_printf("Não foi possivel verificar se a matriz é identidade!");
        retorno = false;
    }
    return retorno;
}