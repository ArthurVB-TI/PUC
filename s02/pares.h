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