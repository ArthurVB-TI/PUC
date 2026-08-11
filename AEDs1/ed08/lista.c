#include "io.h"

void printIntArray(int n, int array[])
{
    int x = 0;

    for (x = 0; x < n; x = x + 1)
    {
        IO_printf("%2d: %d\n", x, array[x]);
    }
}

void readIntArray(int n, int array[])
{
    int x = 0;
    int y = 0;
    chars text = IO_new_chars(STR_SIZE);

    for (x = 0; x < n; x = x + 1)
    {
        strcpy(text, STR_EMPTY);

        y = IO_readint(
            IO_concat(
                IO_concat(text, IO_toString_d(x)),
                " : "
            )
        );

        array[x] = y;
    }
}

void fprintIntArray(chars fileName, int n, int array[])
{
    FILE* arquivo = fopen(fileName, "wt");
    int x = 0;

    IO_fprintf(arquivo, "%d\n", n);

    for (x = 0; x < n; x = x + 1)
    {
        IO_fprintf(arquivo, "%d\n", array[x]);
    }

    fclose(arquivo);
}

int freadArraySize(chars fileName)
{
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");

    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }

    return n;
}

void freadIntArray(chars fileName, int n, int array[])
{
    int x = 0;
    int y = 0;
    FILE* arquivo = fopen(fileName, "rt");

    IO_fscanf(arquivo, "%d", &x);

    if (n <= 0 || n > x)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        x = 0;

        while (!feof(arquivo) && x < n)
        {
            IO_fscanf(arquivo, "%d", &y);
            array[x] = y;
            x = x + 1;
        }
    }
}

void copyIntArray(int n, int copy[], int array[])
{
    int x = 0;

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        for (x = 0; x < n; x = x + 1)
        {
            copy[x] = array[x];
        }
    }
}

int sumIntArray(int n, int array[])
{
    int soma = 0;
    int x = 0;

    for (x = 0; x < n; x = x + 1)
    {
        soma = soma + array[x];
    }

    return soma;
}

bool isAllZeros(int n, int array[])
{
    bool result = true;
    int x = 0;

    while (x < n && result)
    {
        result = result && (array[x] == 0);
        x = x + 1;
    }

    return result;
}

void addIntArray(int n, int array3[], int array1[], int k, int array2[])
{
    int x = 0;

    for (x = 0; x < n; x = x + 1)
    {
        array3[x] = array1[x] + k * array2[x];
    }
}

bool isEqual(int n, int array1[], int array2[])
{
    bool result = true;
    int x = 0;

    while (x < n && result)
    {
        result = result && (array1[x] == array2[x]);
        x = x + 1;
    }

    return result;
}

bool searchArray(int value, int n, int array[])
{
    bool result = false;
    int x = 0;

    while (x < n && !result)
    {
        result = (value == array[x]);
        x = x + 1;
    }

    return result;
}

void method_01()
{
    int array[] = { 1, 2, 3, 4, 5 };

    IO_id("Method_01 - v0.0");
    printIntArray(5, array);
    IO_pause("Apertar ENTER para continuar");
}

void method_02()
{
    int n = 5;
    int array[n];

    IO_id("Method_02 - v0.0");
    readIntArray(n, array);

    IO_printf("\n");
    printIntArray(n, array);

    IO_pause("Apertar ENTER para continuar");
}

void method_03()
{
    int n = 5;
    int array[n];

    IO_id("Method_03 - v0.0");
    readIntArray(n, array);

    IO_printf("\n");
    fprintIntArray("ARRAY1.TXT", n, array);

    IO_pause("Apertar ENTER para continuar");
}

void method_04()
{
    int n = 0;

    IO_id("Method_04 - v0.0");

    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        int array[n];

        freadIntArray("ARRAY1.TXT", n, array);

        IO_printf("\n");
        printIntArray(n, array);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method_05()
{
    int n = 0;

    IO_id("Method_05 - v0.0");

    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        int array[n];
        int other[n];

        freadIntArray("ARRAY1.TXT", n, array);
        copyIntArray(n, other, array);

        IO_printf("\nOriginal\n");
        printIntArray(n, array);

        IO_printf("\nCopia\n");
        printIntArray(n, other);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method_06()
{
    int n = 0;

    IO_id("Method_06 - v0.0");

    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        int array[n];

        freadIntArray("ARRAY1.TXT", n, array);

        IO_printf("\nSoma = %d\n", sumIntArray(n, array));
    }

    IO_pause("Apertar ENTER para continuar");
}

void method_07()
{
    int n = 5;

    int array1[] = { 0, 0, 0, 0, 0 };
    int array2[] = { 1, 2, 3, 4, 5 };
    int array3[] = { 1, 2, 0, 4, 5 };

    IO_id("Method_07 - v0.0");

    IO_println("\nArray1");
    printIntArray(n, array1);
    IO_printf("isAllZeros(array1) = %d", isAllZeros(n, array1));

    IO_println("\nArray2");
    printIntArray(n, array2);
    IO_printf("isAllZeros(array2) = %d", isAllZeros(n, array2));

    IO_println("\nArray3");
    printIntArray(n, array3);
    IO_printf("isAllZeros(array3) = %d", isAllZeros(n, array3));

    IO_pause("Apertar ENTER para continuar");
}

void method_08()
{
    int n = 0;

    IO_id("Method_08 - v0.0");

    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        int array[n];
        int other[n];
        int sum[n];

        freadIntArray("ARRAY1.TXT", n, array);
        copyIntArray(n, other, array);

        IO_printf("\nOriginal\n");
        printIntArray(n, array);

        IO_printf("\nCopia\n");
        printIntArray(n, other);

        addIntArray(n, sum, array, (-2), other);

        IO_printf("\nSoma\n");
        printIntArray(n, sum);
    }

    IO_pause("Apertar ENTER para continuar");
}

void method_09()
{
    int n = 0;

    IO_id("Method_09 - v0.0");

    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        int array[n];
        int other[n];

        freadIntArray("ARRAY1.TXT", n, array);
        copyIntArray(n, other, array);

        IO_printf("\nOriginal\n");
        printIntArray(n, array);

        IO_printf("\nCopia\n");
        printIntArray(n, other);

        IO_printf("\nIguais = %d\n", isEqual(n, array, other));

        other[0] = (-1) * other[0];

        IO_printf("\nCopia alterada\n");
        printIntArray(n, other);

        IO_printf("\nIguais = %d\n", isEqual(n, array, other));
    }

    IO_pause("Apertar ENTER para continuar");
}

void method_10()
{
    int n = 0;
    int value = 0;

    IO_id("Method_10 - v0.0");

    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        int array[n];

        freadIntArray("ARRAY1.TXT", n, array);

        IO_printf("\nOriginal\n");
        printIntArray(n, array);

        value = array[0];
        IO_printf("\nProcurar por (%d) = %d\n", value, searchArray(value, n, array));

        value = array[n / 2];
        IO_printf("\nProcurar por (%d) = %d\n", value, searchArray(value, n, array));

        value = array[n - 1];
        IO_printf("\nProcurar por (%d) = %d\n", value, searchArray(value, n, array));

        value = (-1);
        IO_printf("\nProcurar por (%d) = %d\n", value, searchArray(value, n, array));
    }

    IO_pause("Apertar ENTER para continuar");
}

int main()
{
	int x = 0;

	do
	{
		IO_id("EXEMPLO0700 - Programa - v0.0");

		IO_println("Opcoes");
		IO_println("0 - parar");
		IO_println("1 - Method_01");
		IO_println("2 - Method_02");
		IO_println("3 - Method_03");
		IO_println("4 - Method_04");
		IO_println("5 - Method_05");
		IO_println("6 - Method_06");
		IO_println("7 - Method_07");
		IO_println("8 - Method_08");
		IO_println("9 - Method_09");
		IO_println("10 - Method_10");
		IO_println("");

		x = IO_readint("Entrar com uma opcao: ");

		switch(x)
		{
			case 0: break;
			case 1: method_01(); break;
			case 2: method_02(); break;
			case 3: method_03(); break;
			case 4: method_04(); break;
			case 5: method_05(); break;
			case 6: method_06(); break;
			case 7: method_07(); break;
			case 8: method_08(); break;
			case 9: method_09(); break;
			case 10: method_10(); break;
			default:
				IO_pause("Valor invalido");
		}
	}
	while(x != 0);

	IO_pause("Apertar ENTER para terminar");

	return 0;
}