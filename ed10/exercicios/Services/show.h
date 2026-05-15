void index_p1(Intervalo* i,Valores* v){
    if(verificarValores(v) && verificarIntervalo(i)){
        IO_printf("Os valores que estão dentro do intervalo ");
        indexIntervalo(i);
        IO_printf(" são: \n");
        v->index = 0;
        while(v->index < v->length){
            if(isIn_Intervalo(i,v->valores[v->index])){
                IO_printf("\t%d\n",v->valores[v->index]);
            }
            v->index = v->index + 1;
        }
        v->index = 0;
    } else {
        IO_printf("Seus valores e/ou intervalos não existem!");
    }
    IO_println("");
}

void gravar_p1(char arquivo_nome[],Valores* v){
    FILE* arquivo = fopen(arquivo_nome,"wt");
    if(verificarValores(v)){
        v->index = 0;
        fprintf(arquivo,"%d\n",v->length);
        while(v->index < v->length){
            fprintf(arquivo,"%d\n",v->valores[v->index]);
            v->index = v->index + 1;
        }
        v->index = 0;
    } else {
        IO_printf("Seus valores e/ou intervalos não existem!");
    }
    fclose(arquivo);
    IO_println("");
}

void index_p2(Procurados* p,Valores* v){
    if(verificarValores(v) && verificarProcurados(p)){
        IO_printf("Dentre os valores: \n");
        indexValores(v);
        IO_printf("Os valores procurados foram: \n");
        indexProcurados(p);
    } else {
        IO_printf("Seus valores e/ou procurados não existem!");
    }
    IO_println("");
}

void index_p3(Valores* v1, Valores* v2, bool resposta){
    IO_printf("Arranjo 1: \n");
    indexValores(v1);
    IO_printf("Arranjo 2: \n");
    indexValores(v2);
    if(resposta){
        IO_printf("Os arranjos são iguais!\n");
    } else {
        IO_printf("Os arranjos não são iguais!\n");
    }
    IO_println("");
}

void index_p4(Valores* v1, Valores* v2, Valores* v3, int constante){
    if(verificarValores(v1) && verificarValores(v2) && verificarValores(v3)){
        IO_printf("Arranjo 1: \n");
        indexValores(v1);
        IO_printf("Arranjo 2: \n");
        indexValores(v2);
        IO_printf("Resultado da adição com constante %d: \n", constante);
        indexValores(v3);
    } else {
        IO_printf("Um ou mais arranjos não existem!");
    }
    IO_println("");
}