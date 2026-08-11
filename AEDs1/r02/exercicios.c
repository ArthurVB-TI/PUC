#include "io.h"
#include "exercicios/routes.h"

int main ( int argc, char* argv[] )
{
    int opcao = 0;

    IO_id("R02 - Recuperacao 02");

    do
    {
        IO_printf("\nOpcoes:\n");
        IO_printf("0  - Sair\n");
        IO_printf("1  - Ordenar decrescente      (DADOS1.TXT -> DECRESCENTE.TXT)\n");
        IO_printf("2  - Inverter arranjo          (DECRESCENTE.TXT -> INVERTIDOS.TXT)\n");
        IO_printf("3  - Mediana do arranjo        (DADOS1.TXT)\n");
        IO_printf("4  - Filtrar elementos comuns  (DADOS1.TXT + DADOS2.TXT -> FILTRADOS.TXT)\n");
        IO_printf("5  - Binario para decimal      (BINARIOS1.TXT)\n");
        IO_printf("6  - Tridiagonal crescente     (MATRIZ1.TXT -> MATRIZ2.TXT)\n");
        IO_printf("7  - Tridiagonal secundaria    (MATRIZ1.TXT -> MATRIZ2.TXT)\n");
        IO_printf("8  - Potencias por linhas      (MATRIZ3.TXT)\n");
        IO_printf("9  - Potencias decresc. col.   (MATRIZ4.TXT)\n");
        IO_printf("10 - Supermercados abaixo media (DADOS3.TXT)\n");

        IO_printf("\nOpcao = ");
        scanf("%d", &opcao); getchar();

        IO_println("");

        switch (opcao)
        {
            case 0:  break;
            case 1:  m1();  break;
            case 2:  m2();  break;
            case 3:  m3();  break;
            case 4:  m4();  break;
            case 5:  m5();  break;
            case 6:  m6();  break;
            case 7:  m7();  break;
            case 8:  m8();  break;
            case 9:  m9();  break;
            case 10: m10(); break;
            default: IO_printf("\nERRO: Opcao invalida.\n"); break;
        }
    }
    while (opcao != 0);

    IO_printf("\n\nApertar ENTER para terminar.");
    getchar();
    return 0;
}