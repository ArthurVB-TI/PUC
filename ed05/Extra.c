#include "io.h"

void Extra_01()
{
    int x = 0;
    long long resultado = 1;
    IO_println("");
    x = IO_readint("Escreva um valor inteiro acima de 0: ");
    IO_println("");
    while(x == 0){
        x = IO_readint("O valor digitado é igual a 0, digite outro: ");
        IO_println("");
    }
    for(int i = x;i > 0;i = i - 1){
        resultado = resultado * i;
    }
    IO_printf("Resultado do fatorial é: %lli\n",resultado);
    IO_println("");
    IO_pause("Pressione ENTER para continuar");
}

void Extra_02()
{
    int x = 0;
    double resultado = 1;
    IO_println("");
    x = IO_readint("Escreva um valor inteiro acima de 0: ");
    IO_println("");
    while(x == 0){
        x = IO_readint("O valor digitado é igual a 0, digite outro: ");
        IO_println("");
    }
    int fatorial(int num){
        int resultado = 1;
        for(int i = num;i > 0;i = i - 1){
            resultado = resultado * i;
        }
        return resultado;
    }
    for(int i = x;i > 0;i = i - 1){
        resultado = resultado * (i+(pow(2,i)/fatorial(pow(3,i))));
    }
    IO_printf("Resultado do fatorial é: %lf\n",resultado);
    IO_println("");
    IO_pause("Pressione ENTER para continuar");
}

int main()
{
    int x = 0;

    IO_id("EXEMPLO0500-Programa-v0.0");

	do
	{

		IO_println("Opcoes");
		IO_println("0 - parar");
		IO_println("1 - Extra 01");
		IO_println("2 - Extra 02");
		IO_println("");

		x = IO_readint("Entrar com uma opcao: ");

		switch(x)
		{
			case 0: break;
			case 1: Extra_01(); break;
			case 2: Extra_02(); break;
			default:
				IO_pause(IO_concat("Valor diferente das opcoes[0:2](",IO_concat(IO_toString_d(x),")")));
		}
	}
	while(x != 0);

	IO_pause("Apertar ENTER para terminar");
    
    return (0);
}