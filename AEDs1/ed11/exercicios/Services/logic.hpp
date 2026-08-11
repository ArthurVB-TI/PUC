void readRandoms(Array<int>* a){
    int i1 = 0;
    int i2 = 0;

    a->readLength();
    IO_readIntervalo(&i1,&i2);
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        a->setValue(IO_random(i1, i2));
    }
}

void fread_int(Array<int>* a,char arquivo_name[]){
    FILE* arquivo = fopen(arquivo_name, "rt");
    int* retorno;

    bool verify = false;
    int valorAtual = 0;
    int index = 0;
    int n = 0;
    char lixo[STR_SIZE];

    fscanf(arquivo,"%d",&n);

    if(n > 0){
        retorno = (int*) malloc(n * sizeof(int));
        while(!feof(arquivo) && index < n){
            verify = fscanf(arquivo,"%d",&valorAtual);
            if(verify){
                retorno[index] = valorAtual;
            } else {
                fgets(lixo,sizeof(lixo),arquivo);
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

int getMaiorPar(Array<int>* a){
    int maior = 0;
    int valorAtual = 0;
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorAtual = a->getValue();
        if(valorAtual % 2 == 0){
            if(valorAtual > maior){
                maior = valorAtual;
            }
        }
    }
    return maior;
}

int getMaiorPar_MultiploDe5(Array<int>* a){
    int maior = 0;
    int valorAtual = 0;
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorAtual = a->getValue();
        if(valorAtual % 2 == 0 && valorAtual % 5 == 0){
            if(valorAtual > maior){
                maior = valorAtual;
            }
        }
    }
    return maior;
}

int somarEntreIntervalos(Array<int>* a,int *interval1,int *interval2){
    int i1 = 0;
    int i2 = 0;
    int valorAtual = 0;
    int soma = 0;
    
    IO_readIntervalo(&i1,&i2);
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorAtual = a->getValue();
        if(valorAtual >= i1 && valorAtual <= i2){
            soma = soma + valorAtual;
        }
    }

    *interval1 = i1;
    *interval2 = i2;
    return soma;
}

double mediaEntreIntervalos(Array<int>* a,int *interval1,int *interval2){
    int i1 = 0;
    int i2 = 0;
    int valorAtual = 0;
    double soma = 0;
    int qtde = 1;
    
    IO_readIntervalo(&i1,&i2);
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorAtual = a->getValue();
        if(valorAtual >= i1 && valorAtual <= i2){
            soma = soma + valorAtual;
            qtde = qtde + 1;
        }
    }

    if(soma > 0) soma = soma/(double)qtde;
    *interval1 = i1;
    *interval2 = i2;
    return soma;
}

bool verificarEntreIntervalos(Array<int>* a,int i1,int i2){
    int valorAtual = 0;
    bool retorno = true;
    
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorAtual = a->getValue();
        if(!(valorAtual >= i1 && valorAtual < i2)){
            retorno = false;
        }
    }

    return retorno;
}

bool isDecrescente(Array<int>* a){
    int valorAtual = 0;
    int valorAntigo = 0;
    bool retorno = true;
    
    a->setPosition(0);
    for(int i = 0; i < a->getLength(); i = i + 1){
        valorAntigo = valorAtual;
        valorAtual = a->getValue();
        if(valorAtual > valorAntigo && i != 0){
            retorno = false;
        }
    }

    return retorno;
}

bool isExistente(Array<int>* a, int value, int *interval1, int *interval2){
    int i1 = 0;
    int i2 = 0;
    int n = 0;
    int valorAtual = 0;
    bool retorno = false;
    
    IO_readIntervalo(&i1,&i2);
    a->setPosition(i1);
    if(i2 > a->getLength()) n = a->getLength();
    else n = i2;
    for(int i = i1; i < n; i = i + 1){
        valorAtual = a->getValue();
        if(valorAtual == value){
            retorno = true;
        }
    }

    *interval1 = i1;
    *interval2 = i2;
    return retorno;
}

void multiplicarArray(Array<int>* a, int value, int *interval1, int *interval2){
    int i1 = 0;
    int i2 = 0;
    int n = 0;
    int valorAtual = 0;
    
    IO_readIntervalo(&i1,&i2);
    a->setPosition(0);
    if(i2 > a->getLength()) n = a->getLength();
    else n = i2;
    for(int i = i1; i < n; i = i + 1){
        valorAtual = a->getValue();
        a->setPosition(i);
        a->setValue(valorAtual * value);
    }

    *interval1 = i1;
    *interval2 = i2;
}

void sortDown(Array<int>* a){
    int valorAtual = 0;
    int valorAntigo = 0;
    int menorValor = 0;
    int menorValor_Index = 0;
    int countDecrescente = 0;

    for(int i = 0; i < a->getLength() && countDecrescente + i < a->getLength(); i = i + 1){
        countDecrescente = 0;
        for(int j = i; j < a->getLength(); j = j + 1){
            a->setPosition(j);
            valorAntigo = valorAtual;
            valorAtual = a->getValue();
            if(valorAtual < menorValor || j == i){
                menorValor = valorAtual;
                menorValor_Index = j;
            }
            if(valorAtual <= valorAntigo && j != i){
                countDecrescente = countDecrescente + 1;
            }
        }

        if(countDecrescente + i < a->getLength()){
            a->setPosition(i);
            a->setValue_wIndex(a->getValue(),menorValor_Index);
            a->setValue_wIndex(menorValor, i);
        }
    }
}