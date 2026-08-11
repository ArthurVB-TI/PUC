#ifndef _METODOS_H_
#define _METODOS_H_

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m1 - Exercicio 01
 * Objetivo: Verificar se arranjo esta em ordem decrescente;
 *           se nao estiver, ordenar por troca de vizinhos e gravar em DECRESCENTE.TXT.
 * Parametros: nenhum (le de DADOS1.TXT)
 * Testes: {3,1,4,2,5} -> ordena -> {5,4,3,2,1}; {5,4,3} -> ja decrescente
 */
void m1() {
    Array* a = (Array*) malloc(sizeof(Array));
    array_init(a);
    array_ler("DADOS1.TXT", a);
    IO_printf("Arranjo lido: "); array_mostrar(a);

    if (arranjo_decrescente(a)) {
        IO_printf("Ja esta em ordem decrescente.\n");
    } else {
        IO_printf("Nao esta em ordem decrescente. Ordenando...\n");
        arranjo_ordenar_decrescente(a);
        IO_printf("Arranjo ordenado: "); array_mostrar(a);
    }
    array_gravar("DECRESCENTE.TXT", a);
    IO_printf("Gravado em DECRESCENTE.TXT\n");
    free(a);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m2 - Exercicio 02
 * Objetivo: Inverter a ordem dos elementos do arranjo lido de DECRESCENTE.TXT
 *           e gravar em INVERTIDOS.TXT.
 * Parametros: nenhum
 * Testes: {5,4,3,2,1} -> invertido: {1,2,3,4,5}
 */
void m2() {
    Array* a   = (Array*) malloc(sizeof(Array));
    Array* inv = (Array*) malloc(sizeof(Array));
    array_init(a);
    array_init(inv);
    array_ler("DECRESCENTE.TXT", a);
    IO_printf("Arranjo lido: "); array_mostrar(a);

    arranjo_inverter(inv, a);
    show_arranjo("Arranjo invertido", inv);
    array_gravar("INVERTIDOS.TXT", inv);
    IO_printf("Gravado em INVERTIDOS.TXT\n");
    free(a);
    free(inv);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m3 - Exercicio 03
 * Objetivo: Calcular o valor mais perto da media do arranjo de DADOS1.TXT.
 *           Se dois valores forem igualmente proximos e diferentes, usa a media dos dois.
 * Parametros: nenhum
 * Testes: {1,2,3,4,5} -> media=3.0, mediana=3
 *         {1,2,4,5}   -> media=3.0, proximos: 2 e 4 -> (2+4)/2=3.0
 */
void m3() {
    Array* a = (Array*) malloc(sizeof(Array));
    double mediana;
    array_init(a);
    array_ler("DADOS1.TXT", a);
    IO_printf("Arranjo lido: "); array_mostrar(a);

    mediana = arranjo_mediana(a);
    show_double("Mediana (valor mais perto da media)", mediana);
    free(a);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m4 - Exercicio 04
 * Objetivo: Filtrar elementos comuns entre DADOS1.TXT e DADOS2.TXT sem repeticoes
 *           e gravar em FILTRADOS.TXT.
 * Parametros: nenhum
 * Testes: {1,2,3,4} e {2,4,6} -> comuns: {2,4}
 */
void m4() {
    Array* a1       = (Array*) malloc(sizeof(Array));
    Array* a2       = (Array*) malloc(sizeof(Array));
    Array* filtrado = (Array*) malloc(sizeof(Array));
    array_init(a1); array_init(a2); array_init(filtrado);
    array_ler("DADOS1.TXT", a1);
    array_ler("DADOS2.TXT", a2);
    IO_printf("Arranjo 1: "); array_mostrar(a1);
    IO_printf("Arranjo 2: "); array_mostrar(a2);

    arranjo_filtrar(filtrado, a1, a2);
    show_arranjo("Elementos comuns", filtrado);
    array_gravar("FILTRADOS.TXT", filtrado);
    IO_printf("Gravado em FILTRADOS.TXT\n");
    free(a1); free(a2); free(filtrado);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m5 - Exercicio 05
 * Objetivo: Ler cadeias binarias de BINARIOS1.TXT, validar (so 0 e 1)
 *           e converter para decimal.
 * Parametros: nenhum
 * Testes: "1011" -> 11; "0000" -> 0; "abc" -> invalido; "1101" -> 13
 */
void m5() {
    FILE* f = fopen("BINARIOS1.TXT", "r");
    char linha[ARRAY_MAX + 1];
    Array* a = (Array*) malloc(sizeof(Array));
    int i, decimal, len;

    if (f == NULL) { IO_printf("BINARIOS1.TXT nao encontrado.\n"); free(a); return; }

    while (fgets(linha, sizeof(linha), f) != NULL) {
        len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') { linha[len - 1] = '\0'; }

        if (!binario_valido(linha)) {
            IO_printf("\"%s\" -> invalido\n", linha);
            continue;
        }
        array_init(a);
        a->size = strlen(linha);
        for (i = 0; i < a->size; i = i + 1) {
            a->data[i] = linha[i] - '0';
        }

        decimal = arranjo_paraDecimal(a);
        IO_printf("\"%s\" -> %d\n", linha, decimal);
    }
    fclose(f);
    free(a);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m6 - Exercicio 06
 * Objetivo: Ler N de MATRIZ1.TXT e montar matriz tridiagonal crescente NxN,
 *           mostrar e gravar em MATRIZ2.TXT.
 * Parametros: nenhum
 * Testes: N=4 -> tridiagonal como no enunciado
 */
void m6() {
    FILE* f = fopen("MATRIZ1.TXT", "r");
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    int n;
    char label[40];

    if (f == NULL) { IO_printf("MATRIZ1.TXT nao encontrado.\n"); free(m); return; }
    while (fscanf(f, "%d", &n) == 1) {
        matrix_tridiagonal_crescente(m, n);
        sprintf(label, "Tridiagonal crescente N=%d", n);
        show_matrix(label, m);
        matrix_gravar("MATRIZ2.TXT", m);
        IO_printf("Gravado em MATRIZ2.TXT\n");
    }
    fclose(f);
    free(m);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m7 - Exercicio 07
 * Objetivo: Ler N de MATRIZ1.TXT e montar matriz tridiagonal secundaria NxN,
 *           mostrar e gravar em MATRIZ2.TXT.
 * Parametros: nenhum
 * Testes: N=4 -> tridiagonal secundaria como no enunciado
 */
void m7() {
    FILE* f = fopen("MATRIZ1.TXT", "r");
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    int n;
    char label[40];

    if (f == NULL) { IO_printf("MATRIZ1.TXT nao encontrado.\n"); free(m); return; }
    while (fscanf(f, "%d", &n) == 1) {
        matrix_tridiagonal_secundaria(m, n);
        sprintf(label, "Tridiagonal secundaria N=%d", n);
        show_matrix(label, m);
        matrix_gravar("MATRIZ2.TXT", m);
        IO_printf("Gravado em MATRIZ2.TXT\n");
    }
    fclose(f);
    free(m);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m8 - Exercicio 08
 * Objetivo: Ler matriz de MATRIZ3.TXT e verificar se tem potencias por linhas.
 *           Linha i (base 0): m[i][j] == (j+1)^i
 * Parametros: nenhum
 * Testes: {{1,1,1,1},{1,2,3,4},{1,4,9,16},{1,8,27,64}} -> sim
 */
void m8() {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    matrix_ler("MATRIZ3.TXT", m);
    show_matrix("Matriz de MATRIZ3.TXT", m);
    show_bool("E potencias por linhas?", matrix_potencias_por_linhas(m));
    free(m);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m9 - Exercicio 09
 * Objetivo: Ler matriz de MATRIZ4.TXT e verificar se tem potencias decrescentes por colunas.
 *           Coluna j (base 0): m[i][j] == (j+1)^(rows-1-i)
 * Parametros: nenhum
 * Testes: {{1,8,27,64},{1,4,9,16},{1,2,3,4},{1,1,1,1}} -> sim
 */
void m9() {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    matrix_ler("MATRIZ4.TXT", m);
    show_matrix("Matriz de MATRIZ4.TXT", m);
    show_bool("E potencias decrescentes por colunas?", matrix_potencias_decrescentes_colunas(m));
    free(m);
}

/**
 * Autor: Arthur Victor Alves
 * Identificacao: m10 - Exercicio 10
 * Objetivo: Ler supermercados de DADOS3.TXT, calcular media de precos
 *           e mostrar ao menos dois com preco abaixo da media.
 * Parametros: nenhum
 * Testes: 4 supermercados com precos 10.50,25.00,18.90,32.00 -> media=21.60,
 *         abaixo: Extra(10.50), SuperBom(18.90)
 */
void m10() {
    Supermercado* lista = (Supermercado*) malloc(100 * sizeof(Supermercado));
    int n = 0, i;
    double media;

    supermercados_ler("DADOS3.TXT", lista, &n);
    if (n == 0) { IO_printf("DADOS3.TXT nao encontrado ou vazio.\n"); free(lista); return; }

    IO_printf("Supermercados lidos: %d\n", n);
    for (i = 0; i < n; i = i + 1) {
        IO_printf("  [%d] %s - R$ %.2lf\n", lista[i].codigo, lista[i].nome, lista[i].preco);
    }

    media = supermercados_media(lista, n);
    show_supermercados_abaixo_media(lista, n, media);
    free(lista);
}

#endif
