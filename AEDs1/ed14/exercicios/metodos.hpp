using namespace std;

Erro<string> obj;

void m1()
{
    string texto = IO_nextLine("Digite um valor inteiro: ");
    int resultado = obj.getInt(texto);
    show_resultado("getInt(\"" + texto + "\")", resultado);
}

void m2()
{
    string texto = IO_nextLine("Digite um valor real: ");
    double resultado = obj.getDouble(texto);
    show_resultado("getDouble(\"" + texto + "\")", resultado);
}

void m3()
{
    string texto = IO_nextLine("Digite um valor logico (true/false/T/F/0/1): ");
    bool resultado = false;
    try
    {
        resultado = obj.getBoolean(texto);
    }
    catch (const invalid_argument& e)
    {
        cout << "ERRO: " << e.what() << endl;
        return;
    }
    show_resultado("getBoolean(\"" + texto + "\")", resultado);
}

void m4()
{
    string texto = IO_nextLine("Digite o texto principal: ");
    string sub   = IO_nextLine("Digite o subtexto a procurar: ");
    bool resultado = obj.contains(texto, sub);
    show_resultado("contains(\"" + texto + "\", \"" + sub + "\")", resultado);
}

void m5()
{
    string texto = IO_nextLine("Digite o texto: ");
    string resultado = obj.toUpperCase(texto);
    show_resultado("toUpperCase(\"" + texto + "\")", resultado);
}

void m6()
{
    string texto = IO_nextLine("Digite o texto: ");
    string resultado = obj.toLowerCase(texto);
    show_resultado("toLowerCase(\"" + texto + "\")", resultado);
}

void m7()
{
    string texto  = IO_nextLine("Digite o texto: ");
    char original = IO_readchar("Digite o caractere original: ");
    char novo     = IO_readchar("Digite o novo caractere: ");
    string resultado = obj.replace(texto, original, novo);
    show_resultado("replace(\"" + texto + "\", '" + original + "', '" + novo + "')", resultado);
}

void m8()
{
    string texto = IO_nextLine("Digite o texto para cifrar: ");
    string resultado = obj.encrypt(texto);
    show_resultado("encrypt(\"" + texto + "\")", resultado);
}

void m9()
{
    string texto = IO_nextLine("Digite o texto cifrado para decifrar: ");
    string resultado = obj.decrypt(texto);
    show_resultado("decrypt(\"" + texto + "\")", resultado);
}

void m10()
{
    string texto = IO_nextLine("Digite o texto para separar por espacos: ");
    string sequencia[100];
    int qtde = splitTexto(texto, ' ', sequencia);
    show_split(texto, sequencia, qtde);
}

void mE1()
{
    string texto = IO_nextLine("Digite o texto: ");
    char sep = IO_readchar("Digite o delimitador: ");
    string sequencia[100];
    int qtde = splitTexto(texto, sep, sequencia);
    show_split(texto, sequencia, qtde);
}

void mE2()
{
    string texto = IO_nextLine("Digite o texto para inverter: ");
    string resultado = obj.invertido(texto);
    show_resultado("invertido(\"" + texto + "\")", resultado);
}
