/*
 * lerIntervalo -> ler intervalos
 * createIntervalo -> criar intervalos
 * verificarIntervalo -> verificar se está tudo certo com seu intervalo
 * updateIntervalo -> criar novos intervalos
 * isIn_Intervalo -> verificar se o valor passado esta dentro do intervalo
 * indexIntervalo -> mostrar os intervalos
 * deleteIntervalo -> deletar o intervalo
**/

void lerIntervalo(int *a, int *b){
    bool v = false;
    int i1 = 0;
    int i2 = 0;

    do{
        IO_printf("Digite o limite inferior do intervalo: ");
        v = scanf("%d",&i1); getchar( );
        if(!v){ IO_printf("Valor invalido!"); }
    }while(!v);
    
    do{
        IO_printf("Digite o limite superior do intervalo: ");
        v = scanf("%d",&i2); getchar( );
        if(!v){ IO_printf("Valor invalido!"); }
    }while(!v);

    *a = i1;
    *b = i2;
}

Intervalo* createIntervalo(){
    Intervalo* retorno = (Intervalo*) malloc(sizeof(Intervalo)*1);
    int a = 0;
    int b = 0;

    lerIntervalo(&a,&b);

    if(a <= b){
        retorno->Intervalo_1 = a;
        retorno->Intervalo_2 = b;
    } else {
        retorno->Intervalo_1 = b;
        retorno->Intervalo_2 = a;
    }
    return retorno;
}

bool verificarIntervalo(Intervalo* i){
    bool retorno = true;
    if(i == NULL){
        IO_printf("Intervalo não criado!");
        retorno = false;
    }
    return retorno;
}

void updateIntervalo(Intervalo* i){
    int a = 0;
    int b = 0;
    if(verificarIntervalo(i)){
        lerIntervalo(&a,&b);
        if(a <= b){
            i->Intervalo_1 = a;
            i->Intervalo_2 = b;
        } else {
            i->Intervalo_1 = b;
            i->Intervalo_2 = a;
        }
    } else {
        IO_printf("Não foi possivel atualizar seu intervalo!");
    }
}

bool isIn_Intervalo(Intervalo* i,int valor){
    bool retorno = false;
    if(verificarIntervalo(i)){
        if(valor >= i->Intervalo_1 && valor <= i->Intervalo_2){
            retorno = true;
        }
    } else {
        IO_printf("Intervalo não existe!");
    }
    return retorno;
}

void indexIntervalo(Intervalo* i){
    if(verificarIntervalo(i)){
        IO_printf("[%d:%d]",i->Intervalo_1,i->Intervalo_2);
    } else {
        IO_printf("Não foi possivel mostrar seu intervalo!");
    }
}

void deleteIntervalo(Intervalo* i){
    if(verificarIntervalo(i)){
        i->Intervalo_1 = 0;
        i->Intervalo_2 = 0;
        free(i);
        i = NULL;
    } else {
        IO_printf("Seu intervalo já está excluidos!");
    }
}