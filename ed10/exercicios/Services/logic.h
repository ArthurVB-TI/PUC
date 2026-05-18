bool arrayCompare(Valores* v1, Valores* v2){
    bool retorno = true;
    if(v1->length != v2->length){
        retorno = false;
    } else {
        for(int i = 0; i < v1->length; i = i + 1){
            if(v1->valores[i] != v2->valores[i]){
                retorno = false;
            }
        }
    }
    return retorno;
}

void arrayAdd(Valores* v1, Valores* v2,Valores* v3,int constante){
    if(verificarValores(v1) && verificarValores(v2) && v3 != NULL){
        int n = v1->length;
        v3->valores = (int*) malloc(sizeof(int)*v1->length);
        if(v2->length > v1->length){
            v3->valores = (int*) realloc(v3->valores,sizeof(int)*v2->length);
            n = v2->length;
        }
        v3->length = n;
        for(int i = 0; i < n; i = i + 1){
            v3->valores[i] = v1->valores[i] + (v2->valores[i] * constante);
        }
    } else {
        IO_printf("Não foi possivel pegar a resultante do seu arranjo!");
    }
}

bool is_arrayDecrescent(int* array, int length){
    bool retorno = true;
    for(int i = 0; i < length - 1; i = i + 1){
        if(array[i] < array[i+1]){
            retorno = false;
        }
    }
    return retorno;
}

void pegarTransposta(Matriz* m1,Matriz* m2){
    if(verificarMatriz(m1) && m2 != NULL){
        m2->matriz = matrizTransposta(m1->matriz, m1->linhasLength, m1->colunasLength);
        m2->linhasLength = m1->colunasLength;
        m2->colunasLength = m1->linhasLength;
    } else {
        IO_printf("Não foi possivel pegar a transposta da sua matriz!");
    }
}

int** matrizTransposta(int** matriz, int linhas, int colunas){
    int** retorno = (int**) malloc(sizeof(int*)*colunas);
    for(int i = 0; i < colunas; i = i + 1){
        retorno[i] = (int*) malloc(sizeof(int)*linhas);
        for(int j = 0; j < linhas; j = j + 1){
            retorno[i][j] = matriz[j][i];
        }
    }
    return retorno;
}

bool is_matrizZero(Matriz* m){
    bool retorno = true;
    if(verificarMatriz(m)){
        for(int i = 0; i < m->linhasLength; i = i + 1){
            for(int j = 0; j < m->colunasLength; j = j + 1){
                if(m->matriz[i][j] != 0){
                    retorno = false;
                }
            }
        }
    } else {
        IO_printf("Não foi possivel verificar se sua matriz contem somente zeros!");
        retorno = false;
    }
    return retorno;
}

bool matrizCompare(Matriz* m1,Matriz* m2){
    bool retorno = false;
    if(verificarMatriz(m1) && verificarMatriz(m2)){
        if(m1->linhasLength == m2->linhasLength){
            if(m1->colunasLength == m2->colunasLength){
                retorno = true;
                for(int i = 0; i < m1->linhasLength; i = i + 1){
                    for(int j = 0; j < m1->colunasLength; j = j + 1){
                        if(m1->matriz[i][j] != m2->matriz[i][j]){
                            retorno = false;
                        }
                    }
                }
            }
        }
    } else {
        IO_printf("Uma ou mais matrizes não existem!");
    }
    return retorno;
}

void pegarResultante(Matriz* m1,Matriz* m2,Matriz* m3,int constante){
    if(verificarMatriz(m1) && verificarMatriz(m2) && m3 != NULL){
        if(m1->linhasLength == m2->linhasLength && m1->colunasLength == m2->colunasLength){
            updateMatriz_tamanho(m3,m1->linhasLength,m1->colunasLength);
            for(int i = 0; i < m1->linhasLength; i = i + 1){
                for(int j = 0; j < m1->colunasLength; j = j + 1){
                    m3->matriz[i][j] = m1->matriz[i][j] + (m2->matriz[i][j] * constante);
                }
            }
        } else {
            IO_printf("As matrizes precisam ter o mesmo tamanho para pegar a resultante!");
        }
    } else {
        IO_printf("Não foi possivel pegar a resultante da sua matriz!");
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