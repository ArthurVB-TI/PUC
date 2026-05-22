void m1()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";

    readRandoms(arranjo);

    index_m1(arranjo);
    gravar_m1(arranjo, arquivo_name);
}

void m2()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    int maiorPar = 0;

    fread_int(arranjo,arquivo_name);
    maiorPar = getMaiorPar(arranjo);

    index_m2(arranjo,maiorPar);
}

void m3()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    int value = 0;

    fread_int(arranjo,arquivo_name);
    value = getMaiorPar_MultiploDe5(arranjo);

    index_m3(arranjo,value);
}

void m4()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    int i1 = 0;
    int i2 = 0;
    int soma = 0;

    fread_int(arranjo, arquivo_name);
    soma = somarEntreIntervalos(arranjo,&i1,&i2);

    index_m4(arranjo, soma,i1,i2);
}

void m5()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    int i1 = 0;
    int i2 = 0;
    double media = 0;

    fread_int(arranjo, arquivo_name);
    media = mediaEntreIntervalos(arranjo,&i1,&i2);

    index_m5(arranjo, media,i1,i2);
}

void m6()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    int i1 = 1;
    int i2 = 100;
    bool verificar = false;

    fread_int(arranjo, arquivo_name);
    verificar = verificarEntreIntervalos(arranjo,i1,i2);

    index_m6(arranjo, verificar,i1,i2);
}

void m7()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    bool is_Decrescente = false;

    fread_int(arranjo, arquivo_name);
    is_Decrescente = isDecrescente(arranjo);

    index_m7(arranjo, is_Decrescente);
}

void m8()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    int value = 0;
    int i1 = 0;
    int i2 = 0;
    bool existe = false;

    value = IO_readValue();
    fread_int(arranjo, arquivo_name);
    existe = isExistente(arranjo, value, &i1, &i2);

    index_m8(arranjo, existe, value, i1, i2);
}

void m9()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";
    int constante = 0;
    int i1 = 0;
    int i2 = 0;

    constante = IO_readValue();
    fread_int(arranjo, arquivo_name);
    multiplicarArray(arranjo, constante, &i1, &i2);

    index_m9(arranjo, constante, i1, i2);
}

void m10()
{
    Array<int>* arranjo = new Array<int>();
    char arquivo_name[] = "DADOS.TXT";

    fread_int(arranjo, arquivo_name);
    sortDown(arranjo);

    index_m10(arranjo);
}