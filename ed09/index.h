// Exercicios

void index_p2(int linha, int coluna, double **matriz){
    IO_printf("Matriz [%d x %d]:\n",linha,coluna);
    for(int i = 0; i < linha; i = i + 1){
        for(int j = 0; j < coluna; j = j + 1){
            IO_printf("%lf\t",matriz[i][j]);
        }
        IO_println("");
    }
}

void index_p3(int linha, int coluna, double **matriz){
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:\n",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(j == i){
                    IO_printf("%lf\t",matriz[i][j]);
                } else {
                    IO_printf("X\t");
                }
            }
            IO_println("");
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
}

void index_p4(int linha, int coluna, double **matriz){
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:\n",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(j + i == linha - 1){
                    IO_printf("%lf\t",matriz[i][j]);
                } else {
                    IO_printf("X\t");
                }
            }
            IO_println("");
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
}

void index_p5(int linha, int coluna, double **matriz){
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:\n",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(i - 1 == j){
                    IO_printf("%lf\t",matriz[i][j]);
                } else {
                    IO_printf("X\t");
                }
            }
            IO_println("");
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
}

void index_p6(int linha, int coluna, double **matriz){
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:\n",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(i + 1 == j){
                    IO_printf("%lf\t",matriz[i][j]);
                } else {
                    IO_printf("X\t");
                }
            }
            IO_println("");
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
}

void index_p7(int linha, int coluna, double **matriz){
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:\n",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(j + i - 1 == linha - 1){
                    IO_printf("%lf\t",matriz[i][j]);
                } else {
                    IO_printf("X\t");
                }
            }
            IO_println("");
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
}

void index_p8(int linha, int coluna, double **matriz){
    if(linha == coluna){
        IO_printf("Matriz [%d x %d]:\n",linha,coluna);
        for(int i = 0; i < linha; i = i + 1){
            for(int j = 0; j < coluna; j = j + 1){
                if(j + i + 1 == linha - 1){
                    IO_printf("%lf\t",matriz[i][j]);
                } else {
                    IO_printf("X\t");
                }
            }
            IO_println("");
        }
    } else {
        IO_printf("Não é uma matriz quadrada");
    }
}

void index_p9(int linha, int coluna, double **matriz){
    if(isZero(linha,coluna,matriz)){
        IO_printf("Os elementos abaixo da diagonal principal são todos zero\n");
    } else {
        IO_printf("Os elementos abaixo da diagonal principal não são todos zero\n");
    }
}

void index_p10(int linha, int coluna, double **matriz){
    if(isNotZero(linha,coluna,matriz)){
        IO_printf("Os elementos abaixo da diagonal principal são todos diferentes de zero\n");
    } else {
        IO_printf("Os elementos abaixo da diagonal principal não são todos diferentes de zero\n");
    }
}