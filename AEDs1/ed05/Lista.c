#include "io.h"

void method_01a(int x)
{
	int y = 1;
	while(y <= x)
	{
		IO_printf("%s%d\n", "Valor = ", y);
		y = y + 1;
	}
}

void method_02a(int x)
{
	int y = 1;
	int z = 2;
	while(y <= x)
	{
		IO_printf("%d: %d\n", y, z);
		z = z + 2;
		y = y + 1;
	}
}

void method_03a(int x)
{
	int y = 1;
	int z = 0;
	while(y <= x)
	{
		z = 2 * y;
		IO_printf("%d: %d\n", y, z);
		y = y + 1;
	}
}

void method_04a(int x)
{
	int y = x;
	int z = 0;
	while(y > 0)
	{
		z = 2 * y;
		IO_printf("%d: %d\n", y, z);
		y = y - 1;
	}
}

void method_05a(int x)
{
	int y = 0;
	for(y = x; y > 0; y = y - 1)
	{
		IO_printf("%d: %d\n", y, (2 * y));
	}
}

int somarValores(int x)
{
	int soma = 1;
	int y = 0;
	for(y = 1; y <= (x - 1); y = y + 1)
	{
		IO_printf("%d: %d\n", y, (2 * y));
		soma = soma + (2 * y);
	}
	return(soma);
}

double somarFracao1(int x)
{
	double soma = 1.0;
	double numerador = 0.0;
	double denominador = 0.0;
	int y = 0;
	for(y = 1; y <= (x - 1); y = y + 1)
	{
		numerador = 1.0;
		denominador = 2.0 * y;
		IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y, numerador, denominador, (numerador / denominador));
		soma = soma + (1.0) / (2.0 * y);
	}
	return(soma);
}

double somarFracao2(int x)
{
	double soma = 1.0;
	double numerador = 0.0;
	double denominador = 0.0;
	int y = 0;
	IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);
	for(y = 1; y <= (x - 1); y = y + 1)
	{
		numerador = 2.0 * y - 1;
		denominador = 2.0 * y;
		IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y + 1, numerador, denominador, (numerador / denominador));
		soma = soma + numerador / denominador;
	}
	return(soma);
}

double somarFracao3(int x)
{
	double soma = 1.0;
	int y = 0;
	IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);
	for(y = 1; y < x; y = y + 1)
	{
		IO_printf("%d: %7.4lf/%7.4lf = %7.4lf\n", y + 1, (2.0 * y), (2.0 * y + 1), ((2.0 * y) / (2.0 * y + 1)));
		soma = soma + (2.0 * y) / (2.0 * y + 1);
	}
	return(soma);
}

int multiplicarValores(int x)
{
	int produto = 1;
	int y = 0;
	for(y = 1; y <= x; y = y + 1)
	{
		IO_printf("%d: %d\n", y, (2 * y - 1));
		produto = produto * (2 * y - 1);
	}
	return(produto);
}

void method_01()
{
	IO_id(" Method_01 - v0.0");
	method_01a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_02()
{
	IO_id("Method_02 - v0.0");
	method_02a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_03()
{
	IO_id(" Method_03 - v0.0");
	method_03a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_04()
{
	IO_id("Method_04 - v0.0");
	method_04a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_05()
{
	IO_id("Method_05 - v0.0");
	method_05a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_06()
{
	int soma = 0;
	IO_id("Method_06 - v0.0");
	soma = somarValores(5);
	IO_printf("soma de pares = %d\n", soma);
	IO_pause("Apertar ENTER para continuar");
}

void method_07()
{
	double soma = 0.0;
	IO_id("Method_07 - v0.0");
	soma = somarFracao1(5);
	IO_printf("soma de fracoes = %lf\n", soma);
	IO_pause("Apertar ENTER para continuar");
}

void method_08()
{
	double soma = 0.0;
	IO_id("Method_08 - v0.0");
	soma = somarFracao2(5);
	IO_printf("soma de fracoes = %lf\n", soma);
	IO_pause("Apertar ENTER para continuar");
}

void method_09()
{
	double soma = 0.0;
	IO_id("EXEMPLO0509 - Method_09 - v0.0");
	soma = somarFracao3(5);
	IO_printf("soma de fracoes = %lf\n", soma);
	IO_pause("Apertar ENTER para continuar");
}

void method_10()
{
	IO_id("Method_10 - v0.0");
	IO_printf("%s%d\n", "produto = ", multiplicarValores(5));
	IO_pause("Apertar ENTER para continuar");
}

int main()
{
    int x = 0;

	do
	{
		IO_id("EXEMPLO0500-Programa-v0.0");

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
				IO_pause(IO_concat("Valor diferente das opcoes[0:10](",IO_concat(IO_toString_d(x),")")));
		}
	}
	while(x != 0);

	IO_pause("Apertar ENTER para terminar");
    
    return 0;
}