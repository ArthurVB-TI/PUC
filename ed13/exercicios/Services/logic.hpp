void testFile(string arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome.c_str(), "wt");
    fprintf(arquivo, "%s\n", "Arthur Victor Alves");
    fclose(arquivo);
}

void readFromFile(Usuario* u,string arquivo_nome){
    testFile(arquivo_nome);
    FILE* arquivo = fopen(arquivo_nome.c_str(), "rt");
    string nome = "";

    fgets(&nome[0], 100, arquivo);
    
    if(nome != ""){
        u->updateNome(nome);
    }

    fclose(arquivo);
}