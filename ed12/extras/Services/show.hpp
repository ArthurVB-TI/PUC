void index(matriz<int>* Matriz,bool ordem){
    std::cout << "A matriz: " << endl;
    Matriz->indexMatriz();
    std::cout << (ordem ? "Está em ordem" : "Não está em ordem") << endl;
}