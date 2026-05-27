void index_m1(matriz<int>* Matriz){
    std::cout << "Matriz gerada: " << endl;
    Matriz->indexMatriz();
}

void gravar_m1(matriz<int>* Matriz,std::string arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome.c_str(), "w");
    fprintf(arquivo,"%d %d\n", Matriz->getRows(), Matriz->getColumns());
    for(Matriz->row_index = 0; Matriz->row_index < Matriz->getRows(); Matriz->row_index = Matriz->row_index + 1){
        for(Matriz->column_index = 0; Matriz->column_index < Matriz->getColumns(); Matriz->column_index = Matriz->column_index + 1){
            fprintf(arquivo,"%d ",Matriz->getValue(Matriz->row_index,Matriz->column_index));
        }
        fprintf(arquivo,"\n");
    }
    fclose(arquivo);
}

void index_m2(matriz<int>* Matriz,matriz<int>* Matriz_Resultante, int constante){
    std::cout << "A matriz: " << endl;
    Matriz->indexMatriz();
    std::cout << "Multiplicada pela constante " << constante << " é: " << endl;
    Matriz_Resultante->indexMatriz();
}

void index_m3(matriz<int>* Matriz,bool isIdentidade){
    std::cout << "A matriz: " << endl;
    Matriz->indexMatriz();
    std::cout << (isIdentidade ? "É" : "Não é") << " uma matriz identidade" << endl;
}

void index_m4(matriz<int>* Matriz_A, matriz<int>* Matriz_B, bool identica){
    std::cout << "A matriz 1: " << endl;
    Matriz_A->indexMatriz();
    std::cout << "A matriz 2: " << endl;
    Matriz_B->indexMatriz();
    std::cout << "As duas " << (identica ? "são" : "não são") << " identicas" << endl;
}

void index_m5(matriz<int>* Matriz_A, matriz<int>* Matriz_B, matriz<int>* Matriz_Resultante){
    std::cout << "A matriz 1: " << endl;
    Matriz_A->indexMatriz();
    std::cout << "A matriz 2: " << endl;
    Matriz_B->indexMatriz();
    std::cout << "A soma das matrizes é: " << endl;
    Matriz_Resultante->indexMatriz();
}

void index_m6(matriz<int>* Matriz){
    std::cout << "A nova matriz é: " << endl;
    Matriz->indexMatriz();
}

void index_m7(matriz<int>* Matriz){
    std::cout << "A nova matriz é: " << endl;
    Matriz->indexMatriz();
}

void index_m8(matriz<int>* Matriz,int value,bool existe,int linha){
    std::cout << "O valor " << value << " na matriz: " << endl;
    Matriz->indexMatriz();
    if(existe){
        std::cout << "Existe na linha " << linha << endl;
    } else {
        std::cout << "Não existe" << endl;
    }
}

void index_m9(matriz<int>* Matriz,int value,bool existe,int coluna){
    std::cout << "O valor " << value << " na matriz: " << endl;
    Matriz->indexMatriz();
    if(existe){
        std::cout << "Existe na coluna " << coluna << endl;
    } else {
        std::cout << "Não existe" << endl;
    }
}

void index_m10(matriz<int>* Matriz){
    std::cout << "A matriz transposta é: " << endl;
    Matriz->indexMatriz();
}