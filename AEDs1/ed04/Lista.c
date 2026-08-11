#include "io.h"

void method_01()
{
	int quantidade = 0;
	int valor = 0;
	int controle = 0;

	IO_id("Method_01 - v0.0");

	quantidade = IO_readint("Entrar com uma quantidade: ");

	controle = 1;
	while(controle <= quantidade)
	{
		valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));
		printf("\n%s%d", "valor = ", valor);
		controle = controle + 1;
	}

	IO_pause("Apertar ENTER para continuar");
}

bool positive(int x)
{
	bool result = false;

	if(x > 0)
	{
		result = true;
	}

	return(result);
}

void method_02()
{
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;

	IO_id("Method_02 - v0.0");

	quantidade = IO_readint("Entrar com uma quantidade: ");

	controle = 1;
	while(controle <= quantidade)
	{
		valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));

		if(positive(valor))
		{
			contador = contador + 1;
		}

		controle = controle + 1;
	}

	IO_printf("%s%d\n", "Positivos = ", contador);

	IO_pause("Apertar ENTER para continuar");
}

bool belongsTo(int x, int inferior, int superior)
{
	bool result = false;

	if(inferior < x && x < superior)
	{
		result = true;
	}

	return(result);
}

void method_03()
{
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;

	IO_id("Method_03 - v0.0");

	quantidade = IO_readint("Entrar com uma quantidade: ");

	controle = 1;
	while(controle <= quantidade)
	{
		valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));

		if(belongsTo(valor, 0, 100))
		{
			contador = contador + 1;
		}

		controle = controle + 1;
	}

	IO_printf("%s%d\n", "Positivos menores que 100 = ", contador);

	IO_pause("Apertar ENTER para continuar");
}

bool even(int x)
{
	bool result = false;

	if(x % 2 == 0)
	{
		result = true;
	}

	return(result);
}

void method_04()
{
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;

	IO_id("Method_04 - v0.0");

	quantidade = IO_readint("Entrar com uma quantidade: ");

	controle = 1;
	while(controle <= quantidade)
	{
		valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));

		if(belongsTo(valor, 0, 100) && even(valor))
		{
			contador = contador + 1;
		}

		controle = controle + 1;
	}

	IO_printf("%s%d\n", "Positivos menores que 100 e pares = ", contador);

	IO_pause("Apertar ENTER para continuar");
}

void method_05()
{
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;
	bool ok = false;

	IO_id("Method_05 - v0.0");

	quantidade = IO_readint("Entrar com uma quantidade: ");

	controle = 1;
	while(controle <= quantidade)
	{
		valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)), ": "));

		ok = belongsTo(valor, 0, 100);
		ok = ok && even(valor);

		if(ok)
		{
			contador = contador + 1;
		}

		controle = controle + 1;
	}

	IO_printf("%s%d\n", "Positivos menores que 100 e pares = ", contador);

	IO_pause("Apertar ENTER para continuar");
}

bool isLowerCase(char x)
{
	bool result = false;

	if('a' <= x && x <= 'z')
	{
		result = true;
	}

	return(result);
}

void method_06()
{
	chars palavra = IO_new_chars(STR_SIZE);
	int tamanho = 0;
	int posicao = 0;
	char simbolo = '_';
	int contador = 0;

	IO_id("Method_06 - v0.0");

	palavra = IO_readstring("Entrar com uma palavra: ");

	tamanho = strlen(palavra);

	for(posicao = 0; posicao < tamanho; posicao = posicao + 1)
	{
		simbolo = palavra[posicao];

		if(isLowerCase(simbolo))
		{
			contador = contador + 1;
		}
	}

	IO_printf("%s%d\n", "Minusculas = ", contador);

	IO_pause("Apertar ENTER para continuar");
}

void method_07()
{
	chars palavra = IO_new_chars(STR_SIZE);
	int tamanho = 0;
	int posicao = 0;
	char simbolo = '_';
	int contador = 0;

	IO_id("Method_07 - v0.0");

	palavra = IO_readstring("Entrar com uma palavra: ");

	tamanho = strlen(palavra);

	for(posicao = 0; posicao < tamanho; posicao = posicao + 1)
	{
		simbolo = palavra[posicao];

		if(isLowerCase(simbolo))
		{
			IO_printf("%c ", simbolo);
			contador = contador + 1;
		}
	}

	IO_printf("\n%s%d\n", "Minusculas = ", contador);

	IO_pause("Apertar ENTER para continuar");
}

void method_08()
{
	chars palavra = IO_new_chars(STR_SIZE);
	int tamanho = 0;
	int posicao = 0;
	char simbolo = '_';
	int contador = 0;
	chars minusculas = IO_new_chars(STR_SIZE);

	strcpy(minusculas, STR_EMPTY);

	IO_id("Method_08 - v0.0");

	palavra = IO_readstring("Entrar com uma palavra: ");

	tamanho = strlen(palavra);

	for(posicao = 0; posicao < tamanho; posicao = posicao + 1)
	{
		simbolo = palavra[posicao];

		if(isLowerCase(simbolo))
		{
			minusculas = IO_concat(minusculas, IO_toString_c(simbolo));
			contador = contador + 1;
		}
	}

	IO_printf("\n%s%d [%s]\n", "Minusculas = ", contador, minusculas);

	IO_pause("Apertar ENTER para continuar");
}

bool isDigit(char x)
{
	bool result = false;

	if('0' <= x && x <= '9')
	{
		result = true;
	}

	return(result);
}

void method_09()
{
	chars palavra = IO_new_chars(STR_SIZE);
	int tamanho = 0;
	int posicao = 0;
	char simbolo = '_';
	int contador = 0;

	IO_id("Method_09 - v0.0");

	palavra = IO_readstring("Entrar com caracteres: ");

	tamanho = strlen(palavra);

	for(posicao = 0; posicao < tamanho; posicao = posicao + 1)
	{
		simbolo = palavra[posicao];

		if(isDigit(simbolo))
		{
			IO_printf("%c ", simbolo);
			contador = contador + 1;
		}
	}

	IO_printf("\n%s%d\n", "Algarismos = ", contador);

	IO_pause("Apertar ENTER para continuar");
}

bool isADigit(char x)
{
	return('0' <= x && x <= '9');
}

chars concatADigit(chars string, char digit)
{
	return(IO_concat(string, IO_toString_c(digit)));
}

void method_10()
{
	chars palavra = IO_new_chars(STR_SIZE);
	int tamanho = 0;
	int posicao = 0;
	char simbolo = '_';
	chars digitos = IO_new_chars(STR_SIZE);

	strcpy(digitos, STR_EMPTY);

	IO_id("Method_10 - v0.0");

	palavra = IO_readstring("Entrar com uma palavra: ");

	tamanho = strlen(palavra);

	for(posicao = 0; posicao < tamanho; posicao = posicao + 1)
	{
		simbolo = palavra[posicao];

		if(isADigit(simbolo))
		{
			digitos = concatADigit(digitos, simbolo);
		}
	}

	IO_printf("\n%s%d [%s]\n", "Algarismos = ", strlen(digitos), digitos);

	IO_pause("Apertar ENTER para continuar");
}

int main()
{
	int x = 0;

	do
	{
		IO_id("EXEMPLO0400-Programa-v0.0");

		IO_println("Opcoes");
		IO_println("0 - parar");
		IO_println("1 - Metodo 01");
		IO_println("2 - Metodo 02");
		IO_println("3 - Metodo 03");
		IO_println("4 - Metodo 04");
		IO_println("5 - Metodo 05");
		IO_println("6 - Metodo 06");
		IO_println("7 - Metodo 07");
		IO_println("8 - Metodo 08");
		IO_println("9 - Metodo 09");
		IO_println("10 - Metodo 10");
		IO_println("");

		x = IO_readint("Entrar com uma opcao:");

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
				IO_pause(IO_concat("Valor diferente das opcoes[0:10](", IO_concat(IO_toString_d(x), ")")));
		}
	}
	while(x != 0);

	IO_pause("Apertar ENTER para terminar");

	return 0;
}