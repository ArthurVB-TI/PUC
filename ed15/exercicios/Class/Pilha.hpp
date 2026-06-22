#ifndef _PILHA_HPP_
#define _PILHA_HPP_

using namespace std;

struct intStack
{
    int value;
    intStack* next;
};

typedef intStack* ref_intStack;

class Pilha
{
    private:
        ref_intStack topo;
        int tamanho;

    public:
        Pilha ( ) : topo ( NULL ), tamanho ( 0 ) { }

        ~Pilha ( ) {
            while ( topo != NULL ) {
                ref_intStack antigo = topo;
                topo = topo->next;
                delete antigo;
            }
        }

        Pilha ( const Pilha& ) = delete;
        Pilha& operator= ( const Pilha& ) = delete;

        int getTamanho ( ) { return ( tamanho ); }
        ref_intStack getTopo ( ) { return ( topo ); }

        ref_intStack push ( int value ) {
            ref_intStack novo = new intStack;

            novo->value = value;
            novo->next = topo;

            topo = novo;
            tamanho = tamanho + 1;

            return ( topo );
        }

        ref_intStack pop ( ) {
            if ( topo == NULL ) {
                tamanho = 0;
                return ( NULL );
            }

            ref_intStack antigo = topo;

            topo = topo->next;
            tamanho = tamanho - 1;

            delete antigo;
            return ( topo );
        }

        ref_intStack dup ( ) {
            if ( topo != NULL ) {
                push ( topo->value );
            }

            return ( topo );
        }

        ref_intStack swap ( ) {
            if ( topo != NULL && topo->next != NULL ) {
                int temp = topo->value;
                topo->value = topo->next->value;
                topo->next->value = temp;
            }

            return ( topo );
        }

        ref_intStack invert ( ) {
            ref_intStack anterior = NULL;
            ref_intStack atual = topo;
            ref_intStack proximo = NULL;

            while ( atual != NULL ) {
                proximo = atual->next;
                atual->next = anterior;
                anterior = atual;
                atual = proximo;
            }

            topo = anterior;
            return ( topo );
        }

        void show ( ) {
            ref_intStack atual = topo;

            cout << "Pilha (topo -> base): ";
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
