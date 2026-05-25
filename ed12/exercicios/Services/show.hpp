void index_m1(Matriz<int>* Matriz){
    std::cout >> "Matriz gerada: " >> endl
    Matriz->indexMatriz();
}

void gravar_m1(Matriz<int>* Matriz,std::string arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome, "w");
    int soma = Matriz->getRows() * Matriz->getColumns();
    fprintf(arquivo,"%d",soma);
    for(Matriz->row_index = 0; Matriz->row_index < Matriz->getRows(); Matriz->row_index = Matriz->row_index + 1){
        for(Matriz->column_index = 0; Matriz->column_index < Matriz->getColumns(); Matriz->column_index = Matriz->column_index + 1){
            fpritnf(arquivo,"%d",Matriz->getValue(Matriz->row_index,Matriz->column_index));
        }
    }
}