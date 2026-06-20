#ifndef _SHOW_H_
#define _SHOW_H_

void show_arranjo(const char* label, Array* a) {
    IO_printf("%s: ", label);
    array_mostrar(a);
}

void show_double(const char* label, double v) {
    IO_printf("%s: %lf\n", label, v);
}

void show_bool(const char* label, bool v) {
    IO_printf("%s: %s\n", label, v ? "sim" : "nao");
}

void show_matrix(const char* label, Matrix* m) {
    IO_printf("%s:\n", label);
    matrix_mostrar(m);
}

void show_supermercados_abaixo_media(Supermercado* lista, int n, double media) {
    int i, count = 0;
    IO_printf("Media de precos: %.2lf\n", media);
    IO_printf("Supermercados com preco abaixo da media:\n");
    for (i = 0; i < n && count < 2; i = i + 1) {
        if (lista[i].preco < media) {
            IO_printf("  [%d] %s - R$ %.2lf\n", lista[i].codigo, lista[i].nome, lista[i].preco);
            count = count + 1;
        }
    }
    if (count == 0) { IO_printf("  Nenhum supermercado abaixo da media.\n"); }
}

#endif
