void readRandoms_e(Array<int>* a){
    int i1 = 0;
    int i2 = 0;

    a->readLength();
    IO_readIntervalo(&i1, &i2);
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        a->setValue(IO_random(i1, i2));
    }
}

void fread_int(Array<int>* a, char arquivo_name[]){
    FILE* arquivo = fopen(arquivo_name, "rt");
    int* retorno;

    bool verify = false;
    int valorAtual = 0;
    int index = 0;
    int n = 0;
    char lixo[STR_SIZE];

    fscanf(arquivo, "%d", &n);

    if(n > 0){
        retorno = (int*) malloc(n * sizeof(int));
        while(!feof(arquivo) && index < n){
            verify = fscanf(arquivo, "%d", &valorAtual);
            if(verify){
                retorno[index] = valorAtual;
            } else {
                fgets(lixo, sizeof(lixo), arquivo);
            }
            index = index + 1;
        }
        a->updateLength(n);
        a->setPosition(0);
        for(int i = 0; i < n; i = i + 1){
            a->setValue(retorno[i]);
        }
    }

    fclose(arquivo);
}

bool isDiferente(Array<int>* a, Array<int>* b){
    bool retorno = false;
    int valorA = 0;
    int valorB = 0;

    if(a->getLength() != b->getLength()) return true;

    a->setPosition(0);
    b->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorA = a->getValue();
        valorB = b->getValue();
        if(valorA != valorB){
            retorno = true;
        }
    }
    return retorno;
}

int qtdeDiferencas(Array<int>* a, Array<int>* b){
    int qtde = 0;
    int valorA = 0;
    int valorB = 0;

    if(a->getLength() != b->getLength()) return -1;

    a->setPosition(0);
    b->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorA = a->getValue();
        valorB = b->getValue();
        if(valorA != valorB){
            qtde = qtde + 1;
        }
    }
    return qtde;
}
