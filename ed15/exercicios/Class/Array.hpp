using namespace std;

template <class T>
class Array{
    private:
        T value;
        Array* endereco;

        void init_Array(){
            this->value = NULL;
            this->endereco = NULL;
        }
        
        void init_Array(T value){
            this->value = value;
            this->endereco = this;
        }
    public:
        Array() { init_Array(); }
        Array(T value) { init_Array(value); }

        void set_Value(T value){ this->value = value; }
        T get_Value(){ return this->value; }

        void set_Endereco(T *value){ this->endereco = value; }
        Array* get_Endereco(){ return this->endereco; }
};