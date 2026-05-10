#include "io.h"

void m1(void)
{
    printf("\n");
    println("Metodo 1: ");

    double area = 0.0;
    double raio = 0.0;

    area = readdouble("Digite o valor da area do circulo: ") * 8.0;
    raio = pow((area/M_PI),(1.0/2.0));

    printf("\n%s%lf\n\n","O valor do raio é: ",raio);

    printf("Pressione ENTER para finalizar");
    getchar();
}

void m2(void)
{
    printf("\n");
    println("Metodo 2: ");

    double volume = 0.0;
    double area = 0.0;
    double raio = 0.0;

    volume = readdouble("Digite o valor da area do circulo: ") / 2.0;
    raio = pow((volume/M_PI),(1.0/3.0)) / (4.0/3.0);
    area = pow(raio,2) * M_PI;

    printf("\n%s%lf\n%s%lf\n\n","O valor do raio é: ",raio, "O valor da area é: ",area);

    printf("Pressione ENTER para finalizar");
    getchar();
}

void main(void)
{
    int opcao = 0;
    
    println("Escolha alguma das ações para ser executada");
    println("0  -  Finalizar");
    println("1  -  Metodo 1");
    println("2  -  Metodo 2");

    printf("\n");

    opcao = readint("Opção: ");

    do
    {
        switch(opcao)
        {
            case 0:
                break;
            case 1:
                m1();
                printf("\n");
                println("Selecione outra opção");
                opcao = readint("Opção: ");
                break;
            case 2:
                m2();
                printf("\n");
                println("Selecione outra opção");
                opcao = readint("Opção: ");
                break;
            default:
                println("");
                println("opção invalida!");
                println("");
                break;
        }
    }
    while (opcao != 0);

    printf("\n");
    printf("Pressione ENTER para finalizar");
    getchar();
}