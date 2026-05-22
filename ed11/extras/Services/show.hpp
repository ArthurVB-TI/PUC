void gravar_e(Array<int>* a, char arquivo_name[]){
    FILE* arquivo = fopen(arquivo_name, "wt");

    a->setPosition(0);
    fprintf(arquivo, "%d\n", a->getLength());
    for(int i = 0; i < a->getLength(); i = i + 1){
        fprintf(arquivo, "%d\n", a->getValue());
    }

    fclose(arquivo);
}

void index_e1(Array<int>* a, Array<int>* b, bool result){
    std::cout << "Arranjo A:" << std::endl;
    a->index();
    std::cout << "Arranjo B:" << std::endl;
    b->index();
    if(result){
        std::cout << "Os arranjos são diferentes em pelo menos uma posição." << std::endl;
    } else {
        std::cout << "Os arranjos são iguais em todas as posições." << std::endl;
    }
}

void index_e2(Array<int>* a, Array<int>* b, int qtde){
    std::cout << "Arranjo A:" << std::endl;
    a->index();
    std::cout << "Arranjo B:" << std::endl;
    b->index();
    if(qtde < 0){
        std::cout << "Os arranjos possuem tamanhos diferentes." << std::endl;
    } else {
        std::cout << "A quantidade de diferenças entre os arranjos é: " << qtde << std::endl;
    }
}
