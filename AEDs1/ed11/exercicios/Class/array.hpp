template<class T>
class Array
{
    private:
        T *data;
        int length;
        int position; // index
    public:
        Array()
        {
            this->data = NULL;
            this->length = 0;
            this->position = 0;
        }
        Array(int n)
        {
            if(n > 0){
                this->data = new T[n];
                this->length = n;
                this->position = 0;
            } else {
                this->data = NULL;
                this->length = 0;
                this->position = 0;
            }
        }
        void updateLength(int n)
        {
            if(n > 0){
                if(this->data != NULL){
                    int tamanho = 0;
                    if(n > this->length){
                        tamanho = n;
                    } else {
                        tamanho = this->length;
                    }
                    T *newData = new T[tamanho];
                    for(int i = 0; i < tamanho; i++){
                        newData[i] = this->data[i];
                    }
                    delete[] this->data;
                    this->data = newData;
                    newData = NULL;
                } else {
                    this->data = new T[n];
                }
                this->length = n;
                this->position = 0;
            }
        }
        void readLength()
        {
            int qtde = 0;
            do{
                std::cout << "Digite sua quantidade: ";
                std::cin >> qtde;
                if(std::cin.fail())
                {
                    std::cout << "Valor invalido\n";

                    std::cin.clear();

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }while(std::cin.fail() || qtde <= 0);
            this->updateLength(qtde);
        }
        int getLength()
        {
            int retorno = 0;
            if(this->length > 0) retorno = this->length;
            return retorno;
        }
        void setValue(T value)
        {
            if((this->position >= 0) && (this->position < this->length && this->data != NULL)){
                this->data[this->position] = value;
                this->position = this->position + 1;
            }
        }
        void setValue_wIndex(T value,int index)
        {
            if((index >= 0) && (index < this->length && this->data != NULL)){
                this->data[index] = value;
            }
        }
        T getValue()
        {
            T retorno = 0;
            if((this->position >= 0) && (this->position < this->length && this->data != NULL)){
                retorno = this->data[this->position];
                this->position = this->position + 1;
            }
            return retorno;
        }
        void setPosition(int n)
        {
            if(n >= 0 && n < this->length && this->data != NULL) this->position = n;
        }
        void index()
        {
            if(this->data != NULL && this->length > 0){
                for(this->position = 0; this->position < this->length; this->position = this->position + 1){
                    IO_printf("[%d] - %d\n", this->position + 1, this->data[this->position]);
                }
            } else {
                IO_printf("Não foi possivel mostra o seu arranjo!");
            }
        }
};