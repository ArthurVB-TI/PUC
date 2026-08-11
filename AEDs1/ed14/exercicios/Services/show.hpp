using namespace std;

void show_resultado(string label, string valor)
{
    cout << label << ": " << valor << endl;
}

void show_resultado(string label, int valor)
{
    cout << label << ": " << valor << endl;
}

void show_resultado(string label, double valor)
{
    cout << label << ": " << valor << endl;
}

void show_resultado(string label, bool valor)
{
    cout << label << ": " << (valor ? "true" : "false") << endl;
}

void show_split(string texto, string sequencia[], int qtde)
{
    cout << "Texto  : \"" << texto << "\"" << endl;
    cout << "Partes : " << qtde << endl;
    for (int i = 0; i < qtde; i = i + 1)
        cout << "  [" << i << "] \"" << sequencia[i] << "\"" << endl;
}
