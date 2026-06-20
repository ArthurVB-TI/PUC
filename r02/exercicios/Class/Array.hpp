using namespace std;

#define MAX_ARR 200

struct Array {
    int data[MAX_ARR];
    int length;
};

void arr_init(Array* a) {
    a->length = 0;
    for (int i = 0; i < MAX_ARR; i = i + 1) a->data[i] = 0;
}

void arr_push(Array* a, int v) {
    if (a->length < MAX_ARR) {
        a->data[a->length] = v;
        a->length = a->length + 1;
    }
}

bool arr_decrescente(Array* a) {
    for (int i = 0; i < a->length - 1; i = i + 1)
        if (a->data[i] < a->data[i + 1]) return false;
    return true;
}

void arr_sortDesc(Array* a) {
    bool trocou = true;
    while (trocou) {
        trocou = false;
        for (int i = 0; i < a->length - 1; i = i + 1) {
            if (a->data[i] < a->data[i + 1]) {
                int tmp = a->data[i];
                a->data[i] = a->data[i + 1];
                a->data[i + 1] = tmp;
                trocou = true;
            }
        }
    }
}

void arr_inverter(Array* dest, Array* src) {
    dest->length = src->length;
    for (int i = 0; i < src->length; i = i + 1)
        dest->data[i] = src->data[src->length - 1 - i];
}

double arr_media(Array* a) {
    double soma = 0.0;
    for (int i = 0; i < a->length; i = i + 1) soma = soma + a->data[i];
    return soma / a->length;
}

int arr_mediana(Array* a) {
    double media = arr_media(a);
    int melhor = a->data[0];
    double menorDiff = (a->data[0] - media < 0 ? -(a->data[0] - media) : a->data[0] - media);
    int segundo = -1;
    double segundoDiff = -1;

    for (int i = 1; i < a->length; i = i + 1) {
        double diff = (a->data[i] - media < 0 ? -(a->data[i] - media) : a->data[i] - media);
        if (diff < menorDiff) {
            segundo = melhor;
            segundoDiff = menorDiff;
            melhor = a->data[i];
            menorDiff = diff;
        } else if (diff == menorDiff && a->data[i] != melhor) {
            segundo = a->data[i];
            segundoDiff = diff;
        }
    }

    if (segundo != -1 && segundoDiff == menorDiff)
        return (melhor + segundo) / 2;
    return melhor;
}

void arr_filtrar(Array* dest, Array* a1, Array* a2) {
    dest->length = 0;
    for (int i = 0; i < a1->length; i = i + 1) {
        bool emA2 = false;
        for (int j = 0; j < a2->length; j = j + 1)
            if (a1->data[i] == a2->data[j]) { emA2 = true; break; }
        if (!emA2) continue;
        bool jaExiste = false;
        for (int k = 0; k < dest->length; k = k + 1)
            if (dest->data[k] == a1->data[i]) { jaExiste = true; break; }
        if (!jaExiste) arr_push(dest, a1->data[i]);
    }
}

int arr_paraDecimal(Array* a) {
    int resultado = 0;
    for (int i = 0; i < a->length; i = i + 1)
        resultado = resultado * 2 + a->data[i];
    return resultado;
}
