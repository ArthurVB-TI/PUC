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

        int compare ( ref_intQueue other ) {
            ref_intQueue a = inicio;
            ref_intQueue b = other;

            while ( a != NULL && b != NULL ) {
                if ( a->value != b->value ) return ( a->value - b->value );
                a = a->next;
                b = b->next;
            }

            if ( a == NULL && b == NULL ) return ( 0 );
            return ( a != NULL ? 1 : -1 );
        }

        ref_intQueue join ( ref_intQueue other ) {
            ref_intQueue atual = other;


            while ( atual != NULL ) {
                push ( atual->value );
                atual = atual->next;
            }

            return ( inicio );
        }

        int search ( int value ) {
            ref_intQueue atual = inicio;

            while ( atual != NULL ) {
                if ( atual->value == value ) return ( 1 );
                atual = atual->next;
            }

            return ( 0 );
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
