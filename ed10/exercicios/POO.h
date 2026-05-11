typedef struct Intervalor Intervalo;

struct Intervalo(
    int interval_1;
    int interval_2;

    void (*updateInterval)(Intervalo *);
    void (*indexInterval)(Intervalo *);
)