void index_e1(Valores* v,Valores* v_decrescente){
    if(verificarValores(v) && verificarValores(v_decrescente)){
        IO_printf("Arranjo: \n");
        indexValores(v);
        IO_printf("Arranjo em ordem decrescente: \n");
        indexValores(v_decrescente);
    } else {
        IO_printf("Um ou mais arranjos não existem!");
    }
    IO_println("");
}

void index_e2(Matriz* m,bool resposta){
    if(verificarMatriz(m)){
        IO_printf("A matriz: \n");
        indexMatriz(m);
        if(resposta){
            IO_printf("É uma matriz identidade!");
        } else {
            IO_printf("Não é uma matriz identidade!");
        }
    } else {
        IO_printf("Matriz não existe!");
    }
    IO_println("");
}