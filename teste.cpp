#include <TimerOne.h>
#include <MultiFuncShield.h>

const int D1 = 13;
const int D2 = 12;
const int D3 = 11;
const int D4 = 10;
const int BUZZER = 3;
const int TRIG_PIN = 5;
const int ECHO_PIN = 6;

const int qtde = 10;
int await = 1000;
bool IO_rand_reset = false;
bool continuar = true;

const int tons[] = {262, 294, 330, 349};

int IO_random(int minVal, int maxVal) {
    if (!IO_rand_reset) {
        randomSeed(analogRead(A5));
        IO_rand_reset = true;
    }
    if (minVal < maxVal) {
        return random(minVal, maxVal + 1);
    }
    return 0;
}

class arranjo {
    public:
        int* array;
        int tamanho;
        int index;

        arranjo() {
            array = new int[qtde];
            tamanho = 0;
            index = 0;
        }

        void resetArray() {
            tamanho = 0;
            index = 0;
        }

        void addArray() {
            if (tamanho < qtde) {
                array[tamanho] = IO_random(1, 4);
                tamanho++;
            }
        }

        bool verificar(int v, int indice) {
            if (indice >= 0 && indice < tamanho) {
                return array[indice] == v;
            }
            return false;
        }
};

void start(arranjo* a) {
    a->addArray();
}

void reset() {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    noTone(BUZZER);
    digitalWrite(BUZZER, HIGH);
    MFS.write(0);
}

void mostrarValores(int valor) {
    reset();
    switch (valor) {
        case 1: digitalWrite(D1, LOW); tone(BUZZER, tons[0]); MFS.write(1); break;
        case 2: digitalWrite(D2, LOW); tone(BUZZER, tons[1]); MFS.write(2); break;
        case 3: digitalWrite(D3, LOW); tone(BUZZER, tons[2]); MFS.write(3); break;
        case 4: digitalWrite(D4, LOW); tone(BUZZER, tons[3]); MFS.write(4); break;
        default: MFS.write("ERRO"); break;
    }
}

float lerDistancia() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duracao = pulseIn(ECHO_PIN, HIGH, 30000);
    if (duracao == 0) return -1;
    return (duracao * 0.0343) / 2;
}

int obterNivelPorDistancia() {
    float dist = lerDistancia();
    if (dist > 0  && dist <= 10) return 1;
    if (dist > 10 && dist <= 20) return 2;
    if (dist > 20 && dist <= 30) return 3;
    if (dist > 30 && dist <= 40) return 4;
    return 0;
}

int pegarValores() {
    unsigned long tempoInicial = millis();
    int ultimoNivelDetectado = 0;

    while (millis() - tempoInicial < 5000) {
        int nivelAtual = obterNivelPorDistancia();

        if (nivelAtual != ultimoNivelDetectado) {
            if (nivelAtual > 0) {
                mostrarValores(nivelAtual);
            } else {
                reset();
                MFS.write("----");
            }
            ultimoNivelDetectado = nivelAtual;
        }

        byte botao = MFS.getButton();
        if (botao == BUTTON_1_PRESSED) {
            break;
        }
        delay(50);
    }

    int resultadoFinal = ultimoNivelDetectado;
    if (resultadoFinal > 0) {
        mostrarValores(resultadoFinal);
        delay(300);
    }
    reset();
    return resultadoFinal;
}

void efeitoArquiris() {
    reset();
    digitalWrite(D1, LOW); tone(BUZZER, tons[0]); delay(100); reset();
    digitalWrite(D2, LOW); tone(BUZZER, tons[1]); delay(100); reset();
    digitalWrite(D3, LOW); tone(BUZZER, tons[2]); delay(100); reset();
    digitalWrite(D4, LOW); tone(BUZZER, tons[3]); delay(100); reset();
}

void perdeu() {
    tone(BUZZER, 150);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);

    for (int i = 0; i < 3; i++) {
        MFS.write("LOSE"); delay(400);
        MFS.write("");     delay(200);
    }
    reset();
    await = 1000;
}

void aumentarNivel() {
    for (int i = 0; i < 2; i++) {
        MFS.write("FAST");
        efeitoArquiris();
    }
    await = await / 2;
}

void ganhou() {
    for (int i = 0; i < 3; i++) {
        MFS.write("WIN ");
        efeitoArquiris();
    }
}

void durante(arranjo* a) {
    bool sofreu_derrota = false;

    for (a->index = 0; a->index < a->tamanho; a->index++) {
        mostrarValores(a->array[a->index]);
        delay(await);
        reset();
        delay(500);
    }

    for (a->index = 0; a->index < a->tamanho && continuar; a->index++) {
        int valor = pegarValores();
        if (!a->verificar(valor, a->index)) {
            perdeu();
            sofreu_derrota = true;
            continuar = false;
        }
    }

    if (!sofreu_derrota) {
        if (a->tamanho >= qtde) {
            ganhou();
            continuar = false;
        } else {
            a->addArray();
            if (a->tamanho % 5 == 0) {
                aumentarNivel();
            }
        }
    }
}

void setup() {
    Timer1.initialize();
    Timer1.attachInterrupt(MFS.ackTimerService);
    MFS.init();

    for (int i = 10; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }
    pinMode(BUZZER, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    reset();
}

arranjo* a = NULL;

void loop() {
    a = new arranjo();
    start(a);
    continuar = true;

    while (continuar) {
        durante(a);
    }

    delete a;
    a = NULL;
    reset();
    delay(3000);
}
