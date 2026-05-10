#include "io.h"

void writeInts(chars fileName, int x)
{
	FILE* arquivo = fopen(fileName, "wt");
	int y = 0;

	for(y = 1; y <= x; y = y + 1)
	{
		fprintf(arquivo, "%d\n", y);
	}

	fclose(arquivo);
}

void method_01()
{
	IO_id("Method_01 - v0.0");

	writeInts("DADOS1.TXT", 10);

	IO_pause("Apertar ENTER para continuar");
}

void readInts(chars fileName)
{
	FILE* arquivo = fopen(fileName, "rt");
	int x = 0;

	fscanf(arquivo, "%d", &x);

	while(!feof(arquivo))
	{
		printf("%d\n", x);
		fscanf(arquivo, "%d", &x);
	}

	fclose(arquivo);
}

void method_02()
{
	IO_id("Method_02 - v0.0");

	readInts("DADOS1.TXT");

	IO_pause("Apertar ENTER para continuar");
}

void writeDoubles(chars fileName, int x)
{
	FILE* arquivo = fopen(fileName, "wt");
	int y = 0;

	IO_fprintf(arquivo, "%d\n", x);

	for(y = 1; y <= x; y = y + 1)
	{
		IO_fprintf(arquivo, "%lf\n", (0.1 * y));
	}

	fclose(arquivo);
}

void method_03()
{
	IO_id("Method_03 - v0.0");

	writeDoubles("DADOS2.TXT", 10);

	IO_pause("Apertar ENTER para continuar");
}

void readDoubles(chars fileName)
{
	FILE* arquivo = fopen(fileName, "rt");
	int x = 0;
	int y = 1;
	double z = 0.0;

	fscanf(arquivo, "%d", &x);

	while(!feof(arquivo) && y <= x)
	{
		fscanf(arquivo, "%lf", &z);
		printf("%2d: %lf\n", y, z);
		y = y + 1;
	}

	fclose(arquivo);
}

void method_04()
{
	IO_id("Method_04 - v0.0");

	readDoubles("DADOS2.TXT");

	IO_pause("Apertar ENTER para continuar");
}

void writeText(chars fileName)
{
	FILE* arquivo = fopen(fileName, "wt");
	chars linha = IO_new_chars(STR_SIZE);

	IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");

	do
	{
		strcpy(linha, IO_readln(""));
		IO_fprintf(arquivo, "%s\n", linha);
	}
	while(strcmp("PARAR", linha) != 0);

	fclose(arquivo);
}

void method_05()
{
	IO_id("Method_05 - v0.0");

	writeText("DADOS3.TXT");

	IO_pause("Apertar ENTER para continuar");
}

void readText(chars fileName)
{
	FILE* arquivo = fopen(fileName, "rt");
	chars linha = IO_new_chars(STR_SIZE);

	strcpy(linha, IO_freadln(arquivo));

	while(!feof(arquivo) && strcmp("PARAR", linha) != 0)
	{
		printf("%s\n", linha);
		strcpy(linha, IO_freadln(arquivo));
	}

	fclose(arquivo);
}

void method_06()
{
	IO_id("Method_06 - v0.0");

	readText("DADOS3.TXT");

	IO_pause("Apertar ENTER para continuar");
}

void copyText(chars fileOut, chars fileIn)
{
	FILE* saida = fopen(fileOut, "wt");
	FILE* entrada = fopen(fileIn, "rt");
	chars linha = IO_new_chars(STR_SIZE);
	int contador = 0;

	strcpy(linha, IO_freadln(entrada));

	while(!feof(entrada))
	{
		contador = contador + 1;

		if(strcmp("PARAR", linha) != 0)
		{
			IO_fprintln(saida, linha);
		}

		strcpy(linha, IO_freadln(entrada));
	}

	IO_printf("Lines read = %d\n", contador);

	fclose(saida);
	fclose(entrada);
}

void method_07()
{
	IO_id("Method_07 - v0.0");

	copyText("DADOS4.TXT", "DADOS3.TXT");

	IO_pause("Apertar ENTER para continuar");
}

void appendText(chars fileName)
{
	FILE* arquivo = fopen(fileName, "at");
	chars linha = IO_new_chars(STR_SIZE);

	IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");

	do
	{
		strcpy(linha, IO_readln(""));
		IO_fprintln(arquivo, linha);
	}
	while(strcmp("PARAR", linha) != 0);

	fclose(arquivo);
}

void method_08()
{
	IO_id("EXEMPLO0710 - Method_08 - v0.0");

	appendText("DADOS4.TXT");

	IO_pause("Apertar ENTER para continuar");
}

void readWords(chars fileName)
{
	FILE* arquivo = fopen(fileName, "rt");
	chars linha = IO_new_chars(STR_SIZE);

	strcpy(linha, IO_fread(arquivo));

	while(!feof(arquivo) && strcmp("PARAR", linha) != 0)
	{
		printf("%s\n", linha);
		strcpy(linha, IO_fread(arquivo));
	}

	fclose(arquivo);
}

void method_09()
{
	IO_id("Method_09 - v0.0");

	readWords("DADOS4.TXT");

	IO_pause("Apertar ENTER para continuar");
}

bool searchWord(chars fileName, chars word)
{
	FILE* arquivo = fopen(fileName, "rt");
	chars linha = IO_new_chars(STR_SIZE);

	strcpy(linha, IO_fread(arquivo));

	while(!feof(arquivo) && strcmp(word, linha) != 0)
	{
		strcpy(linha, IO_fread(arquivo));
	}

	fclose(arquivo);

	return(strcmp(word, linha) == 0);
}

void method_10()
{
	IO_id("Method_10 - v0.0");

	IO_printf("Procurar (\"%s\") = %d\n", "pqr", searchWord("DADOS4.TXT", "pqr"));
	IO_printf("Procurar (\"%s\") = %d\n", "pqs", searchWord("DADOS4.TXT", "pqs"));

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