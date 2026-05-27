typedef struct array{
    int* data;
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
        a->data = (int*)malloc(sizeof(int)*qtde);
        a->length = qtde;
        a->index = 0;
    }
}

void getArray(array* a, char* arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome, "r");
    int n = 0;
    int i = 0;
    bool v = false;
    int valorAtual = 0;
    char lixo[100];
    if(arquivo != NULL){
        if(a->data != NULL){
            fscanf(arquivo, "%d", &n);
            updateArray(a, n);
            while(!feof(arquivo) && i < n){
                v = fscanf(arquivo, "%d", &valorAtual);
                if(!v){
                    a->data[a->index] = valorAtual;
                } else {
                    fgets(lixo,sizeof(lixo),arquivo);
                }
                i = i + 1; 
            }
        }
        fclose(arquivo);
    }
}

void indexArray(array* a){
    if(a->data != NULL){
        for(a->index = 0; a->index < a->length; a->index = a->index + 1){
            IO_printf("%d\n",a->data[a->index]);
        }
    }
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