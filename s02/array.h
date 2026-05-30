typedef struct array{
    double* data;
    int length;
    int index;
} array;

array* createArray(){
    array* r = (array*) malloc(sizeof(array));
    r->data = NULL;
    r->length = 0;
    r->index = 0;
    return r;
}

void updateArray(array* a, int qtde){
    if(a != NULL && qtde > 0){
        a->data = (double*)malloc(sizeof(double)*qtde);
        a->length = qtde;
        a->index = 0;
    }
}

void getArray(array* a, char* arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome, "r");
    int n = 0;
    int i = 0;
    double valorAtual = 0.0;
    char lixo[100];
    if(arquivo != NULL){
        fscanf(arquivo, "%d", &n);
        updateArray(a, n);
        while(!feof(arquivo) && i < n){
            if(fscanf(arquivo, "%*[^:]: %lf", &valorAtual) == 1){
                a->data[i] = valorAtual;
                i = i + 1;
            } else {
                fgets(lixo, sizeof(lixo), arquivo);
            }
        }
        fclose(arquivo);
    }
}

void indexArray(array* a){
    if(a->data != NULL){
        for(a->index = 0; a->index < a->length; a->index = a->index + 1){
            IO_printf("%lf\n",a->data[a->index]);
        }
    }
}

double getMaior(array* a){
    double maior = -1.0;
    if(a->data != NULL){
        maior = a->data[0];
        for(a->index = 1; a->index < a->length; a->index = a->index + 1){
            if(maior < a->data[a->index]){
                maior = a->data[a->index];
            }
        }
    }
    return maior;
}

double getMenor(array* a){
    double menor = 0.0;
    if(a->data != NULL){
        menor = a->data[0];
        for(a->index = 1; a->index < a->length; a->index = a->index + 1){
            if(menor > a->data[a->index]){
                menor = a->data[a->index];
            }
        }
    }
    return menor;
}

double getMedia(array* a){
    double media = 0.0;
    if(a->data != NULL){
        for(a->index = 0; a->index < a->length; a->index = a->index + 1){
            media = media + a->data[a->index];
        }
    }
    return (media / (double) a->length);
}

double getMediaSemExtremos(array* a){
    double media = 0.0;
    double maior = getMaior(a);
    double menor = getMenor(a);
    int count = 0;
    bool removeuMaior = false;
    bool removeuMenor = false;
    if(a->data != NULL){
        for(a->index = 0; a->index < a->length; a->index = a->index + 1){
            if(!removeuMaior && a->data[a->index] == maior){ removeuMaior = true; continue; }
            if(!removeuMenor && a->data[a->index] == menor){ removeuMenor = true; continue; }
            media = media + a->data[a->index];
            count = count + 1;
        }
    }
    if(count > 0){ return (media / (double) count); }
    return 0.0;
}

void deleteArray(array* a){
    if(a != NULL){
        if(a->data != NULL){
            free(a->data);
            a->data = NULL;
        }
        a->length = 0;
        a->index = 0;
        free(a);
        a = NULL;
    }
}