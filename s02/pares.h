typedef struct pares{
    int** data;
    int index;
    int length;
    double* distancia;
} pares;

pares* createPares(){
    pares* p = (pares*) malloc(sizeof(pares));
    p->data = NULL;
    p->index = 0;
    p->length = 0;
    p->distancia = NULL;
    return p;
}

void updatePares(pares* par, int qtde){
    if(par != NULL && qtde > 0){
        par->data = (int**) malloc(sizeof(int*)*qtde);
        for(int i = 0; i < qtde; i = i + 1){
            par->data[i] = (int*) malloc(sizeof(int)*2);
        }
        par->distancia = (double*) malloc(sizeof(double) * (qtde*(qtde-1)/2));
        par->length = qtde;
    }
}

void updateDistancia(pares* par){
    if(par->data != NULL){
        int n = par->length;
        for(par->index = 0; par->index < n; par->index = par->index + 1){
            for(int j = par->index + 1; j < n; j = j + 1){
                int k = par->index * n - par->index*(par->index+1)/2 + (j - par->index - 1);
                par->distancia[k] = sqrt(pow(par->data[j][0] - par->data[par->index][0], 2) + pow(par->data[j][1] - par->data[par->index][1], 2));
            }
        }
    }
}

void randomPares(pares* par){
    if(par->data != NULL && par->length > 0){
        for(par->index = 0; par->index < par->length; par->index = par->index + 1){
            par->data[par->index][0] = IO_random(1,100);
            par->data[par->index][1] = IO_random(1,100);
        }
    }
}

void indexPares(pares* par){
    if(par->data != NULL){
        for(par->index = 0; par->index < par->length; par->index = par->index + 1){
            IO_printf("(%d, %d)\n",par->data[par->index][0],par->data[par->index][1]);
        }
    }
}

void indexParesDistancia(pares* par){
    if(par->data != NULL){
        int n = par->length;
        for(par->index = 0; par->index < n; par->index = par->index + 1){
            for(int j = par->index + 1; j < n; j = j + 1){
                int k = par->index * n - par->index*(par->index+1)/2 + (j - par->index - 1); // Pesquisei o calculo
                IO_printf("(%d,%d): %lf\n", par->index + 1, j, par->distancia[k]);
            }
        }
    }
}

void gravarPares(pares* par, char* nome){
    FILE* arquivo = fopen(nome, "wt");
    if(arquivo != NULL && par->data != NULL){
        fprintf(arquivo, "%d\n", par->length);
        for(int i = 0; i < par->length; i = i + 1){
            fprintf(arquivo, "%d %d\n", par->data[i][0], par->data[i][1]);
        }
        fclose(arquivo);
    }
}

void gravarDistancias(pares* par, char* nome){
    FILE* arquivo = fopen(nome, "wt");
    if(arquivo != NULL && par->data != NULL){
        int n = par->length;
        fprintf(arquivo, "%d\n", n*(n-1)/2);
        for(par->index = 0; par->index < n; par->index = par->index + 1){
            for(int j = par->index + 1; j < n; j = j + 1){
                int k = par->index * n - par->index*(par->index+1)/2 + (j - par->index - 1);
                fprintf(arquivo, "(%d,%d): %lf\n", par->index, j, par->distancia[k]);
            }
        }
        fclose(arquivo);
    }
}

void lerParesDeArquivo(pares* par, char* nome){
    FILE* arquivo = fopen(nome, "rt");
    int x = 0, y = 0;
    int capacidade = 100;
    if(arquivo != NULL){
        par->data = (int**) malloc(sizeof(int*) * capacidade);
        par->length = 0;
        while(!feof(arquivo)){
            if(fscanf(arquivo, "%d %d", &x, &y) == 2){
                if(x == 0 && y == 0){ break; }
                par->data[par->length] = (int*) malloc(sizeof(int) * 2);
                par->data[par->length][0] = x;
                par->data[par->length][1] = y;
                par->length = par->length + 1;
            } else { break; }
        }
        par->distancia = (double*) malloc(sizeof(double) * (par->length > 1 ? par->length - 1 : 1));
        fclose(arquivo);
    }
}

void calcularDistanciasConsecutivas(pares* par){
    if(par->data != NULL && par->length > 1){
        for(par->index = 0; par->index < par->length - 1; par->index = par->index + 1){
            double dx = (double)(par->data[par->index+1][0] - par->data[par->index][0]);
            double dy = (double)(par->data[par->index+1][1] - par->data[par->index][1]);
            par->distancia[par->index] = sqrt(dx*dx + dy*dy);
        }
    }
}

void gravarDistanciasConsecutivas(pares* par, char* nome){
    FILE* arquivo = fopen(nome, "wt");
    if(arquivo != NULL && par->data != NULL){
        int n = par->length - 1;
        fprintf(arquivo, "%d\n", n);
        for(int i = 0; i < n; i = i + 1){
            fprintf(arquivo, "(%d,%d): %lf\n", i, i+1, par->distancia[i]);
        }
        fclose(arquivo);
    }
}

typedef struct matrizPares{
    double** data;
    int linhas;
    int colunas;
} matrizPares;

matrizPares* createMatrizPares(){
    matrizPares* m = (matrizPares*) malloc(sizeof(matrizPares));
    m->data = NULL;
    m->linhas = 0;
    m->colunas = 2;
    return m;
}

void lerMatrizParesDeArquivo(matrizPares* m, char* nome){
    FILE* arquivo = fopen(nome, "rt");
    double x = 0.0, y = 0.0;
    int capacidade = 100;
    if(arquivo != NULL){
        m->data = (double**) malloc(sizeof(double*) * capacidade);
        m->linhas = 0;
        while(!feof(arquivo)){
            if(fscanf(arquivo, "%lf %lf", &x, &y) == 2){
                if(x == 0.0 && y == 0.0){ break; }
                m->data[m->linhas] = (double*) malloc(sizeof(double) * 2);
                m->data[m->linhas][0] = x;
                m->data[m->linhas][1] = y;
                m->linhas = m->linhas + 1;
            } else { break; }
        }
        fclose(arquivo);
    }
}

void ordenarMatrizPares(matrizPares* m){
    if(m->data == NULL){ return; }
    int n = m->linhas;
    bool trocou = true;
    while(trocou){
        trocou = false;
        for(int i = 0; i < n - 1; i = i + 1){
            bool trocar = (m->data[i][0] > m->data[i+1][0]) ||
                          (m->data[i][0] == m->data[i+1][0] && m->data[i][1] > m->data[i+1][1]);
            if(trocar){
                double* tmp = m->data[i];
                m->data[i] = m->data[i+1];
                m->data[i+1] = tmp;
                trocou = true;
            }
        }
    }
}

void indexMatrizPares(matrizPares* m){
    if(m->data != NULL){
        for(int i = 0; i < m->linhas; i = i + 1){
            IO_printf("(%.2lf, %.2lf)\n", m->data[i][0], m->data[i][1]);
        }
    }
}

double distanciaPrimeiroUltimo(matrizPares* m){
    if(m->data == NULL || m->linhas < 2){ return 0.0; }
    double dx = m->data[m->linhas-1][0] - m->data[0][0];
    double dy = m->data[m->linhas-1][1] - m->data[0][1];
    return sqrt(dx*dx + dy*dy);
}

void deleteMatrizPares(matrizPares* m){
    if(m != NULL){
        if(m->data != NULL){
            for(int i = 0; i < m->linhas; i = i + 1){ free(m->data[i]); }
            free(m->data);
        }
        free(m);
    }
}

void deletePares(pares* par){
    if(par != NULL){
        if(par->data != NULL){
            for(int i = 0; i < par->length; i = i + 1){
                free(par->data[i]);
            }
            free(par->data);
            free(par->distancia);
            par->length = 0;
            par->index = 0;
        }
        free(par);
        par = NULL;
    }
}