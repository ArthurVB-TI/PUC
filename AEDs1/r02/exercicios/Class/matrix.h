#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MATRIX_MAX 20

typedef struct {
    int data[MATRIX_MAX][MATRIX_MAX];
    int rows;
    int cols;
} Matrix;

void matrix_init(Matrix* m, int rows, int cols) {
    int i, j;
    m->rows = rows;
    m->cols = cols;
    for (i = 0; i < rows; i = i + 1) {
        for (j = 0; j < cols; j = j + 1) {
            m->data[i][j] = 0;
        }
    }
}

void matrix_ler(const char* arquivo, Matrix* m) {
    FILE* f = fopen(arquivo, "r");
    int i, j;
    if (f == NULL) { m->rows = 0; m->cols = 0; return; }
    fscanf(f, "%d %d", &m->rows, &m->cols);
    for (i = 0; i < m->rows; i = i + 1) {
        for (j = 0; j < m->cols; j = j + 1) {
            fscanf(f, "%d", &m->data[i][j]);
        }
    }
    fclose(f);
}

void matrix_gravar(const char* arquivo, Matrix* m) {
    FILE* f = fopen(arquivo, "w");
    int i, j;
    if (f == NULL) { return; }
    fprintf(f, "%d %d\n", m->rows, m->cols);
    for (i = 0; i < m->rows; i = i + 1) {
        for (j = 0; j < m->cols; j = j + 1) {
            fprintf(f, "%4d", m->data[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void matrix_mostrar(Matrix* m) {
    int i, j;
    for (i = 0; i < m->rows; i = i + 1) {
        for (j = 0; j < m->cols; j = j + 1) {
            IO_printf("%4d", m->data[i][j]);
        }
        IO_printf("\n");
    }
}

#endif
