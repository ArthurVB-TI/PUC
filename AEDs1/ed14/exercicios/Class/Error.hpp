#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>
using namespace std;

/*
    1_  std::runtime_error -> Trata erros imprevisíveis que só acontecem enquanto o programa roda, como arquivos sumidos ou rede fora do ar.
    2_  std::invalid_argument -> Bloqueia valores inválidos enviados para funções, como passar um número negativo onde só aceita positivo.
    3_  std::out_of_range -> Impede o programa de quebrar ao tentar acessar uma posição ou índice que não existe em uma lista.
    4_  std::bad_alloc -> Avisa quando o computador ficou sem memória RAM disponível para criar um novo objeto.
    5_  Exceções Personalizadas -> Permite criar seus próprios nomes de erro para regras específicas do seu sistema (ex: SenhaIncorreta).
    6_  std::expected (C++23) -> Retorna o resultado correto OU o erro sem travar o código e sem a perda de desempenho do throw.
    7_  std::logic_error -> Trata erros na lógica do código que poderiam ter sido evitados pelo programador antes de rodar o programa.
    8_  std::domain_error -> Avisa quando um valor está fora do domínio matemático aceito por uma função, como tentar calcular a raiz quadrada de um número negativo.
    9_ std::length_error -> Impede o programa de quebrar ao tentar redimensionar uma lista ou texto além do tamanho máximo permitido pelo sistema.
    10_ std::overflow_error -> Trata erros onde o resultado de uma conta matemática é grande demais para caber no tipo de variável escolhido.
    11_ std::underflow_error -> Trata erros onde o resultado de uma conta com números decimais fica tão próximo de zero que a variável perde a precisão.
    12_ std::bad_cast -> Avisa quando você tenta converter um tipo de objeto em outro usando dynamic_cast e a conversão é impossível.
    13_ std::bad_typeid -> Ocorre quando você tenta descobrir o tipo de um ponteiro que está totalmente vazio (nullptr).
**/

template <class T>
class Erro
{
    private:
        int erro;
        int cifra;

    public:
        static const std::string NO_ERROR;

        Erro ( ) : erro(0), cifra(3) { }
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
                int result = stoi(value);
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

        double getDouble(T value)
        {
            double retorno = 0;
            try {
                double result = stod(value);
                retorno = result;
            }
            // Usei o nome da variavel e porque já é costume
            // Caso seja um texto passado como parametro
            catch(const invalid_argument& e) {
                cout << "ERRO: Argumento invalido! " << e.what() << endl;
                retorno = 0.0;
            }
            // Caso seja muito grande
            catch(const out_of_range& e) {
                cout << "ERRO: Valor grande demais! " << e.what() << endl;
                retorno = 0.0;
            }
            return retorno;
        }

        bool getBoolean(T value)
        {
            bool retorno = false;
            string texto = value;

            if(texto == "true" || texto == "1" || texto == "T"){
                retorno = true;
            } else if(texto == "false" || texto == "0" || texto == "F"){
                retorno = false;
            } else {
                // Comando pra forçar um erro
                throw std::invalid_argument("Erro: Conteudo invalido para conversao booleana ('" + texto + "').");
            }
            
            return retorno;
        }

        bool contains(string text,string subtext){
            bool retorno = false;

            if(text.find(subtext) != std::string::npos) retorno = true;

            return retorno;
        }

        string toUpperCase(string text){
            string retorno = text;
            for(int i = 0; i < retorno.length(); i = i + 1){
                if(retorno[i] >= 'a' && retorno[i] <= 'z') retorno[i] = retorno[i] - 32;
            }
            return retorno;
        }
        
        string toLowerCase(string text){
            string retorno = text;
            for(int i = 0; i < retorno.length(); i = i + 1){
                if(retorno[i] >= 'A' && retorno[i] <= 'Z') retorno[i] = retorno[i] + 32;
            }
            return retorno;
        }

        string replace(string texto, char original, char novo){
            string retorno = texto;
            for(int i = 0; i < texto.length(); i = i + 1){
                if(retorno[i] == original) retorno[i] = novo;
            }
            return retorno;
        }

        string encrypt(string texto){
            string retorno = texto;
            for(int i = 0; i < texto.length(); i = i + 1){
                if((retorno[i] >= 'a' && retorno[i] <= 'z') || (retorno[i] >= 'A' && retorno[i] <= 'Z')){
                    if(retorno[i] + cifra > 'z' || (retorno[i] + cifra > 'Z' && retorno[i] + cifra < 'a')){
                        retorno[i] = retorno[i] + cifra - 25;
                    }else {
                        retorno[i] = retorno[i] + cifra;
                    }
                }
            }
            return retorno;
        }

        string decrypt(string texto){
            string retorno = texto;
            for(int i = 0; i < texto.length(); i = i + 1){
                if((retorno[i] >= 'a' && retorno[i] <= 'z') || (retorno[i] >= 'A' && retorno[i] <= 'Z')){
                    if(retorno[i] - cifra < 'A' || (retorno[i] - cifra < 'a' && retorno[i]  - cifra > 'Z')){
                        retorno[i] = retorno[i] - cifra + 25;
                    }else {
                        retorno[i] = retorno[i] - cifra;
                    }
                }
            }
            return retorno;
        }

        int split(string texto){
            int retorno = 0;
            for(int i = 0; i < texto.length(); i = i + 1){
                if(texto[i] == ' '){ 
                    retorno = retorno + 1;
                    while(texto[i+1] == ' ') i = i + 1;
                }
                
            }
            return retorno;
        }
        
        int split(string texto, char separador){
            int retorno = 0;
            for(int i = 0; i < texto.length(); i = i + 1){
                if(texto[i] == separador){ 
                    retorno = retorno + 1;
                    while(texto[i+1] == separador) i = i + 1;
                }
                
            }
            return retorno;
        }

        string invertido(string texto){
            string retorno = texto;
            int n = texto.length();
            for(int i = 0; i < n; i = i + 1){
                retorno[i] = texto[(n-1)-i];
            }
            return retorno;
        }

    protected:
        void setErro ( int codigo )
        {
            erro = codigo;
        }

};

template <class T>
const std::string Erro<T>::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif
