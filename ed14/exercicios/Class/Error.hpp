#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>
using namespace std;

template <class T>
class Erro
{
    private:
        int erro;

    public:
        static const std::string NO_ERROR = "[ERRO] Nao ha' erro.";

        Erro ( ) : erro(0) { }
        ~Erro ( ) { }

        int getErro ( )
        {
            return ( erro );
        }
        bool hasError ( )
        {
            return ( erro != 0 );
        }
        virtual std::string getErroMsg ( )
        {
            return ( NO_ERROR );
        }


        int getInt(T value)
        {
            int retorno = 0;
            try {
                string texto = to_string(value);

                int result = stoi(texto);
                retorno = result;
            }
            // Usei o nome da variavel e porque já é costume
            // Caso seja um texto passado como parametro
            catch(const invalid_argument& e) {
                cout << "ERRO: Argumento invalido! " << e.what() << endl;
                retorno = -1;
            }
            // Caso seja muito grande
            catch(const out_of_range& e) {
                 cout << "ERRO: Valor grande demais! " << e.what() << endl;
                retorno = -1;
            }
            return retorno;
        }


    protected:
        void setErro ( int codigo )
        {
            erro = codigo;
        }

};

#endif
