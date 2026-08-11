#include "io.h"
#define PI 3.14

void metodo1()
{
    int x = 0;
    int y = 0;
    double comprimento = 0.0;
    double areaDividida = 0.0;

    do{
        x = IO_readint("Escreva o raio do circulo: ");
    }while( x <= 0 );
    do{
        y = IO_readint("Escreva em quantas partes dividir: ");
    }while( y <= 0 );

    comprimento = 2.0 * (double) x * PI;
    areaDividida = comprimento / (double) y;

    IO_printf("\n\nRaio: %d\nComprimento: %lf\nareaDividida: %lf\n\n",x,comprimento,areaDividida);
}

void metodo2()
{
    int qtde = 0;
    int count = 1;
    int index = 0;

    qtde = IO_readint("Escreva uma quantidade de palavras a ser escrita: ");
    char** palavras = (char**) malloc( qtde*sizeof(char) );
    bools verificacoes = IO_new_bools( qtde );

    IO_println("");
    for(int i = 0; i < qtde; i = i + 1){
        palavras[i] = IO_new_chars(STR_SIZE);
        verificacoes[i] = true;
        do{
            IO_flush();
            palavras[i] = IO_readstring("Escreva 3 letras: ");
        }while(strlen(palavras[i]) != 3);
        while(count < 3){
            if(palavras[i][count] < palavras[i][count - 1]){
                verificacoes[i] = false;
            }
            count = count + 1;
        }
        count = 1;
    }

    IO_printf("\nVerificações das palavras:\n");
    while(index < qtde){
        if(!verificacoes[index]){
            IO_printf("\t[%d] Não está em ordem crescente - %s\n",index,palavras[index]);
        } else {
            IO_printf("\t[%d] Está em ordem crescente - %s\n",index,palavras[index]);
        }
        index = index + 1;
    }
    IO_println("");
}

void metodo3()
{
    int a = 0;
    int b = 0;
    int qtde = 0;
    
    a = IO_readint("Escreva o primeiro intervalo: ");
    do{
        b = IO_readint("Escreva o segundo intervalo (maior que o primeiro): ");
    }while( b <= a);

    qtde = IO_readint("Escreva um: ");
    ints valores = IO_new_ints(qtde);

    for(int i = 0; i < qtde; i = i + 1){
        IO_printf("%d",i);
        valores[i] = IO_readint(" - ");
    }

    IO_printf("Estão no intervalo (%d:%d]?\n",a,b);
    for(int i = 0; i < qtde; i = i + 1){
        if((valores[i] > a && valores[i] <= b) && valores[i] % 2 == 0 && ((valores[i]/2 > a && valores[i]/2 <= b) && (valores[i]*2 > a && valores[i]*2 <= b))){
            IO_printf("\t[Y] - %d\n",valores[i]);
        } else {
            IO_printf("\t[N] - %d\n",valores[i]);
        }
    }
    IO_println("");
}

void metodo4()
{
    chars texto = IO_new_chars(STR_SIZE);

    texto = IO_readln("Escreva um texto: ");
    IO_printf("Descrição da palavra %s:\n",texto);
    for(int i = 0; i < strlen(texto);i = i + 1){
        if(texto[i] >= 'a' && texto[i] <= 'z'){
            IO_printf("\t[%c] - Letra minuscula\n",texto[i]);
        } else {
            if(texto[i] >= 'A' && texto[i] <= 'Z'){
                IO_printf("\t[%c] - Letra maiuscula\n",texto[i]);
            } else {
                if(texto[i] >= '0' && texto[i] <= '9'){
                    IO_printf("\t[%c] - Numero\n",texto[i]);
                } else {
                    if(texto[i] == ' '){
                        IO_printf("\t[%c] - Espaço\n",texto[i]);
                    } else {
                        if(texto[i] == '_'){
                            IO_printf("\t[%c] - Letra maiuscula\n",texto[i]);
                        } else {
                            IO_printf("\t[%c] - Caracter especial\n",texto[i]);
                        }
                    }
                }
            }
        }
    }
    IO_println("");
}

void descritor(chars texto, int i){
    if(i < strlen(texto)){
        if(texto[i] >= 'a' && texto[i] <= 'z'){
            IO_printf("\t[%c] - Letra minuscula\n",texto[i]);
        } else {
            if(texto[i] >= 'A' && texto[i] <= 'Z'){
                IO_printf("\t[%c] - Letra maiuscula\n",texto[i]);
            } else {
                if(texto[i] >= '0' && texto[i] <= '9'){
                    IO_printf("\t[%c] - Numero\n",texto[i]);
                } else {
                    if(texto[i] == ' '){
                        IO_printf("\t[%c] - Espaço\n",texto[i]);
                    } else {
                        if(texto[i] == '_'){
                            IO_printf("\t[%c] - Letra maiuscula\n",texto[i]);
                        } else {
                            IO_printf("\t[%c] - Caracter especial\n",texto[i]);
                        }
                    }
                }
            }
        }
        descritor(texto,i+1);
    }
}

void metodo5()
{
    chars texto = IO_new_chars(STR_SIZE);

    texto = IO_readln("Escreva um texto: ");
    IO_printf("Descrição da palavra %s:\n",texto);
    descritor(texto,0);
    IO_println("");
}

int main()
{
    int opcao = 0;

    IO_id("Preparatoria");

    do{
        IO_println("Opções: ");
        IO_printf("\t%s\n","0 - Metodo 0");
        IO_printf("\t%s\n","1 - Metodo 1");
        IO_printf("\t%s\n","2 - Metodo 2");
        IO_printf("\t%s\n","3 - Metodo 3");
        IO_printf("\t%s\n","4 - Metodo 4");
        IO_printf("\t%s\n","5 - Metodo 5");
        opcao = IO_readint("Escolha uma opção - ");
        switch(opcao){
            case 0: break;
            case 1: metodo1(); IO_pause("Pressione ENTER para continuar: "); break;
            case 2: metodo2(); IO_pause("Pressione ENTER para continuar: "); break;
            case 3: metodo3(); IO_pause("Pressione ENTER para continuar: "); break;
            case 4: metodo4(); IO_pause("Pressione ENTER para continuar: "); break;
            case 5: metodo5(); IO_pause("Pressione ENTER para continuar: "); break;
            default: IO_println("Opção indisponivel"); IO_pause("Pressione ENTER para terminar: "); break;
        }
    }while(opcao != 0);
    
    return 0;
}