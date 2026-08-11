#ifndef _ARRAY_H_
#define _ARRAY_H_

#define ARRAY_MAX 100

typedef struct {
    int  data[ARRAY_MAX];
    int  size;
} Array;

void array_init(Array* a) {
    int i;
    a->size = 0;
    for (i = 0; i < ARRAY_MAX; i = i + 1) {
        a->data[i] = 0;
    }
}

void array_ler(const char* arquivo, Array* a) {
    FILE* f = fopen(arquivo, "r");
    int i;
    if (f == NULL) { a->size = 0; return; }
    fscanf(f, "%d", &a->size);
    for (i = 0; i < a->size; i = i + 1) {
        fscanf(f, "%d", &a->data[i]);
    }
    fclose(f);
}

void array_gravar(const char* arquivo, Array* a) {
    FILE* f = fopen(arquivo, "w");
    int i;
    if (f == NULL) { return; }
    fprintf(f, "%d\n", a->size);
    for (i = 0; i < a->size; i = i + 1) {
        fprintf(f, "%d\n", a->data[i]);
    }
    fclose(f);
}

void array_mostrar(Array* a) {
    int i;
    IO_printf("[ ");
    for (i = 0; i < a->size; i = i + 1) {
        IO_printf("%d%s", a->data[i], (i + 1 < a->size ? ", " : ""));
    }
    IO_printf(" ]\n");
}

#endif
