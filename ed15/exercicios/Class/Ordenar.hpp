using namespace std;

template <class T>
class Ordenar : public Array{
    private:
        void init_Ordenar(){ }

    public:
        // Metodos de criação
        Ordenar(){ init_Ordenar(); }

        // Metodos de ordenação
        T* push(T* values, T value){
            T* retorno = values;
            int index = 0;

            while(retorno[index] != NULL) index = index + 1;
            retorno[index] = value;

            values = retorno;
            return retorno;
        }

        T* pop(T* values, T value){
            T* retorno = values;
            int index = 0;

            while(retorno[index] != NULL) index = index + 1;
            retorno[index - 1] = NULL;

            values = retorno;
            return index;
        }
        
        T* dup(T* values, T value){
            T* retorno = values;
            int index = 0;

            while(retorno[index] != NULL) index = index + 1;
            retorno[index] = retorno[index - 1];

            values = retorno;
            return retorno;
        }

        T* swap(T* values){
            Array* arranjo = new Array();
            for(int i = 0; values[i + 1] != NULL; i = i + 1){
                Array* value = new Array(values[i]);
            }
        }


        
        // Metodos de leitura
        void index(T* values, int length){
            for(int i = 0; i < length; i = i + 1){
                cout << values[i] << " ";
            }
        }
};