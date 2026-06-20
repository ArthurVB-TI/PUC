using namespace std;

Array* getArray(string nome_arquivo,int *length){
    Array* retorno = new Array();
    FILE* arquivo = fopen(nome_arquivo.c_str(),"rt");
    int* values = (int*) malloc(sizeof(int) * 100);

    int valorAtual = 0;
    char lixo[100];
    bool v = false;

    int index = 0;
    while(!feof(arquivo) || index < 100){
        v = fscanf(arquivo,"%d", &valorAtual);
        if(v){
            values[index] = valorAtual;
            index = index + 1;
        } else {
            fgets(lixo,100,arquivo);
        }
    }

    retorno->update_length(index);
    for(int i = 0; i < index; i = i + 1){
        retorno->set_Push(values[i]);
    }

    free(values);
    fclose(arquivo);

    *length = index;
    return retorno;
}

void setArray(Array* a, string nome_arquivo){
    FILE* arquivo = fopen(nome_arquivo.c_str(), "wt");

    if(!a->ordemCrescente()) a->sort();
    for(int i = 0; i < a->get_length(); i = i + 1){
        fprintf(arquivo,"%d\n",a->get_value(i));
    }

    fclose(arquivo);
}