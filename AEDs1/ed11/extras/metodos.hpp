void e1()
{
    Array<int>* arranjoA = new Array<int>();
    Array<int>* arranjoB = new Array<int>();
    char arquivo_nameA[] = "DADOS1.TXT";
    char arquivo_nameB[] = "DADOS2.TXT";
    bool result = false;

    readRandoms_e(arranjoA);
    gravar_e(arranjoA, arquivo_nameA);
    readRandoms_e(arranjoB);
    gravar_e(arranjoB, arquivo_nameB);

    fread_int(arranjoA, arquivo_nameA);
    fread_int(arranjoB, arquivo_nameB);
    result = isDiferente(arranjoA, arranjoB);

    index_e1(arranjoA, arranjoB, result);
}

void e2()
{
    Array<int>* arranjoA = new Array<int>();
    Array<int>* arranjoB = new Array<int>();
    char arquivo_nameA[] = "DADOS1.TXT";
    char arquivo_nameB[] = "DADOS2.TXT";
    int qtde = 0;

    readRandoms_e(arranjoA);
    gravar_e(arranjoA, arquivo_nameA);
    readRandoms_e(arranjoB);
    gravar_e(arranjoB, arquivo_nameB);

    fread_int(arranjoA, arquivo_nameA);
    fread_int(arranjoB, arquivo_nameB);
    qtde = qtdeDiferencas(arranjoA, arranjoB);

    index_e2(arranjoA, arranjoB, qtde);
}
