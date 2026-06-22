#ifndef _FILA_HPP_
#define _FILA_HPP_

using namespace std;

struct intQueue
{
    int value;
    intQueue* next;
};

typedef intQueue* ref_intQueue;

class Fila
{
    private:
        ref_intQueue inicio;
        ref_intQueue fim;
        int tamanho;

    public:
        Fila ( ) : inicio ( NULL ), fim ( NULL ), tamanho ( 0 ) { }

        ~Fila ( ) {
            while ( inicio != NULL ) {
                ref_intQueue antigo = inicio;
                inicio = inicio->next;
                delete antigo;
            }
            fim = NULL;
        }

        Fila ( const Fila& ) = delete;
        Fila& operator= ( const Fila& ) = delete;

        int getTamanho ( ) { return ( tamanho ); }
        ref_intQueue getInicio ( ) { return ( inicio ); }

        ref_intQueue push ( int value ) {
            ref_intQueue novo = new intQueue;

            novo->value = value;
            novo->next = NULL;

            if ( fim == NULL ) {
                inicio = novo;
                fim = novo;
            } else {
                fim->next = novo;
                fim = novo;
            }

            tamanho = tamanho + 1;
            return ( inicio );
        }

        ref_intQueue pop ( ) {
            if ( inicio == NULL ) {
                tamanho = 0;
                return ( NULL );
            }

            ref_intQueue antigo = inicio;

            inicio = inicio->next;
            if ( inicio == NULL ) fim = NULL;

            tamanho = tamanho - 1;

            delete antigo;
            return ( inicio );
        }

        ref_intQueue mergeUp ( ref_intQueue other ) {
            ref_intQueue novaInicio = NULL;
            ref_intQueue novoFim = NULL;

            ref_intQueue a = inicio;
            ref_intQueue b = other;

            bool temUltimo = false;
            int ultimo = 0;

            while ( a != NULL || b != NULL ) {
                int valor;

                if ( a != NULL && ( b == NULL || a->value <= b->value ) ) {
                    valor = a->value;
                    a = a->next;
                }
                else
                {
                    valor = b->value;
                    b = b->next;
                }

                if ( !temUltimo || valor != ultimo ) {
                            ref_intQueue novo = new intQueue;
                            novo->value = valor;
                            novo->next = NULL;

                    if ( novoFim == NULL ) {
                        novaInicio = novo;
                        novoFim = novo;
                    } else {
                        novoFim->next = novo;
                        novoFim = novo;
                    }

                    ultimo = valor;
                    temUltimo = true;
                }
            }

            return ( novaInicio );
        }

        ref_intQueue intQueue_mergeDown ( ref_intQueue other ) {
            ref_intQueue novaInicio = NULL;
            ref_intQueue novoFim = NULL;

            ref_intQueue a = inicio;
            ref_intQueue b = other;

            bool temUltimo = false;
            int ultimo = 0;

            while ( a != NULL || b != NULL ) {
                int valor;

                if ( a != NULL && ( b == NULL || a->value >= b->value ) ) {
                    valor = a->value;
                    a = a->next;
                }
                else
                {
                    valor = b->value;
                    b = b->next;
                }

                if ( !temUltimo || valor != ultimo ) {
                    ref_intQueue novo = new intQueue;
                    novo->value = valor;
                    novo->next = NULL;

                    if ( novoFim == NULL ) {
                        novaInicio = novo;
                        novoFim = novo;
                    } else {
                        novoFim->next = novo;
                        novoFim = novo;
                    }

                    ultimo = valor;
                    temUltimo = true;
                }
            }

            return ( novaInicio );
        }

        void show ( ) {
            ref_intQueue atual = inicio;

            cout << "Fila (inicio -> final): ";
            if ( atual == NULL ) {
                cout << "(vazia)";
            }
            while ( atual != NULL ) {
                cout << atual->value;
                if ( atual->next != NULL ) cout << " -> ";
                atual = atual->next;
            }
            cout << endl;
        }
};

#endif
