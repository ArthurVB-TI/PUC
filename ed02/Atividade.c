#include "io.h"

void method_01(void)
{
    int x = 0;
    
    IO_id("Method_01-Programa-v0.0");
    x = IO_readint("Entrar com um valor inteiro:");
    
    if(x == 0) {
        IO_printf("%s(%d)\n","Valor igual a zero",x);
    } else if(x != 0) {
        IO_printf("%s(%d)\n","Valor diferente de zero",x);
    }
    
    IO_pause("Apertar ENTER para continuar");
}

void method_02(void)
{
	int x = 0;

	IO_id("Method_02-Programa-v0.0");
	x = IO_readint("Entrar com um valor inteiro:");

	if(x == 0) {
		IO_printf("%s(%d)\n","Valor igual a zero",x);
	} else {
		IO_printf("%s(%d)\n","Valor diferente de zero",x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_03(void)
{
	int x = 0;

	IO_id("Method_03-Programa-v0.0");
	x = IO_readint("Entrar com um valor inteiro:");

	if(x == 0)
	{
    	IO_printf("%s(%d)\n","Valor igual a zero",x);
	} else {
		IO_printf("%s(%d)\n","Valor diferente de zero",x);
		if(x > 0)
		{
			IO_printf("%s(%d)\n","Valor maior que zero",x);
		} else {
			IO_printf("%s(%d)\n","Valor menor que zero",x);
		}
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_04(void)
{
	double x = 0.0;

	IO_id("EXEMPLO0204-Programa-v0.0");
	x = IO_readdouble("Entrar com um valor real:");

	if(1.0 <= x && x <= 10.0) {
		IO_printf("%s(%lf)\n","Valor dentro do intervalo[1:10]",x);
	} else {
		IO_printf("%s(%lf)\n","Valor fora do intervalo[1:10]",x);
		if(x < 1.0) {
			IO_printf("%s(%lf)\n","Valor abaixo do intervalo[1:10]",x);
		} else {
			IO_printf("%s(%lf)\n","Valor acima do intervalo[1:10]",x);
		}
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_05(void)
{
	char x = '_';

	IO_id("Method_05-Programa-v0.0");
	x = IO_readchar("Entrar com um caractere:");

	if(('a' <= x) && (x <= 'z')) {
		IO_printf("%s(%c)\n","Letra minuscula",x);
	} else {
		IO_printf("%s(%c)\n","Valor diferente de minuscula",x);
		if(('A' <= x) && (x <= 'Z')) {
			IO_printf("%s(%c)\n","Letra maiuscula",x);
		} else {
			if(('0' <= x) && (x <= '9')) {
				IO_printf("%s(%c)\n","Algarismo",x);
			} else {
				IO_printf("%s(%c)\n","Valor diferente de algarismo",x);
			}
		}
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_06(void)
{
	char x = '_';

	IO_id("Method_06-Programa-v0.0");
	x = IO_readchar("Entrar com um caractere:");

	if(('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
	{
		IO_printf("%s(%c)\n","Letra",x);
	} else {
		IO_printf("%s(%c)\n","Valor diferente de letra",x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_07(void)
{
	char x = '_';

	IO_id("Method_07-Programa-v0.0");
	x = IO_readchar("Entrar com um caractere:");

	if(!(('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z')))
	{
		IO_printf("%s(%c)\n","Valor diferente de letra",x);
	} else {
		IO_printf("%s(%c)\n","Letra",x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_08(void)
{
	char x = '_';

	IO_id("Method_08-Programa-v0.0");
	x = IO_readchar("Entrar com um caractere['0','A','a']:");

	switch(x)
	{
		case '0':
			IO_printf("%s(%c=%d)\n","Valor igual do simbolo zero",x,x);
			break;
		case 'A':
			IO_printf("%s(%c=%d)\n","Valor igual'a letra A",x,x);
			break;
		case 'a':
			IO_printf("%s(%c=%d)\n","Valor igual'a letra a",x,x);
			break;
		default:
			IO_printf("%s(%c=%d)\n","Valor diferente das opcoes['0','A','a']",x,x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_09(void)
{
	int x = 0;

	IO_id("Method_09-Programa-v0.0");
	x = IO_readint("Entrar com um inteiro[0,1,2,3]:");

	switch(x)
	{
		case 0:
			IO_printf("%s(%d)\n","Valor igual a zero",x);
			break;
		case 1:
			IO_printf("%s(%d)\n","Valor igual a um",x);
			break;
		case 2:
			IO_printf("%s(%d)\n","Valor igual a dois",x);
			break;
		case 3:
			IO_printf("%s(%d)\n","Valor igual a tres",x);
			break;
		default:
			IO_printf("%s(%d)\n","Valor diferente das opcoes[0,1,2,3]",x);
	}

	IO_pause("Apertar ENTER para continuar");
}

void method_10(void)
{
	int x = 0;

	IO_id("Method_09-Programa-v0.0");
	x = IO_readint("Entrar com um inteiro[0,1,2,3]:");

	switch(x)
	{
		case 0:
			IO_println(IO_concat("Valor igual a zero(",IO_concat(IO_toString_d(x),")\n")));
			break;
		case 1:
			IO_println(IO_concat("Valor igual a um(",IO_concat(IO_toString_d(x),")\n")));
			break;
		case 2:
			IO_println(IO_concat("Valor igual a dois(",IO_concat(IO_toString_d(x),")\n")));
			break;
		case 3:
			IO_println(IO_concat("Valor igual a três(",IO_concat(IO_toString_d(x),")\n")));
			break;
		default:
			IO_println(IO_concat("Valor diferente das opcoes[0,1,2,3](",IO_concat(IO_toString_d(x),")")));
	}

	IO_pause("Apertar ENTER para continuar");
}

void main( void )
{
    int opcao = 0;
    
    printf("%s\n", "Exemplo0200 - Programa = v0.0");
    printf("%s\n", "Autor: Arthur Victor");
    printf("\n");

    do 
    {
        printf("\n%s\n", "Opcoes:"); 
        printf("\n%s", "0  - Terminar"); 
        printf("\n%s", "1  - Method_01"); 
        printf("\n%s", "2  - Method_02"); 
        printf("\n%s", "3  - Method_03");
        printf("\n%s", "4  - Method_04");
        printf("\n%s", "5  - Method_05");
        printf("\n%s", "6  - Method_06");
        printf("\n%s", "7  - Method_07");
        printf("\n%s", "8  - Method_08");
        printf("\n%s", "9  - Method_09"); 
        printf("\n%s", "10 - Method_10"); 
        printf("\n"); 
        
        printf("\n%s", "Opcao = "); 
        scanf( "%d", &opcao ); getchar( );
        printf("\n");
        switch ( opcao ) 
        { 
            case 0: 
                break; 
            case 1:
                method_01 ( );
                break;
            case 2:
                method_02 ( );
                break; 
            case 3:
                method_03 ( );
                break;
            case 4:
                method_04 ( );
                break;
            case 5:
                method_05 ( );
                break;
            case 6:
                method_06 ( );
                break;
            case 7:
                method_07 ( );
                break;
            case 8:
                method_08 ( );
                break;
            case 9:
                method_09 ( );
                break;
            case 10:
                method_10 ( );
                break;
            default:
                printf("\nERRO: Opcao invalida.\n"); 
                break; 
        }
    } 
    while ( opcao != 0 ); 

    printf("\n\nApertar ENTER para terminar."); 
    getchar( );
}