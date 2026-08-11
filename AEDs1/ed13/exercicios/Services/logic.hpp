void testFile(string arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome.c_str(), "wt");
    fprintf(arquivo, "%s\n", "Arthur Victor Alves");
    fclose(arquivo);
}

void readFromFile(Usuario* u,string arquivo_nome){
    testFile(arquivo_nome);
    FILE* arquivo = fopen(arquivo_nome.c_str(), "rt");
    char buffer[100];

    if(fgets(buffer, 100, arquivo)){
        string nome(buffer);
        if(!nome.empty() && nome.back() == '\n') nome.pop_back();
        u->updateNome(nome);
    }

    fclose(arquivo);
}