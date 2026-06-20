/*
 * Feito por Arthur Victor
*/

#include "io.h"


// Funções reutilizadas
int* armazenarArranjo(int n){
    return (int*) calloc(n,sizeof(int)); // Alocar variavel na memoria
}

int lerQuantidade(){
    int retorno = 0;
    bool v = false;

    // ler valor até: valor > 0
    do{
        IO_printf("Digite uma quantidade positiva: ");
        v = scanf("%d",&retorno); getchar( ); // Pegar valor inteiro

        if(!v){ IO_printf("Insira um valor inteiro!"); } // Caso o valor lido não seja inteiro
        else{ if(retorno <= 0){ IO_printf("Valor Invalido!"); } } // Aviso caso valor não siga as especificações
    }while(retorno <= 0);

    return retorno;
}

void lerIntervalos(int *a, int *b){
    int vA = 0; // Retorno de a
    int vB = 0; // Retorno de b
    bool v = false;

    // Ler primeiro intervalo
    do{
        IO_printf("Digite primeiro intervalo inteiro: ");
        v = scanf("%d",&vA); getchar( );
        if(!v){ IO_printf("Insira um valor Inteiro!"); }
    }while(!v);

    // Ler segundo intervalor
    do{
        IO_printf("Digite segundo intervalo inteiro: ");
        v = scanf("%d",&vB); getchar( );
        if(!v){ IO_printf("Insira um valor Inteiro!"); }
        else{ if(vA >= vB){ IO_printf("Insira um valor maior que o primeiro!"); } }
    }while(!v || vA >= vB);

    // Atribuir resultados
    *a = vA;
    *b = vB;
}

void lerIntervalosReais(double *a, double *b){
    double vA = 0.0; // Retorno de a
    double vB = 0.0; // Retorno de b
    bool v = false;

    // Ler primeiro intervalo
    do{
        IO_printf("Digite primeiro intervalo real: ");
        v = scanf("%lf",&vA); getchar( );
        if(!v){ IO_printf("Insira um valor Real!"); }
    }while(!v);

    // Ler segundo intervalor
    do{
        IO_printf("Digite segundo intervalo real: ");
        v = scanf("%lf",&vB); getchar( );
        if(!v){ IO_printf("Insira um valor Real!"); }
        else{ if(vA >= vB){ IO_printf("Insira um valor maior que o primeiro!"); } }
    }while(!v || vA >= vB);

    // Atribuir resultados
    *a = vA;
    *b = vB;
}

int* lerValores(int quantidade){
    int* retorno = (int*) malloc(sizeof(int)*quantidade);
    int valorAtual = 0;
    bool v = false;

    // for pecorrendo a quantidade
    for(int i = 0; i < quantidade; i = i + 1){
        
        // Mesmo laço de repetição da função lerQuantidade
        do{
            IO_printf("Digite um valor inteiro: ");
            v = scanf("%d",&valorAtual); getchar( ); // Pegar valor inteiro

            if(!v){ IO_printf("Insira um valor inteiro!"); } // Caso o valor lido não seja inteiro
            else{ if(valorAtual <= 0){ IO_printf("Valor Invalido!"); } } // Aviso caso valor não siga as especificações
        }while(!v || valorAtual <= 0);

        // Depois das verificações, atribuir o valor lido dentro do arranjo
        retorno[i] = valorAtual;
    }

    return retorno;
}

double* lerValoresReais(int quantidade){
    double* retorno = (double*) calloc(quantidade,sizeof(double));
    double valorAtual = 0.0;
    bool v = false;

    // for pecorrendo a quantidade
    for(int i = 0; i < quantidade; i = i + 1){
        
        // Ler valor real
        do{
            IO_printf("Digite um valor real: ");
            v = scanf("%lf",&valorAtual); getchar( ); // Pegar valor inteiro

            if(!v){ IO_printf("Insira um valor real!"); } // Caso o valor lido não seja inteiro
        }while(!v);

        // Depois das verificações, atribuir o valor lido dentro do arranjo
        retorno[i] = valorAtual;
    }

    return retorno;
}

char* lerLinha(){
    char* retorno = (char*) malloc(sizeof(char)*STR_SIZE);

    IO_printf("Digite um texto: ");
    fgets(retorno,STR_SIZE,stdin);

    return retorno;
}

// Metodos dos exercicios
// 1
void lerDivisores(int n,int* valores,int* dP,int* dI){
    int divisoresPares = 0;
    int divisoresImpares = 0;

    // Primeiro for para executar para todos os valores
    for(int i = 0; i < n; i = i + 1){
        
        // Segundo for para verificar todos os numeros, se são divisiveis e se são pares ou impares (depois armazenar)
        for(int j = 2; j < valores[i]; j = j + 1){
            // Todas as divisoes de 2 até v - 1
            if(valores[i]%j == 0){
                if(j % 2 == 0){
                    divisoresPares = divisoresPares + 1;
                } else {
                    divisoresImpares = divisoresImpares + 1;
                }
            }
        }

        // Adicionar quantos divisores dentro do ponteiro
        dP[i] = divisoresPares;
        dI[i] = divisoresImpares;

    }
}

void index1(int n, int* v, int* dP, int* dI){
    // Mostrar a quantidade de divisores (par/impar) de todos os valores do arranjo
    for(int i = 0; i < n; i = i + 1){
        IO_printf("O número %d possui %d divisores pares e %d divisores impares\n",v[i],dP[i],dI[i]);
    }
}

// 2
void lerPrimos(int n, int *vP_n,int* v, int* vP){
    bool isPrimo = true;
    int index = 0;

    // Executar para cada valor dentro do arranjo
    for(int i = 0; i < n; i = i + 1){
        isPrimo = true; // Afirma que é primo até que se prove o contrario

        // For para verificar se o número é primo
        for(int j = 2; j < v[i]; j = j + 1){
            // Todas as divisoes de 2 até v - 1
            if(v[i] % j == 0){
                isPrimo = false;
            }
        }

        if(isPrimo){
            // Se for primo, adiciona no arranjo de Números Primos
            vP[index] = v[i];

            // Passa para o proximo valor do arranjo de Números Primos
            index = index + 1;
        }

    }

    // Adiciona quantos valores existem dentro do arranjo de Números Primos
    *vP_n = index;
}

void index2(int n,int vP_n,int* v,int* vP){
    IO_printf("Dos valores [");

    // Mostra todos os valores do arranjo
    for(int i = 0; i < n; i = i + 1){
        if(i + 1 != n){
            IO_printf("%d - ",v[i]);
        } else {
            IO_printf("%d",v[i]);
        }
    }

    IO_printf("], esses são os números primos:\n");

    // Mostra todos os valores do arranjo de Números Primos
    for(int i = 0; i < vP_n; i = i + 1){
        IO_printf("\t%d\n",vP[i]);
    }
}

// 3
void lerOperadores(char* texto,int* definicoes){
    int n = strlen(texto);
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if(p == '!' || p == '|' || p == '&'){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 1;
        }
    }
}

void lerAritmeticos(char* texto,int* definicoes){
    int n = strlen(texto);
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if(p == '+' || p == '-' || p == '*' || p == '/' || p == '%'){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 2;
        }
    }
}

void lerRelacionais(char* texto,int* definicoes){
    int n = strlen(texto);
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if(p == '>' || p == '<' || p == '='){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 3;
        }
    }
}

void lerSeparadores(char* texto,int* definicoes){
    int n = strlen(texto);
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if(p == ' ' || p == '.' || p == ',' || p == ';' || p == ':' || p == '_'){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 4;
        }
    }
}

void index3(char* texto, int* definicoes){
    int n = strlen(texto) - 1;
    int opcao = 0;

    // Executar para cada caracter do texto
    for(int i = 0; i < n; i = i + 1){
        opcao = definicoes[i];

        // Mostrar o que cada número da definição representa
        switch(opcao){
            case 1: IO_printf("[%c] - O símbolo é um operador lógico",texto[i]); break;
            case 2: IO_printf("[%c] - O símbolo é um operador aritmético",texto[i]); break;
            case 3: IO_printf("[%c] - O símbolo é um operador relacional",texto[i]); break;
            case 4: IO_printf("[%c] - O símbolo é um separador",texto[i]); break;
            default: IO_printf("[%c] - É um símbolo qualquer",texto[i]); break;
        }
        IO_println("");
    }
}

// 4
void lerNumeros(char* texto, int* definicoes){
    int n = strlen(texto) - 1;
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if(p >= '0' && p <= '9'){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 5;
        }
    }
}

void lerMinusculas(char* texto, int* definicoes){
    int n = strlen(texto);
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if(p >= 'a' && p <= 'z'){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 6;
        }
    }
}

void lerMaiusculas(char* texto, int* definicoes){
    int n = strlen(texto);
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if(p >= 'A' && p <= 'Z'){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 7;
        }
    }
}

void lerPareados(char* texto, int* definicoes){
    int n = strlen(texto);
    char p = '\0';
    
    // for para verificar o texto inteiro
    for(int i = 0; i < n; i = i + 1){
        // Atribuir caracter atual dentro de uma variavel
        p = texto[i];

        // Verificar esse caracter
        if((p == '(' || p == ')') || (p == '[' || p == ']') || (p == '{' || p == '}')){
            // Atribuir o número que representa esse caracter
            definicoes[i] = 8;
        }
    }
}

void index4(char* texto,int* definicoes){
    int n = strlen(texto);
    int opcao = 0;

    // Executar para cada caracter do texto
    for(int i = 0; i < n; i = i + 1){
        opcao = definicoes[i];

        // Mostrar o que cada número da definição representa
        switch(opcao){
            case 1: IO_printf("[%c] - O símbolo é um operador lógico",texto[i]); break;
            case 2: IO_printf("[%c] - O símbolo é um operador aritmético",texto[i]); break;
            case 3: IO_printf("[%c] - O símbolo é um operador relacional",texto[i]); break;
            case 4: IO_printf("[%c] - O símbolo é um separador",texto[i]); break;
            case 5: IO_printf("[%c] - O símbolo é um número",texto[i]); break;
            case 7: IO_printf("[%c] - O símbolo é uma letra Minuscula",texto[i]); break;
            case 6: IO_printf("[%c] - O símbolo é uma letra Maiuscula",texto[i]); break;
            case 8: IO_printf("[%c] - O símbolo é um pareado",texto[i]); break;
            default: IO_printf("[%c] - É um símbolo qualquer",texto[i]); break;
        }
        IO_println("");
    }
}

// 5
double medias(double *a,double *b,double *c,int n,double* valores){
    double retorno = 0.0;
    double media_a = 0.0;
    double media_b = 0.0;
    double media_c = 0.0;
    int index_a = 0;
    int index_b = 0;
    int index_c = 0;

    // Executar para cada valor
    for(int i = 0; i < n; i = i + 1){
        // Verificar em qual categoria está o valor
        if(valores[i] < -25.25){
            media_a = media_a + valores[i];
            index_a = index_a + 1;
        } else {
            if(valores[i] >= -25.25 && valores[i] <= 68.75){
                media_b = media_b + valores[i];
                index_b = index_b + 1;
            } else {
                media_c = media_c + valores[i];
                index_c = index_c + 1;
            }
        }
    }

    // Atribuir valores aos ponteiros
    media_b = media_b / ((index_b != 0) ? index_b : 1);
    media_c = media_c / ((index_c != 0) ? index_c : 1);
    media_a = media_a / ((index_a != 0) ? index_a : 1);
    *a = media_a;
    *b = media_b;
    *c = media_c;
    
    // Verificar qual media é a maior
    if(media_a > media_b && media_a > media_c){
        retorno = media_a;
    } else {
        if(media_b > media_c){
            retorno = media_b;
        } else {
            retorno = media_c;
        }
    }

    return retorno;
}

void index5(double a, double b, double c, double maiorMedia){
    IO_printf("Dentre as medias [%lf - %lf - %lf], a maior é: %lf",a,b,c,maiorMedia);
}

// 6
int* lerValoresDoIntervalo(){
    int* resultado = (int*) malloc(sizeof(int)*STR_SIZE);
    int valorAtual = 0;
    bool v = false;

    // Verificar até o tamanho do int ou valor inserido ser -1
    for(int i = 0; i < STR_SIZE && valorAtual != -1; i = i + 1){

        // Ler valor dentro das condições
        do{
            IO_printf("Digite um valor inteiro: ");
            v = scanf("%d",&valorAtual); getchar( );
            if(!v){ IO_printf("Insira um valor Inteiro!"); }
        }while(!v);

        // Atribuir valor
        resultado[i] = valorAtual;

    }

    return resultado;
}

void calcularSoma(int a, int b,int* valores, double *soma){
    double retornoSoma = 0.0;
    int p = 0;
    
    // For para executar todos os valores do arranjo
    for(int i = 0; valores[i] != -1 && i < STR_SIZE; i = i + 1){
        
        p = valores[i]; // Valor atual

        // Verificar se esta dentro do intervalo ]a:b[
        if(p > a && p < b){
            // Verificar se é impar e divisivel por 3 e não de 5
            if(p % 3 == 0 && p % 5 != 0 && p % 2 != 0 && p != 0){
                retornoSoma = retornoSoma + (1.0/((i == 0) ? 1.0 : pow((double)i,3.0)));
            }
        }

    }

    *soma = retornoSoma;
}

void index6(int a,int b,int* valores,double soma){
    int index = -1;

    IO_printf("Os valores do arranjo são: [");
    do{
        index = index + 1;
        if(valores[index] != -1 && index + 1 < STR_SIZE){
            IO_printf("%d - ",valores[index]);
        } else {
            IO_printf("%d",valores[index]);
        }
    }while(valores[index] != -1 && index < STR_SIZE);
    IO_printf("]\nA soma dos cubos inversos dos valores que estão dentro do intervalo é:\n\t%lf",soma);
}

// 7
double* lerValoresReaisDoIntervalo(){
    double* resultado = (double*) malloc(sizeof(double)*STR_SIZE);
    double valorAtual = 1.0;
    bool v = false;

    // Verificar até o tamanho do int ou valor inserido ser 0
    for(int i = 0; i < STR_SIZE && valorAtual != 0.0; i = i + 1){

        // Ler valor dentro das condições
        do{
            IO_printf("Digite um valor real: ");
            v = scanf("%lf",&valorAtual); getchar( );
            if(!v){ IO_printf("Insira um valor Real!"); }
        }while(!v);

        // Atribuir valor
        resultado[i] = valorAtual;

    }

    return resultado;
}

double* calcularPorcentagens(double a, double b,int *indexPorcentagens,double* valores){
    double* retorno = (double*) malloc(sizeof(double)*STR_SIZE);
    double soma = 0.0;
    double p = 0.0;
    int index = 0;
    
    // For para executar todos os valores do arranjo
    for(int i = 0; valores[i] != 0.0 && i < STR_SIZE; i = i + 1){
        
        p = valores[i]; // Valor atual

        // Verificar se esta fora do intervalo ]a:b[
        if(!(p > a && p < b) && valores[i] != 0.0){
            // Soma e contar os valores
            soma = soma + valores[i];
            retorno[i] = valores[i];
            index = index + 1;
        }

    }
    
    // For para calcular porcentagem dos valores
    for(int i = 0; i < index; i = i + 1){
        retorno[i] = (retorno[i] / soma) * 100 ;
    }

    *indexPorcentagens = index;
    return retorno;
}

void index7(double a,double b,int indexPorcentagens,double* valores,double* porcentagens){
    int index = -1;

    // Mostrar valores do arranjo
    IO_printf("Os valores do arranjo são: [");
    do{
        index = index + 1;
        if(valores[index] != 0.0 && index + 1 < STR_SIZE){
            IO_printf("%lf - ",valores[index]);
        } else {
            IO_printf("%lf",valores[index]);
        }
    }while(valores[index] != 0.0 && index < STR_SIZE);

    // Mostrar valores das porcentagens
    IO_printf("]\nA porcentagem dos valores que estão fora do intervalo são:\n");
    for(int i = 0; i < indexPorcentagens; i = i + 1){
        IO_printf("\t%lf\n",porcentagens[i]);
    }
}

// 8
double lerReal(){
    double retorno = 0.0;
    bool v = false;

    // Ler até digitar valor real
    do{
        IO_printf("Digite um valor real: ");
        v = scanf("%lf",&retorno); getchar( );
        if(!v){ IO_printf("Valor Invalido"); }
    }while(!v)

    return retorno;
}

bool ordemCrescente(double v1,double v2,double v3){
    bool retorno = true; // Está em ordem crescente até que se prove o contrario

    // Verificações
    if(!(v1 <= v2 && v2 <= v3)){
        retorno = false;
    } 
    return retorno;
}

bool ordemDecrescente(double v1,double v2,double v3){
    bool retorno = true; // Está em ordem decrescente até que se prove o contrario

    // Verificações
    if(!(v1 >= v2 && v2 >= v3)){
        retorno = false;
    } 
    return retorno;
}

double maiorNumero(double v1,double v2,double v3){
    double retorno = 0.0;

    // Verificar se o valor 1 é maior que todos
    if(v1 > v2 && v1 > v3){
        retorno = v1;
    } else {
        // Se valor 1 não for o maior, verificar qual dos outros 2 é o maior
        if(v2 > v3){
            retorno = v2;
        } else {
            retorno = v3;
        }
    }

    return retorno;
}

double menorNumero(double v1,double v2,double v3){
    double retorno = 0.0;

    // Verificar se o valor 1 é menor que todos
    if(v1 < v2 && v1 < v3){
        retorno = v1;
    } else {
        // Se valor 1 não for o menor, verificar qual dos outros 2 é o menor
        if(v2 < v3){
            retorno = v2;
        } else {
            retorno = v3;
        }
    }

    return retorno;
}

void index8(double v1,double v2,double v3){
    // Mostrar valores
    IO_printf("Dentre os valores [%lf - %lf - %lf]: \n",v1,v2,v3);

    // Verificar se está em ordem crescente
    if(ordemCrescente(v1,v2,v3)){
        IO_printf("\tEstá em ordem crescente\n");
    } else {
        IO_printf("\tNão está em ordem crescente\n");
    }

    // Verificar se está em ordem decrescente
    if(ordemDecrescente(v1,v2,v3)){
        IO_printf("\tEstá em ordem decrescente\n");
    } else {
        IO_printf("\tNão está em ordem decrescente\n");
    }

    // Verificar qual é o maior número
    IO_printf("\tO maior número é: ",maiorNumero(v1,v2,v3));

    // Verificar qual é o menor número
    IO_printf("\tO maior número é: ",menorNumero(v1,v2,v3));
}

// 9
char lerChar(){
    char retorno = '';
    bool v = false;

    // Ler até digitar valor real
    do{
        IO_printf("Digite um valor real: ");
        v = scanf("%c",&retorno); getchar( );
        if(!v){ IO_printf("Valor Invalido"); }
    }while(!v)

    return retorno;
}

bool ordemCrescente_Char(char v1,char v2,char v3){
    bool retorno = true; // Está em ordem crescente até que se prove o contrario

    // Verificações
    if(!(v1 <= v2 && v2 <= v3)){
        retorno = false;
    } else {
        if(!((v1 >= 'a' || v1 >= 'A') && (v3 <= 'z' || <='Z'))){ 
            retorno = false;
        }
    }
    return retorno;
}

bool ordemDecrescente_Char(char v1,char v2,char v3){
    bool retorno = true; // Está em ordem decrescente até que se prove o contrario

    // Verificações
    if(!(v1 >= v2 && v2 >= v3)){
        retorno = false;
    } else {
        if(!((v1 >= 'a' || v1 >= 'A') && (v3 <= 'z' || <='Z'))){ 
            retorno = false;
        }
    }
    return retorno;
}

bool sucessor(char v1, char v2){
    bool retorno = true;

    // Verdadeiro até que se prove o contrario
    if(v1 < v2){
        retorno = true;
    } else {
        retorno = false;
    }

    return retorno;
}

void index9(char v1,char v2,char v3){
    // Mostrar valores
    IO_printf("Dentre os caraceteres [%c - %c - %c]: \n",v1,v2,v3);

    // Verificar se está em ordem crescente
    if(ordemCrescente_Char(v1,v2,v3)){
        IO_printf("\tEstá em ordem crescente\n");
    } else {
        IO_printf("\tNão está em ordem crescente\n");
    }

    // Verificar se está em ordem decrescente
    if(ordemDecrescente_Char(v1,v2,v3)){
        IO_printf("\tEstá em ordem decrescente\n");
    } else {
        IO_printf("\tNão está em ordem decrescente\n");
    }

    // Verificar
    if(sucessor(v1,v2)){
        IO_printf("\tO segundo valor é maior que o primeiro\n");
    } else {
        IO_printf("\tO segundo valor não é maior que o primeiro\n");
    }
}

// 10
char* lerCharacteres(){
    char* retorno = (char*) malloc(sizeof(char)*STR_SIZE);

    // Ler cadeia
    fgets(retorno,STRI_SIZE,stdin);

    return retorno
}

bool ordemCrescente_String(char* c1, char* c2, char* c3)
{
    return (
        strcmp(c1, c2) < 0 &&
        strcmp(c2, c3) < 0
    );
}

bool ordemDecrescente_String(char* c1, char* c2, char* c3)
{
    return (
        strcmp(c1, c2) > 0 &&
        strcmp(c2, c3) > 0
    );
}

char* menor_String(char* c1, char* c2, char* c3)
{
    char* menor = c1;

    if(strcmp(c2, menor) < 0)
    {
        menor = c2;
    }

    if(strcmp(c3, menor) < 0)
    {
        menor = c3;
    }

    return menor;
}

char* maior_String(char* c1, char* c2, char* c3)
{
    char* maior = c1;

    if(strcmp(c2, maior) > 0)
    {
        maior = c2;
    }

    if(strcmp(c3, maior) > 0)
    {
        maior = c3;
    }

    return maior;
}

void index10(char* c1, char* c2, char* c3)
{
    // Mostrar cadeias
    IO_printf("Dentre as cadeias de caracteres:\n");
    IO_printf("\t%s\n", c1);
    IO_printf("\t%s\n", c2);
    IO_printf("\t%s\n", c3);

    // Ordem crescente
    if(ordemCrescente_String(c1, c2, c3))
    {
        IO_printf("\tEsta em ordem crescente\n");
    }
    else
    {
        IO_printf("\tNao esta em ordem crescente\n");
    }

    // Ordem decrescente
    if(ordemDecrescente_String(c1, c2, c3))
    {
        IO_printf("\tEsta em ordem decrescente\n");
    }
    else
    {
        IO_printf("\tNao esta em ordem decrescente\n");
    }

    // Nenhuma ordem
    if(
        !ordemCrescente_String(c1, c2, c3) &&
        !ordemDecrescente_String(c1, c2, c3)
    )
    {
        IO_printf("\tMenor cadeia = %s\n", menor_String(c1, c2, c3));
        IO_printf("\tMaior cadeia = %s\n", maior_String(c1, c2, c3));
    }
}

// Metodos Reutilizados
void lerDefinicoes(char* linha,int* definicoes){
    int* result = (int*) calloc(strlen(linha),sizeof(int));
    char* copy_linha = linha;
    
    // Atribuir Definicoes atravez de Metodos
    lerOperadores(copy_linha, result);
    lerAritmeticos(copy_linha, result);
    lerRelacionais(copy_linha, result);
    lerSeparadores(copy_linha, result);
    lerNumeros(copy_linha, result);
    lerMinusculas(copy_linha, result);
    lerMaiusculas(copy_linha, result);
    lerPareados(copy_linha, result);


    // Atribuir definicoes do texto dentro do ponteiro
    for(int i = 0; i < strlen(linha); i = i + 1){
        definicoes[i] = result[i];
    }
}

// Exercicios
void metodo1()
{
    // Variaveis
    int quantidade = 0;
    int* valores; // Cadeia de inteiros
    int* divisoresPares;
    int* divisoresImpares;

    // Funções
    quantidade = lerQuantidade();
    divisoresPares = armazenarArranjo(quantidade);
    divisoresImpares = armazenarArranjo(quantidade);
    valores = lerValores(quantidade);

    // Metodos
    lerDivisores(quantidade,valores,divisoresPares,divisoresImpares); // Contar divisores
    index1(quantidade,valores,divisoresPares,divisoresImpares); // Mostrar divisores
}

void metodo2()
{
    // Variaveis
    int quantidade = 0;
    int quantidadePrimos = 0;
    int* valores; // Cadeia de inteiros
    int* valoresPrimos;

    // Funções
    quantidade = lerQuantidade();
    valoresPrimos = armazenarArranjo(quantidade);
    valores = lerValores(quantidade);

    // Metodos
    lerPrimos(quantidade,&quantidadePrimos,valores,valoresPrimos);
    index2(quantidade,quantidadePrimos,valores,valoresPrimos);
}

void metodo3()
{
    // Variaveis
    char* linha;
    int* definicoes; // Variavel para classificar cada valor do texto

    // Função
    linha = lerLinha();
    definicoes = armazenarArranjo(strlen(linha));

    // Metodos
    lerDefinicoes(linha,definicoes); // Metodos para chamar outros metodos
    index3(linha,definicoes);
}

void metodo4()
{
    // Variaveis
    char* linha;
    int* definicoes;

    // Função
    linha = lerLinha();
    definicoes = armazenarArranjo(strlen(linha));

    // Metodos
    lerDefinicoes(linha,definicoes);
    index4(linha,definicoes);
}

void metodo5()
{
    // Variaveis
    int quantidade = 0;
    double media1 = 0;
    double media2 = 0;
    double media3 = 0;
    double maiorMedia = 0;
    double* valores;

    // Funções
    quantidade = lerQuantidade();
    valores = lerValoresReais(quantidade);
    maiorMedia = medias(&media1,&media2,&media3,quantidade,valores);

    // Metodo
    index5(media1,media2,media3,maiorMedia);
}

void metodo6()
{
    // Variaveis
    int primeiroIntervalo = 0;
    int segundoIntervalo = 0;
    double soma = 0.0;
    int* valores;

    // Funções
    lerIntervalos(&primeiroIntervalo,&segundoIntervalo);
    valores = lerValoresDoIntervalo();

    // Metodos
    calcularSoma(primeiroIntervalo,segundoIntervalo,valores,&soma);
    index6(primeiroIntervalo,segundoIntervalo,valores,soma);
}

void metodo7()
{
    // Variaveis
    double primeiroIntervalo = 0.0;
    double segundoIntervalo = 0.0;
    int indexPorcentagens = 0;
    double* valores;
    double* porcentagens;

    // Funções
    lerIntervalosReais(&primeiroIntervalo,&segundoIntervalo);
    valores = lerValoresReaisDoIntervalo();
    porcentagens = calcularPorcentagens(primeiroIntervalo,segundoIntervalo,&indexPorcentagens,valores);

    // Metodo
    index7(primeiroIntervalo,segundoIntervalo,indexPorcentagens,valores,porcentagens);
}

void metodo8()
{
    // Variaveis
    double valor1 = 0.0;
    double valor2 = 0.0;
    double valor3 = 0.0;

    // Funções
    valor1 = lerReal();
    valor2 = lerReal();
    valor3 = lerReal();

    // Metodo
    index8(valor1,valor2,valor3);
}

void metodo9()
{
    // Variaveis
    char valor1 = '';
    char valor2 = '';
    char valor3 = '';

    // Funções
    valor1 = lerChar();
    valor2 = lerChar();
    valor3 = lerChar();

    // Metodo
    index9(valor1,valor2,valor3);
}

void metodo10()
{
    // Variaveis
    char* valor1;
    char* valor2;
    char* valor3;

    // Funções
    valor1 = lerCharacteres();
    valor2 = lerCharacteres();
    valor3 = lerCharacteres();

    // Metodo
    index10(valor1,valor2,valor3);
}

int main()
{
    int opcao = 0;

    IO_id("Revisão");

    do{
        IO_println("Opções: ");
        IO_printf("\t%s\n","0 - Metodo 0");
        IO_printf("\t%s\n","1 - Metodo 1");
        IO_printf("\t%s\n","2 - Metodo 2");
        IO_printf("\t%s\n","3 - Metodo 3");
        IO_printf("\t%s\n","4 - Metodo 4");
        IO_printf("\t%s\n","5 - Metodo 5");
        IO_printf("\t%s\n","6 - Metodo 6");
        IO_printf("\t%s\n","7 - Metodo 7");
        IO_printf("\t%s\n","8 - Metodo 8");
        IO_printf("\t%s\n","9 - Metodo 9");
        IO_printf("\t%s\n","10 - Metodo 10");
        opcao = IO_readint("Escolha uma opção - ");
        switch(opcao){
            case 0: break;
            case 2: metodo2(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 1: metodo1(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 3: metodo3(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 4: metodo4(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 5: metodo5(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 6: metodo6(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 7: metodo7(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 8: metodo8(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 9: metodo9(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            case 10: metodo10(); IO_println(""); IO_pause("Pressione ENTER para continuar: "); break;
            default: IO_println("Opção indisponivel"); IO_pause("Pressione ENTER para terminar: "); break;
        }
    }while(opcao != 0);
    return 0;
}