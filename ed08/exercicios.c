#include "io.h"

#define MAX 100

/*
 * Criei a função IO_random dentro da biblioteca (linha 285 a 297)
*/


// Metodos reutilizados
void lerArquivo(int *n, int arranjo[],chars arquivo_nome)
{
    FILE* arquivo = fopen(arquivo_nome,"rt");
    int index = 0;
    int valor_atual = 0;
    bool v = false;
    char lixo[MAX];

    fscanf(arquivo,"%d",n);
    
    while(!feof(arquivo) && index < *n){
        v = fscanf(arquivo,"%d",&valor_atual);
        if(v){
            arranjo[index] = valor_atual;
        } else {
            fgets(lixo,sizeof(lixo),arquivo);
        }
        index = index + 1;
    }
    fclose(arquivo);
}


// Mostrar exercicios
void index_p1(int n, int *arranjo){
    IO_printf("\nMostrar Valores: \n");
    for(int i = 0; i < n; i = i + 1){
        IO_printf("\t[%d] - %d\n", i, arranjo[i]);
    }
}

void index_p2(int count, int qtde, int *arranjo, chars arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome,"wt");
    fprintf(arquivo,"%d\n",count);
    for(int i = 0; i < count; i = i + 1){
        fprintf(arquivo,"%d\n",arranjo[i]);
    }
    fclose(arquivo);
}

void index_p3(int n, int *arranjo, chars arquivo_nome){
    FILE* arquivo = fopen(arquivo_nome, "wt");
    fprintf(arquivo,"%d\n",n);
    for(int i = 0; i < n; i = i + 1){
        fprintf(arquivo,"%d\n",arranjo[i]);
    }
    fclose(arquivo);
}

void index_p4(int n, int menor, int *arranjo){
    IO_println("");
    for(int i = 0;i < n; i = i + 1){
        if(i < n - 1){
            IO_printf("%d - ",arranjo[i]);
        } else {
            IO_printf("%d",arranjo[i]);
        }
    }
    IO_printf("\nO menor valor dentre estes é %d\n",menor);
}

void index_p5(int n, int maior, int *arranjo){
    IO_println("");
    for(int i = 0;i < n; i = i + 1){
        IO_printf("%d - %d\n",i,arranjo[i]);
    }
    IO_printf("\nO maior valor multiplo de 3 e não de 5 dentre estes é %d\n",maior);
}

void index_p6(int n, int media, int *arranjo){
    IO_println("");
    for(int i = 0;i < n; i = i + 1){
        IO_printf("%d - %d\n",i,arranjo[i]);
    }
    IO_printf("\nA media é %d\n",media);
}

void index_p7(int n, char *texto, int *arranjo){
    IO_println("");
    for(int i = 0; i < n; i = i + 1){
        IO_printf("%d - %d\n",i,arranjo[i]);
    }
    IO_printf("\n%s\n",texto);
}

void index_p8(int qtde, int valor, bool existe, int *arranjo){
    if(existe){
        IO_printf("\nO valor %d existe dentro do arranjo ",valor);
    } else {
        IO_printf("\nO valor %d não existe dentro do arranjo ",valor);
    }
    for(int i = 0; i < qtde; i = i + 1){
        if(i != qtde - 1){
            if(i == 0){
                IO_printf("[");
            }
            IO_printf("%d - ",arranjo[i]);
        } else {
            IO_printf("%d]\n",arranjo[i]);
        }
    }
}

void index_p9(int n, int index, int valor, int *arranjo){
    if(index >= 0){
        IO_printf("\nO valor %d existe dentro do arranjo ",valor);
    } else {
        IO_printf("\nO valor %d não existe dentro do arranjo ",valor);
    }
    for(int i = 0; i < n; i = i + 1){
        if(i != n - 1){
            if(i == 0){
                IO_printf("[");
            }
            IO_printf("%d - ",arranjo[i]);
        } else {
            IO_printf("%d]\n",arranjo[i]);
        }
    }
    if(index >= 0){
        IO_printf("Posição: %d\n",index+1);
    }
}

void index_p10(int n, int valor, int count, int *arranjo){
    if(count > 0){
        IO_printf("\nO valor %d existe dentro do arranjo ",valor);
    } else {
        IO_printf("\nO valor %d não existe dentro do arranjo ",valor);
    }
    for(int i = 0; i < n; i = i + 1){
        if(i != n - 1){
            if(i == 0){
                IO_printf("[");
            }
            IO_printf("%d - ",arranjo[i]);
        } else {
            IO_printf("%d]\n",arranjo[i]);
        }
    }
    if(count > 0){
        IO_printf("Count: %d\n",count);
    }
}

// 0811
void lerPares(int *n, int arranjo[])
{
    do{
        IO_printf("Digite uma quantidade inteira e positiva: ");
        scanf("%d", n); getchar( );
        if(*n<=0){
            IO_printf("Quantidade invalida!\n");
        }
    }while(*n<=0);
    for(int i = 0; i < *n;i = i + 1){
        IO_printf("Digite um valor par e positivo: ");
        scanf("%d", &arranjo[i]); getchar( );
        while(arranjo[i] % 2 != 0 || arranjo[i] <= 0){
            IO_printf("Valor invalido!\n");
            IO_printf("Digite um valor par e positivo: ");
            scanf("%d", &arranjo[i]); getchar( );
        }
    }
}


// 0812
void gravarParesPositivos(int *qtde, int *count, int arranjo[]){
    int valor = 0;
    do{
        IO_printf("Digite uma quantidade inteira: ");
        scanf("%d",qtde); getchar( );
        if(*qtde <= 0){
            IO_printf("Quantidade Invalida!\n");
        }
    }while(*qtde <= 0);
    for(int i = 0; i < *qtde; i = i + 1){
        IO_printf("Digite um valor positivo e par: ");
        scanf("%d",&valor); getchar( );
        if(valor % 2 == 0 && valor > 0){
            arranjo[*count] = valor;
            *count = *count + 1;
        }
    }
}


// 0813
void gerarInt(int *min, int *max, int *n, int arranjo[]){
    do{
        IO_printf("Escreva o primeiro intervalo: ");
        scanf("%d", min); getchar( );
        if(*min < 0){
            IO_printf("O primeiro intervalo deve ser maior que 0!\n");
        }
    }while(*min < 0);
    do{
        IO_printf("Escreva o segundo intervalo: ");
        scanf("%d", max); getchar( );
        if(*min >= *max){
            IO_printf("O segundo intervalo deve ser maior que o primeiro!\n");
        }
    }while(*min >= *max);
    do{
        IO_printf("Digite uma quantidade inteira: ");
        scanf("%d", n); getchar( );
        if(*n <=0){
            IO_printf("A quantidade deve ser maior que 0!\n");
        }
    }while(*n <= 0);
    for(int i = 0; i < *n; i = i + 1){
        arranjo[i] = IO_random(*min,*max);
    }
}


// 0814
void acharMenorPar(int n,int *menor,int *arranjo)
{
    int retorno = 0;
    for(int i = 0; i < n; i = i + 1){
        if(i == 0){
            retorno = arranjo[i];
        }
        if(arranjo[i] < retorno && IO_par(arranjo[i])){
            retorno = arranjo[i];
        }
    }
    if(IO_par(retorno)){
        *menor = retorno;
    } else {
        *menor = 0;
    }
}


// 0815
void acharMaiorParDivisivelPorTres(int n, int *maior, int *arranjo){
    int retorno = 0;
    for(int i = 0; i < n; i = i + 1){
        if(i == 0){
            retorno = arranjo[i];
        }
        if(arranjo[i] > retorno && (arranjo[i] % 3 == 0 && arranjo[i] % 5 != 0)){
            retorno = arranjo[i];
        }
    }
    if((retorno % 3 == 0 && retorno % 5 != 0)){
        *maior = retorno;
    } else {
        *maior = 0;
    }
}


// 0816
void acharMedia(int n, double *media, int *arranjo){
    double retorno = 0.0;
    for(int i = 0; i < n; i = i + 1){
        if(i == 0){
            retorno = arranjo[i];
        }
        retorno = retorno + (double) arranjo[i];
    }
    if(retorno != 0){
        *media = retorno / (double) n;
    } else {
        *media = 0;
    }
}


// 0817
int* lerArranjo(int *n){
    bool v = 0;
    do{
        IO_printf("Digite uma quantidade inteira e positiva: ");
        scanf("%d",n); getchar( );
        if(*n <= 0){
            IO_printf("Quantidade Invalida!");
        }
    }while(*n <= 0);

    int *retorno = (int*) malloc(sizeof(int) * MAX);
    IO_printf("\nDigite os valores: \n");
    for(int i = 0; i < *n; i = i + 1){
        do{
            IO_printf("\t[%d] - ",i);
            v = scanf("%d",&retorno[i]); getchar( );
        }while(!v);
    }
    return retorno;
}

char* verificarOrdem(int n, int *arranjo){
    char *retorno = (char*) malloc(sizeof(char) * MAX);
    bool ordemCrescente = true;
    bool ordemDecrescente = true;
    if(n > 0){
        for(int i = 1; i < n; i = i + 1){
            if(!(arranjo[i] > arranjo[i - 1])){
                ordemCrescente = false;
            }
            if(!(arranjo[i] < arranjo[i - 1])){
                ordemDecrescente = false;
            }
        }
        if(ordemCrescente){
            strcpy(retorno,"Arranjo está em ordem crescente");
        } else {
            if(ordemDecrescente){
                strcpy(retorno,"Arranjo está em ordem decrescente");
            } else {
                strcpy(retorno,"Arranjo não está organizado");
            }
        }
    } else {
        strcpy(retorno,"Arranjo não existe");
    }
    return retorno;
}


// 0818
void acharValor(int qtde, int *valor, bool *existe, int *arranjo){
    bool v = false;
    do{
        IO_printf("Digite um valor inteiro a ser encontrado: ");
        v = scanf("%d",valor); getchar( );
        if(!v){
            IO_printf("Digite um valor inteiro!");
        }
    }while(!v);
    for(int i = 0; i < qtde; i = i + 1){
        if(*valor == arranjo[i]){
            *existe = true;
        }
    }
}


// 0819
void acharPosicao(int n, int *index, int *valor, int *arranjo){
    bool v = false;
    do{
        IO_printf("Digite um valor inteiro a ser encontrado: ");
        v = scanf("%d",valor); getchar( );
        if(!v){
            IO_printf("Digite um valor inteiro!");
        }
    }while(!v);
    for(int i = 0; i < n; i = i + 1){
        if(*valor == arranjo[i]){
            *index = i;
        }
    }
}


// 0820
void acharQuantos(int n,int *valor,int *count,int *arranjo){
    bool v = false;
    do{
        IO_printf("Digite um valor inteiro a ser encontrado: ");
        v = scanf("%d",valor); getchar( );
        if(!v){
            IO_printf("Digite um valor inteiro!");
        }
    }while(!v);
    for(int i = 0; i < n; i = i + 1){
        if(*valor == arranjo[i]){
            *count = *count + 1;
        }
    }
}


// Exercicios
char* p1(bool execute)
{
    if(execute){
        int qtde = 0;
        int arranjo[MAX];

        lerPares(&qtde,arranjo);
        index_p1(qtde,arranjo);
    }
    return "Programa 1";
}

char* p2(bool execute)
{
    if(execute){
        int qtde = 0;
        int count = 0;
        int arranjo[MAX];

        gravarParesPositivos(&qtde,&count,arranjo);
        index_p2(count,qtde,arranjo,"0812.TXT");
    }
    return "Programa 2";
}

char* p3(bool execute)
{
    if(execute){
        int qtde = 0;
        int min = 0;
        int max = 0;
        int arranjo[MAX];

        gerarInt(&min,&max,&qtde,arranjo);
        index_p3(qtde,arranjo,"DADOS.TXT");
    }
    return "Programa 3";
}

char* p4(bool execute)
{
    if(execute){
        int qtde = 0;
        int menor = 0;
        int arranjo[MAX];

        lerArquivo(&qtde,arranjo,"DADOS.TXT");
        acharMenorPar(qtde,&menor,arranjo);
        index_p4(qtde,menor,arranjo);
    }
    return "Programa 4";
}

char* p5(bool execute)
{
    if(execute){
        int qtde = 0;
        int maior = 0;
        int arranjo[MAX];

        lerArquivo(&qtde,arranjo,"DADOS.TXT");
        acharMaiorParDivisivelPorTres(qtde,&maior,arranjo);
        index_p5(qtde,maior,arranjo);
    }
    return "Programa 5";
}

char* p6(bool execute)
{
    if(execute){
        int qtde = 0;
        double media = 0;
        int arranjo[MAX];

        lerArquivo(&qtde,arranjo,"DADOS.TXT");
        acharMedia(qtde,&media,arranjo);
        index_p6(qtde,media,arranjo);
    }
    return "Programa 6";
}

char* p7(bool execute)
{
    if(execute){
        int qtde = 0;
        char texto[MAX];
        int *arranjo = lerArranjo(&qtde);

        strcpy(texto,verificarOrdem(qtde,arranjo));
        index_p7(qtde,texto,arranjo);
    }
    return "Programa 7";
}

char* p8(bool execute)
{
    if(execute){
        int qtde = 0;
        int valor = 0;
        bool existe = false;
        int arranjo[MAX];

        lerArquivo(&qtde,arranjo,"DADOS.TXT");
        acharValor(qtde,&valor,&existe,arranjo);
        index_p8(qtde,valor,existe,arranjo);
    }
    return "Programa 8";
}

char* p9(bool execute)
{
    if(execute){
        int qtde = 0;
        int index = -1;
        int valor = 0;
        int arranjo[MAX];

        lerArquivo(&qtde,arranjo,"DADOS.TXT");
        acharPosicao(qtde,&index,&valor,arranjo);
        index_p9(qtde,index,valor,arranjo);
    }
    return "Programa 9";
}

char* p10(bool execute)
{
    if(execute){
        int qtde = 0;
        int valor = 0;
        int count = 0;
        int arranjo[MAX];

        lerArquivo(&qtde,arranjo,"DADOS.TXT");
        acharQuantos(qtde,&valor,&count,arranjo);
        index_p10(qtde,valor,count,arranjo);
    }
    return "Programa 10";
}

int main()
{
    IO_id("Exercicios");
    Metodo metodos[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    IO_execute(10,metodos);
    return 0;
}