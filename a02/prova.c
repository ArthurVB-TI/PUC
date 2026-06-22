#include <stdio.h>
#include <string.h>

// q1
void q01(int *p, int *q, int n, int a[]) {
    *p = a[0];
    *q = -1;
    for (int x = 1; x < n; x++) {
        if (a[x] > *p) {
            *q = *p;
            *p = a[x];
        } else if (a[x] > *q && a[x] != *p) {
            *q = a[x];
        }
    }
}

/*
    O codigo acima vai fazer com que caso o atual seja maior que o ultimo maior encontrado,
    q = ultimo maior encontrado e p = atual.

    Se a condição acima seja falsa, o codigo vai verificar se o atual é maior que o penultimo
    maior encontrado e diferente do maior encontrado, se for verdade, q = atual.

    2 -> q = -1, p = 2
    5 -> q = 2, p = 5
    4 -> q = 4, p = 5
    6 -> q = 5, p = 6 // A partir daqui, não tem nenhum valor maior que 6 ou 5

    q = 5, p = 6

    // B
*/

int teste_1()
{
    int a[] = {2, 5, 4, 6, 6, 1, 3};
    int p = 0, q = 0;

    q01(&p, &q, 7, a);
    printf("p=%d q=%d\n", p, q);
}

// q2
void array_print(int n, int a[]) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

void q02(int n, int a[]) {
    int z = a[0];
    int x = 0;
    while (x < n - 1) {
        int y = 0;
        while (y < n - 1) {
            if (a[y] % 2 == 0 && a[y + 1] % 2 != 0) {
                a[0] = a[y];
                a[y] = a[y + 1];
                a[y + 1] = a[0];
            }
            y++;
        }
        x++;
    }
    a[0] = z;
}

/*
    Esse metodo é um sort cujo objetivo principal é deixar todos os números pares
    a direita do array, de forma que, todas as vezes que o valor atual for par e o proximo
    impar, eles trocaram de lugar

    (Apenas impurrar os impares para a esquerda e os pares para a direita):
    1,6,3,2,5,4 -> 1,3,5,6,2,4

    // D
*/

int teste_2() {
    int a[] = {1, 6, 3, 2, 5, 4};
    q03(6, a);
    array_print(6, a);
    return 0;
}

// q3
void matrix_print(int m, int n, int a[][4]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
    }
}

int q02(int p, int q, int m, int n, int a[][4]) {
    if (0 <= p && p < n && 0 <= q && q < n && p != q) {
        int x = 0;
        while (x < m) {
            a[x][p] = a[x][p] + a[x][q];
            a[x][q] = a[x][p] - a[x][q];
            a[x][p] = a[x][p] - a[x][q];
            x++;
        }
    }
    return 0;
}

/*
    O metodo acima faz com que troque os valores das posições passadas no parametro
    representadas com p e q, ou seja, como as posições passadas foram 1 e 3, todos os
    arranjos dentro da matriz vão ter os valores da posição 1 e 3 trocados:

    primeira execução:
    1,2,3,4 -> 1,4,3,2 // Nenhuma das respostas possui essa opção

    // E
*/

int teste_3() {
    int a[][4] = {{1, 2, 3, 4}, {4, 3, 2, 1}, {2, 1, 4, 3}, {1, 3, 4, 2}};
    q02(1, 3, 4, 4, a);
    matrix_print(4, 4, a);
    return 0;
}

// q5
int is_vowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void q05(int n, char *a, char *b, char c[]) {
    int tc = strlen(c);
    int ta = 0;
    int tb = tc;
    int m = 0;
    while (tc - m > n) {
        while (tb > 0 && !is_vowel(c[tb])) tb--;
        tb--;
        m = tc - tb;
    }
    while (tb < tc) {
        b[ta++] = c[tb++];
    }
    *(b + ta) = '\0';
    tb = 0;
    while (tb < tc - ta) {
        *(a + tb) = *(c + tb);
        tb++;
    }
    a[tb] = '\0';
}

/*
    O metodo acima faz com que procure a ultima consoante ate a posição (n + 1) passada,
    ou seja, dentro da palavra despenteada, eu tenho que procurar a ultima consoante 
    da palavra despent, quando eu encontrar essa ultima consoante, eu vou dividir a palavra
    ao meio, então, despenteada vai ser dividida ao meio antes da letra t

    (o primeiro while é responsavel por descobrir onde vai ser divida a palavra, o segundo e o terceiro são responsaveis por dividir a palvra entre os ponteiros passados como parametro)

    1234567...
    despenteada -> despen + teada

    // C
*/

int teste_4() {
    char a[20], b[20];
    q05(6, a, b, "despenteada");
    printf("[%s] = [%s] + [%s]\n", "despenteada", a, b);
    return 0;
}

// q5

void q06(char *a, char *b) {
    int p = 0, q = 0;
    int x = strlen(a);
    while (p < x) {
        if (a[p] != '.') {
            b[q] = a[p];
            q = q + 1;
        } else {
            b[q] = '.';
            q = q + 1;
            while (p + 1 < x && a[p + 1] == '.') p = p + 1;
        }
        p = p + 1;
    }
    b[q] = '\0';
}

/*
    O metodo acima faz com que, o texto passado não repita o caracter '.', ou seja, a resposta
    é a opção que não tem nenhuma sequencia de '.'

    // B
*/

int teste_5() {
    char a[50] = "..a.M.A..I...O..R.f.es.t.a..j..u.ni..n..a..";
    char b[50] = "";
    q06(a, b);
    printf("[%s]\n", b);
    return 0;
}

// q6
struct data{int dia,mes;};

// Metodo pra criar o struct
data* create_data(){
    data* d = (data*)malloc(sizeof(data));
    d->dia = 0;
    d->mes = 0;
    return d;
}

// Função pra retornar a diferença de dias
int get_dias(data* d1,data* d2,int dias){
    int retorno = 0;
    // Variaveis para contar e verificar
    int c1 = 0,c2 = 0,m = 0,a = 0,v = 1;

    if(d2->dia > 30) d2->dia = d2->dia % 30;
    if(d2->mes > 12) d2->mes = d2->mes % 12;

    // Contar a diferença de dias
    while(v){
        // Verificar se eu cheguei no mesmo dia do d2
        if(d1->dia + c1 - (m*30) != d2->dia){
            // Se eu não cheguei, adiciono 1 dia a contagem
            c1 = c1 + 1;
            // Verifica se eu não troquei de mes
            if(d1->dia + c1 - (m*30) > 30) m = m + 1;
        } else {
            v = 0;
        }
    }
    v = 1;
    // Faço a mesma coisa que o while anterior, so que pros meses agora
    while(v){
        if(d1->mes + c2 - (a*12) != d2->mes){
            c2 = c2 + 1;
            if(d1->mes + c2 - (a*12) > 12) a = a + 1;
        } else {
            if(m > 0){
                c2 = c2 + 1
                if(d1->mes + c2 - (a*12) > 12) a = a + 1;
            } else {
                v = 0;
            }
        }
    }
    
    // Contar quantos dias de suspenção ele vai levar
    retorno = c1 + c2 - dias;
    if(retorno > 0) retorno = retorno * 2;
    else retorno = 0;

    return retorno;
}

// Metodo principal
int q6(){
    data* d1 = create_data();
    data* d2 = create_data();
    int dias = 0;
    int suspencao = 0;

    // Pegar os valores
    printf("Digite a duração: ");
    if(!scanf("%d",&dias)) dias = 0; getchar();

    printf("Digite a data de saida: ");
    if(!scanf("%d",&d1->dia))d1->dia = 0; getchar();
    if(!scanf("%d",&d1->mes))d1->mes = 0; getchar();
    
    printf("Digite a data de devolução: ");
    if(!scanf("%d",&d2->dia))d2->dia = 0; getchar();
    if(!scanf("%d",&d2->mes))d2->mes = 0; getchar();

    suspencao = get_dias(d1,d2,dias);

    printf("suspenção de %d dias\n",suspencao);
}

// q7


int main()
{
    teste_1();
    teste_2();
    teste_3();
    teste_4();
    teste_5();
    q6();

    return 1;
}