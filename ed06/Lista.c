#include "io.h"

void method_01a(int x)
{
	if(x > 0)
	{
		IO_printf("%s%d\n", "Valor = ", x);
		method_01a(x - 1);
	}
}

void method_01()
{
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	IO_id("Method_01 - v0.0");
	method_01a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_02a(int x)
{
	if(x > 0)
	{
		method_02a(x - 1);
		IO_printf("%s%d\n", "Valor = ", x);
	}
}

void method_02()
{
	IO_id("Method_02 - v0.0");
	method_02a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_03a(int x)
{
	if(x > 1)
	{
		method_03a(x - 1);
		IO_printf("%s%d\n", "Valor = ", x);
	}
	else
	{
		IO_printf("%s\n", "Valor = 1");
	}
}

void method_03()
{
	IO_id("Method_03 - v0.0");
	method_03a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_04a(int x)
{
	if(x > 1)
	{
		method_04a(x - 1);
		IO_printf("%s%d\n", "Valor = ", 2 * (x - 1));
	}
	else
	{
		IO_printf("%s\n", "Valor = 1");
	}
}

void method_04()
{
	IO_id("Method_04 - v0.0");
	method_04a(5);
	IO_pause("Apertar ENTER para continuar");
}

void method_05a(int x)
{
	if(x > 1)
	{
		method_05a(x - 1);
		IO_printf("%d: %d/%d\n", x, (2 * (x - 1)), (2 * (x - 1) + 1));
	}
	else
	{
		IO_printf("%d; %d\n", x, 1);
	}
}

void method_05()
{
	IO_id("Method_05 - v0.0");
	method_05a(5);
	IO_pause("Apertar ENTER para continuar");
}

double somarFracoes(int x)
{
	double soma = 0.0;
	if(x > 1)
	{
		soma = (2.0 * (x - 1)) / (2.0 * (x - 1) + 1) + somarFracoes(x - 1);
		IO_printf("%d: %lf/%lf\n", x, (2.0 * (x - 1)), (2.0 * (x - 1) + 1));
	}
	else
	{
		soma = 1.0;
		IO_printf("%d; %lf\n", x, 1.0);
	}
	return(soma);
}

void method_06()
{
	double soma = 0.0;
	IO_id("Method_06 - v0.0");
	soma = somarFracoes(5);
	IO_printf("soma = %lf\n", soma);
	IO_pause("Apertar ENTER para continuar");
}

double somarFracoes2b(int x, double soma, double numerador, double denominador)
{
	if(x > 0)
	{
		IO_printf("%d: %lf/%lf\n", x, numerador, denominador);
		soma = somarFracoes2b(x - 1,
			soma + ((1.0 * numerador) / denominador),
			numerador + 2.0,
			denominador + 2.0);
	}
	return(soma);
}

double somarFracoes2a(int x)
{
	double soma = 0.0;
	if(x > 0)
	{
		IO_printf("%d: %lf\n", x, 1.0);
		soma = somarFracoes2b(x - 1, 1.0, 2.0, 3.0);
	}
	return(soma);
}

void method_07()
{
	double soma = 0.0;
	IO_id("Method_07 - v0.0");
	soma = somarFracoes2a(5);
	IO_printf("soma = %lf\n", soma);
	IO_pause("Apertar ENTER para continuar");
}

int contarDigitos(int x)
{
	int resposta = 1;
	if(x >= 10)
	{
		resposta = 1 + contarDigitos(x / 10);
	}
	else
	{
		if(x < 0)
		{
			resposta = contarDigitos(-x);
		}
	}
	return(resposta);
}

void method_08()
{
	IO_id("Method_08 - v0.0");
	IO_printf("digitos (%3d) = %d\n", 123, contarDigitos(123));
	IO_printf("digitos (%3d) = %d\n", 1, contarDigitos(1));
	IO_printf("digitos (%3d) = %d\n", -10, contarDigitos(-10));
	IO_pause("Apertar ENTER para continuar");
}

int fibonacci(int x)
{
	int resposta = 0;
	if(x == 1 || x == 2)
	{
		resposta = 1;
	}
	else
	{
		if(x > 1)
		{
			resposta = fibonacci(x - 1) + fibonacci(x - 2);
		}
	}
	return(resposta);
}

void method_09()
{
	IO_id("Method_09 - v0.0");
	IO_printf("fibonacci (%d) = %d\n", 1, fibonacci(1));
	IO_printf("fibonacci (%d) = %d\n", 2, fibonacci(2));
	IO_printf("fibonacci (%d) = %d\n", 3, fibonacci(3));
	IO_printf("fibonacci (%d) = %d\n", 4, fibonacci(4));
	IO_printf("fibonacci (%d) = %d\n", 5, fibonacci(5));
	IO_pause("Apertar ENTER para continuar");
}

int contarMinusculas(chars cadeia, int x)
{
	int resposta = 0;
	if(0 <= x && x < strlen(cadeia))
	{
		if(cadeia[x] >= 'a' && cadeia[x] <= 'z')
		{
			resposta = 1;
		}
		resposta = resposta + contarMinusculas(cadeia, x + 1);
	}
	return(resposta);
}

void method_10()
{
	IO_id("Method_10 - v0.0");
	IO_printf("Minusculas (\"abc\",0) = %d\n", contarMinusculas("abc", 0));
	IO_printf("Minusculas (\"aBc\",0) = %d\n", contarMinusculas("aBc", 0));
	IO_printf("Minusculas (\"AbC\",0) = %d\n", contarMinusculas("AbC", 0));
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