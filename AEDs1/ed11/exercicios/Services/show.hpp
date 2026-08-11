void index_m1(Array<int>* a){
    std::cout << "Os números são:" << std::endl;
    a->index();
}

void gravar_m1(Array<int>* a,char arquivo_name[]){
    FILE* arquivo = fopen(arquivo_name,"wt");

    a->setPosition(0);
    fprintf(arquivo,"%d\n",a->getLength());
    for(int i = 0; i < a->getLength(); i = i + 1){
        fprintf(arquivo, "%d\n", a->getValue());
    }

    fclose(arquivo);
}

void index_m2(Array<int>* a,int maiorPar){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    std::cout << "O maior número par é: " << maiorPar << std::endl;
}

void index_m3(Array<int>* a,int valor){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    std::cout << "O maior número par multiplo de 5 é: " << valor << std::endl;
}

void index_m4(Array<int>* a,int valor,int i1,int i2){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    std::cout << "A soma entre os intervalos [" 
              << i1 << ":" << i2
              << "] é: " << valor << std::endl;
}

void index_m5(Array<int>* a,double valor,int i1,int i2){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    std::cout << "A media da soma dos intervalos [" 
              << i1 << ":" << i2
              << "] é: " << valor << std::endl;
}

void index_m6(Array<int>* a,bool result,int i1,int i2){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    if(result){
        std::cout << "Todos os valores estão entre [" << i1 << ":" << i2 << "]" << std::endl;
    } else {
        std::cout << "Não são todos os valores que estão entre [" << i1 << ":" << i2 << "]" << std::endl;
    }
}

void index_m7(Array<int>* a,bool result){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    if(result){
        std::cout << "Todos eles estão em ordem Decrescente" << std::endl;
    } else {
        std::cout << "Nem todos eles estão em ordem Decrescente" << std::endl;
    }
}

void index_m8(Array<int>* a, bool result, int value, int i1, int i2){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    if(result){
        std::cout << "O valor " << value << " existe no intervalo [" << i1 << ":" << i2 << "]" << std::endl;
    } else {
        std::cout << "O valor " << value << " não existe no intervalo [" << i1 << ":" << i2 << "]" << std::endl;
    }
}

void index_m9(Array<int>* a, int value, int i1, int i2){
    std::cout << "Dentre os números:" << std::endl;
    a->index();
    std::cout << "A constante " << value << " foi multiplicada nos valores do intervalo [" << i1 << ":" << i2 << "]" << std::endl;
}

void index_m10(Array<int>* a){
    std::cout << "Os números de forma organizada são:" << std::endl;
    a->index();
}