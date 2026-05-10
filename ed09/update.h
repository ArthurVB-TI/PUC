// 0912
void fprintDoubleMatrix(char* arquivo_name, int linhas, int colunas, double **matriz){
    FILE* arquivo = fopen(arquivo_name, "wt");
    fprintf(arquivo, "Matriz: [%d x %d]\n", linhas, colunas);
    for(int i = 0; i < linhas; i = i + 1){
        for(int j = 0; j < colunas; j = j + 1){
            fprintf(arquivo, "%lf", matriz[i][j]);
            if(j + 1 < colunas){ fprintf(arquivo, "\t"); }
        }
        fprintf(arquivo, "\n");
    }
    fprintf(arquivo, "End\n");
    fclose(arquivo);
}

double** freadDoubleMatrix(char* arquivo_name, int *linhas, int *colunas){
    FILE* arquivo = fopen(arquivo_name, "rt");
    fscanf(arquivo, "Matriz: [%d x %d]\n", linhas, colunas);
    double** retorno = (double**) malloc(sizeof(double*) * (*linhas));
    for(int i = 0; i < *linhas; i = i + 1){
        retorno[i] = (double*) malloc(sizeof(double) * (*colunas));
        for(int j = 0; j < *colunas; j = j + 1){
            fscanf(arquivo, "%lf", &retorno[i][j]);
        }
    }
    fclose(arquivo);
    return retorno;
}

// 0911

double** ler_Valores_da_Matriz(int linhas, int colunas){
    double** retorno = (double**) malloc(sizeof(double*) * linhas);
    double valorAtual = 0.0;
    bool v = false;

    for(int i = 0; i < linhas; i = i + 1){
        IO_printf("Digite valores positivo ou zero na linha %d\n",i+1);
        retorno[i] = (double*) malloc(sizeof(double) * colunas);

        for(int j = 0; j < colunas; j = j + 1){
            do{
                IO_printf("Coluna [%d] - ",j+1);
                v = scanf("%lf",&valorAtual); getchar( );
                if(!v){
                    IO_printf("Digite um numero real!\n");
                } else {
                    if(valorAtual < 0){
                        IO_printf("Valor Invalido!\n");
                    }
                }
            }while(!v || valorAtual < 0);
            retorno[i][j] = valorAtual;
        }
    }

    return retorno;
}

// 0919
bool isZero(int linha, int coluna, double **matriz){
    bool retorno = true;
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(j == i - 1){
                    if(matriz[i][j] != 0.0){
                        retorno = false;
                    }
                }
            }
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
    return retorno;
}

// 0920
bool isNotZero(int linha, int coluna, double **matriz){
    bool retorno = true;
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(j - 1 == i){
                    if(matriz[i][j] == 0.0){
                        retorno = false;
                    }
                }
            }
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
    return retorno;
}