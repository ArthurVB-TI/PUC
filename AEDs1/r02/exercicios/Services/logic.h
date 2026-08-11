#ifndef _LOGIC_H_
#define _LOGIC_H_

bool arranjo_decrescente(Array* a) {
    int i;
    for (i = 0; i < a->size - 1; i = i + 1) {
        if (a->data[i] < a->data[i + 1]) { return false; }
    }
    return true;
}

void arranjo_ordenar_decrescente(Array* a) {
    int i, tmp;
    bool trocou = true;
    while (!arranjo_decrescente(a) && trocou) {
        trocou = false;
        for (i = 0; i < a->size - 1; i = i + 1) {
            if (a->data[i] < a->data[i + 1]) {
                tmp = a->data[i];
                a->data[i] = a->data[i + 1];
                a->data[i + 1] = tmp;
                trocou = true;
            }
        }
    }
}

void arranjo_inverter(Array* dest, Array* src) {
    int i;
    dest->size = src->size;
    for (i = 0; i < src->size; i = i + 1) {
        dest->data[i] = src->data[(src->size - 1) - i];
    }
}

double arranjo_mediana(Array* a) {
    int i, j, t;
    int* tmp = (int*) malloc(a->size * sizeof(int));
    double soma, media, dist, menor_dist, candidato1, candidato2, resultado;
    int achou2;

    for (i = 0; i < a->size; i = i + 1) {
        tmp[i] = a->data[i];
    }

    for (i = 0; i < a->size - 1; i = i + 1) {
        for (j = 0; j < a->size - 1 - i; j = j + 1) {
            if (tmp[j] > tmp[j + 1]) {
                t = tmp[j]; tmp[j] = tmp[j + 1]; tmp[j + 1] = t;
            }
        }
    }

    soma = 0.0;
    for (i = 0; i < a->size; i = i + 1) {
        soma = soma + tmp[i];
    }
    media = soma / a->size;

    menor_dist = -1.0;
    candidato1 = tmp[0];
    candidato2 = tmp[0];
    achou2 = 0;

    for (i = 0; i < a->size; i = i + 1) {
        dist = tmp[i] - media;
        if (dist < 0) { dist = -dist; }
        if (menor_dist < 0 || dist < menor_dist) {
            menor_dist = dist;
            candidato1 = tmp[i];
            candidato2 = tmp[i];
            achou2 = 0;
        } else if (dist == menor_dist && tmp[i] != candidato1) {
            candidato2 = tmp[i];
            achou2 = 1;
        }
    }

    resultado = achou2 ? (candidato1 + candidato2) / 2.0 : candidato1;
    free(tmp);
    return resultado;
}

bool arranjo_contem(Array* a, int val) {
    int i;
    for (i = 0; i < a->size; i = i + 1) {
        if (a->data[i] == val) { return true; }
    }
    return false;
}

void arranjo_filtrar(Array* dest, Array* a1, Array* a2) {
    int i, v;
    dest->size = 0;
    for (i = 0; i < a1->size; i = i + 1) {
        v = a1->data[i];
        if (arranjo_contem(a2, v) && !arranjo_contem(dest, v)) {
            dest->data[dest->size] = v;
            dest->size = dest->size + 1;
        }
    }
}

bool binario_valido(const char* linha) {
    int i;
    if (linha[0] == '\0') { return false; }
    for (i = 0; linha[i] != '\0'; i = i + 1) {
        if (linha[i] != '0' && linha[i] != '1') { return false; }
    }
    return true;
}

int arranjo_paraDecimal(Array* a) {
    int i, resultado = 0;
    for (i = 0; i < a->size; i = i + 1) {
        resultado = resultado * 2 + a->data[i];
    }
    return resultado;
}

void matrix_tridiagonal_crescente(Matrix* m, int n) {
    int i, j, val = 1;
    matrix_init(m, n, n);
    for (i = 0; i < n; i = i + 1) {
        for (j = i - 1; j <= i + 1 && j < n; j = j + 1) {
            if (j >= 0) {
                m->data[i][j] = val;
                val = val + 1;
            }
        }
    }
}

void matrix_tridiagonal_secundaria(Matrix* m, int n) {
    int i, j, j_start, j_end, val = 1;
    matrix_init(m, n, n);
    for (i = 0; i < n; i = i + 1) {
        j_start = (n - 1) - (i + 1);
        j_end   = (n - 1) - (i - 1);
        for (j = j_start; j <= j_end && j >= 0 && j < n; j = j + 1) {
            m->data[i][j] = val;
            val = val + 1;
        }
    }
}

bool matrix_potencias_por_linhas(Matrix* m) {
    int i, j, p, esperado;
    for (i = 0; i < m->rows; i = i + 1) {
        for (j = 0; j < m->cols; j = j + 1) {
            esperado = 1;
            for (p = 0; p < i; p = p + 1) {
                esperado = esperado * (j + 1);
            }
            if (m->data[i][j] != esperado) { return false; }
        }
    }
    return true;
}

bool matrix_potencias_decrescentes_colunas(Matrix* m) {
    int i, j, p, exp, esperado;
    for (i = 0; i < m->rows; i = i + 1) {
        for (j = 0; j < m->cols; j = j + 1) {
            exp = (m->rows - 1) - i;
            esperado = 1;
            for (p = 0; p < exp; p = p + 1) {
                esperado = esperado * (j + 1);
            }
            if (m->data[i][j] != esperado) { return false; }
        }
    }
    return true;
}

typedef struct {
    char   nome[80];
    int    codigo;
    double preco;
} Supermercado;

void supermercados_ler(const char* arquivo, Supermercado* lista, int* n) {
    FILE* f = fopen(arquivo, "r");
    int i;
    if (f == NULL) { *n = 0; return; }
    fscanf(f, "%d", n);
    for (i = 0; i < *n; i = i + 1) {
        fscanf(f, "%s %d %lf", lista[i].nome, &lista[i].codigo, &lista[i].preco);
    }
    fclose(f);
}

double supermercados_media(Supermercado* lista, int n) {
    int i;
    double soma = 0.0;
    for (i = 0; i < n; i = i + 1) {
        soma = soma + lista[i].preco;
    }
    return soma / n;
}

#endif
