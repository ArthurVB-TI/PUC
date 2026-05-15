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
    int n = v1->length;
    v3->valores = (int*) malloc(sizeof(int)*v1->length);
    if(v2->length > v1->length){
        v3->valores = (int*) realloc(v3->valores,sizeof(int)*v2->length);
        n = v2->length;
    }
    for(int i = 0; i < n; i = i + 1){
        v3->valores[i] = v1->valores[i] + (v2->valores[i] * constante);
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