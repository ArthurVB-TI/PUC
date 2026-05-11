void index_p1(int a, int b, int qtde, int* valores){
    IO_printf("Os valores digitados dentro do intervalo [%d:%d], são:\n",a,b);
    for(int i = 0; i < qtde; i = i + 1){
        IO_printf("\t%d - %d\n",i,valores[i]);
    }
}

void gravar_p1(char* arquivoName, int qtde, int* valores){
    FILE* arquivo = fopen(arquivoName,"wt");

    for(int i = 0; i < qtde; i = i + 1){
        fprintf(arquivo,"%d\n",valores[i]);
    }

    fclose(arquivo);
}