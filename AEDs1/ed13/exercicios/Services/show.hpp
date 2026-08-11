void index_m1(Usuario* u){
    u->indexNome();
}

void index_m2(Usuario* u){
    u->indexTelefone();
}

void index_m3(Usuario* u){
    u->indexTelefone();
}

void index_m4(Usuario* u){
    u->indexNome();
}

void index_m5(Usuario* u){
    u->indexNome();
}

void index_m6(Usuario* u){
    u->indexTelefone();
}

void index_m7(Usuario* u, int n){
    std::cout << "Quantidade de telefones: " << n << std::endl;
    u->indexTelefone();
}

void index_m8(Usuario* u){
    u->indexTelefone();
}

void index_m9(Usuario* u){
    u->indexTelefone();
}

void index_m10(Usuario* u){
    std::cout << "Telefones restantes: " << u->phones() << std::endl;
    u->indexTelefone();
}
