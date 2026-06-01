void e1(){
    matriz<int>* Matriz = new matriz<int>();
    bool is_inOrdem = false;

    Matriz->setMatrizLength();
    Matriz->setRandomMatriz();

    is_inOrdem = deCimaPraBaixo(Matriz);

    index(Matriz,is_inOrdem);
}

void e2(){
    matriz<int>* Matriz = new matriz<int>();
    bool is_inOrdem = false;

    Matriz->setMatrizLength();
    Matriz->setRandomMatriz();

    is_inOrdem = deBaixoPraCima(Matriz);

    index(Matriz,is_inOrdem);
}