void scalar(matriz<int>* m1,matriz<int>* m2,int constante){
    int n = m1->getRows();
    int m = m1->getColumns();
    if(n > 0 && m > 0){
        m2->updateMatriz(n, m);
        for(int i = 0; i < n; i = i + 1){
            for (int j = 0; j < m; j = j + 1){
                m2->setMatriz(i,j,m1->getValue(i,j) * constante);
            }
        }
    }
}

bool identidade(matriz<int>* m1){
    int n = m1->getRows();
    int m = m1->getColumns();
    bool retorno = true;
    if(n > 0 && m > 0 && n == m){
        for(int i = 0; i < n; i = i + 1){
            for (int j = 0; j < n; j = j + 1){
                if(i == j){
                    if(m1->getValue(i, j) != 1){
                        retorno = false;
                    }
                } else {
                    if(m1->getValue(i, j) != 0){
                        retorno = false;
                    }
                }
            }
        }
    }
    return retorno;
}

bool identica(matriz<int>* m1, matriz<int>* m2){
    bool retorno = true;
    int n1 = m1->getRows();
    int c1 = m1->getColumns();
    int n2 = m2->getRows();
    int c2 = m2->getColumns();
    if(n1 == n2 && c1 == c2){
        for(int i = 0; i < n1; i = i + 1){
            for (int j = 0; j < c1; j = j + 1){
                if(m1->getValue(i, j) != m2->getValue(i, j)){
                    retorno = false;
                }
            }
        }
    } else {
        retorno = false;
    }
    return retorno;
}

void gerar_arquivo_m4(matriz<int>* M, std::string arquivo_nome){
    M->setMatrizLength();
    M->setRandomMatriz();
    FILE* arquivo = fopen(arquivo_nome.c_str(), "w");
    fprintf(arquivo, "%d %d\n", M->getRows(), M->getColumns());
    for(M->row_index = 0; M->row_index < M->getRows(); M->row_index = M->row_index + 1){
        for(M->column_index = 0; M->column_index < M->getColumns(); M->column_index = M->column_index + 1){
            fprintf(arquivo, "%d ", M->getValue(M->row_index, M->column_index));
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

void gerar_dados_m4(std::string arquivo_nome1, std::string arquivo_nome2){
    matriz<int>* M1 = new matriz<int>();
    matriz<int>* M2 = new matriz<int>();
    gerar_arquivo_m4(M1, arquivo_nome1);
    gerar_arquivo_m4(M2, arquivo_nome2);
    delete M1;
    delete M2;
}

void somaDeMatrizes(matriz<int>* m1, matriz<int>* m2, matriz<int>* m3){
    int n = m1->getRows();
    int m = m1->getColumns();
    if(n > 0 && m > 0){
        m3->updateMatriz(n, m);
        for(int i = 0; i < n; i = i + 1){
            for (int j = 0; j < m; j = j + 1){
                m3->setMatriz(i, j, m1->getValue(i, j) + m2->getValue(i, j));
            }
        }
    }
}