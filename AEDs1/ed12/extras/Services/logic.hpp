bool deCimaPraBaixo(matriz<int>* m){
    bool retorno = true;
    int l = m->getRows();
    int c = m->getColumns();
    int valorAntigo = 0;
    int valorAtual = 0;
    if(l > 0 && c > 0){
        for(int i = 0; i < c && retorno; i = i + 1){
            for(int j = 0; j < l && retorno; j = j + 1){
                valorAtual = m->getValue(j,i);
                if(!(i == j && i == 0)){
                    if(valorAtual < valorAntigo){
                        retorno = false;
                    }
                }
                valorAntigo = valorAtual;
            }
        }
    }
    return retorno;
}

bool deBaixoPraCima(matriz<int>* m){
    bool retorno = true;
    int l = m->getRows();
    int c = m->getColumns();
    int valorAntigo = 0;
    int valorAtual = 0;
    if(l > 0 && c > 0){
        for(int i = 0; i < c && retorno; i = i + 1){
            for(int j = l - 1; j >= 0 && retorno; j = j - 1){
                valorAtual = m->getValue(j,i);
                if(!(i == j && i == 0)){
                    if(valorAtual < valorAntigo){
                        retorno = false;
                    }
                }
                valorAntigo = valorAtual;
            }
        }
    }
    return retorno;
}