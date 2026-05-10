#include "io.h"

void method_00(void)
{
}

void method_01(void)
{
	int x = 0;

	IO_id("Method_01-v0.0");

	x = IO_readint("Entrar com uma quantidade:");

	while(x > 0)
	{
		IO_println(IO_toString_d(x));
		x = x - 1;
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_02(void)
{
	int x = 0;
    int y = 0;

	IO_id("Method_02-v0.0");

	x = IO_readint("Entrar com uma quantidade:");

	y = x;
	while(y > 0)
	{
		IO_println(IO_toString_d(x));
		y = y - 1;
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_03(void)
{
	int x = 0;
	int y = 0;

	IO_id("Method_03-v0.0");

	x = IO_readint("Entrar com uma quantidade:");

	y = 1;
	while(y <= x)
	{
		IO_printf("%d\n",y);
		y = y + 1;
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_04(void)
{
	int x = 0;
	int y = 0;
	int z = 0;

	IO_id("Method_04-v0.0");

	x = IO_readint("Entrar com uma quantidade:");

	for(y = 1; y <= x; y = y + 1)
	{
		z = IO_readint("Valor=");
		IO_printf("%d.%d\n",y,z);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_05(void)
{
	int x = 0;
	int y = 0;
	int z = 0;

	IO_id("Method_05-v0.0");

	x = IO_readint("Entrar com uma quantidade:");

	for(y = x; y >= 1; y = y - 1)
	{
		z = IO_readint("Valor=");
		IO_printf("%d.%d\n",y,z);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_06(void)
{
	int x = 0;
	int y = 0;
	chars palavra = IO_new_chars(STR_SIZE);
	int tamanho = 0;

	IO_id("Method_06-v0.0");

	palavra = IO_readstring("Entrar com uma palavra:");

	tamanho = strlen(palavra) - 1;

	for(y = tamanho; y >= 0; y = y - 1)
	{
		IO_printf("%d:[%c]\n",y,palavra[y]);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_07(void)
{
	int x = 0;
	int y = 0;
	char palavra[STR_SIZE];
	int tamanho = 0;

	IO_id("Method07-v0.0");

	IO_printf("Entrar com uma palavra:");
	scanf("%s",palavra); getchar();

	tamanho = strlen(palavra);

	for(y = 0; y < tamanho; y = y + 1)
	{
		IO_printf("%d:[%c]\n",y,palavra[y]);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_08(void)
{
	int inferior = 0;
	int superior = 0;
	int x = 0;

	IO_id("Method08-v0.0");

	inferior = IO_readint("Limite inferior do intervalo:");
	superior = IO_readint("Limite superior do intervalo:");

	for(x = inferior; x <= superior; x = x + 1)
	{
		IO_printf("%d\n",x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_09(void)
{
	double inferior = 0;
	double superior = 0;
	double passo = 0;
	double x = 0;

	IO_id("Method_09-v0.0");

	inferior = IO_readdouble("Limite inferior do intervalo:");
	superior = IO_readdouble("Limite superior do intervalo:");
	passo = IO_readdouble("Variacao no intervalo(passo):");

	for(x = superior; x >= inferior; x = x - passo)
	{
		IO_printf("%lf\n",x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_10(void)
{
	double inferior = 0;
	double superior = 0;
	double passo = 0;
	double x = 0;

	IO_id("Method10-v0.0");

	inferior = IO_readdouble("Limite inferior do intervalo:");

	do
	{
		superior = IO_readdouble("Limite superior do intervalo:");
	}
	while(inferior >= superior);

	do
	{
		passo = IO_readdouble("Variacao no intervalo(passo):");
	}
	while(passo <= 0.0);

	for(x = inferior; x <= superior; x = x + passo)
	{
		IO_printf("%lf\n",x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void main()
{
	int x = 0;

	do
	{
		IO_id("EXEMPLO0300-Programa-v0.0");

		IO_println("Opcoes");
		IO_println("0 - parar");
		IO_println("1 - repeticao com teste no inicio");
		IO_println("2 - repeticao com valor constante");
		IO_println("3 - contagem crescente");
		IO_println("4 - leitura de valores (for crescente)");
		IO_println("5 - leitura de valores (for decrescente)");
		IO_println("6 - mostrar caracteres ao contrario");
		IO_println("7 - mostrar caracteres em ordem");
		IO_println("8 - intervalo de inteiros");
		IO_println("9 - intervalo decrescente com passo");
		IO_println("10 - intervalo crescente com passo");
		IO_println("");

		x = IO_readint("Entrar com uma opcao:");

		switch(x)
		{
			case 0: method_00(); break;
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
}