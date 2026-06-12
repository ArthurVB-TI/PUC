using namespace std;

int splitTexto(string texto, char sep, string sequencia[])
{
    int qtde = 0;
    string atual = "";

    for (int i = 0; i <= (int)texto.length(); i = i + 1)
    {
        char c = (i < (int)texto.length()) ? texto[i] : sep;
        if (c == sep)
        {
            if (atual.length() > 0)
            {
                sequencia[qtde] = atual;
                qtde = qtde + 1;
                atual = "";
            }
        }
        else
        {
            atual = atual + c;
        }
    }
    return qtde;
}
