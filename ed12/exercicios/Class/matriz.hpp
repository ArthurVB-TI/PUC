namespace std;

template<class T>
class matriz
{
    private:
        T** data;
        int rows;
        int columns;
    public:
        int row_index;
        int column_index;
        matriz(){
            this->data = NULL;
            this->rows = 0;
            this->columns = 0;
        }
        matriz(int n, int m){
            if (n > 0 && m > 0){
                this->rows = n;
                this->columns = m;
                this->data = new T*[this->rows];
                for (this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    this->data[this->row_index] = new T[this->columns];
                }
            } else {
                IO_println("Dimensoes invalidas");
            }
        }
        void updateMatriz(int n,int m){
            if (n > 0 && m > 0){
                if (this->data != NULL){
                    for (this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                        delete[] this->data[i];
                    }
                    delete[] this->data;
                }
                this->rows = n;
                this->columns = m;
                this->data = new T*[this->rows];
                for (this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    this->data[this->row_index] = new T[this->columns];
                }
            } else {
                IO_println("Dimensoes invalidas");
            }
        }
        void setMatrizLength(){
            if(this->data != NULL){
                int n = 0;
                int m = 0;
                IO_readMatriz(n,m);
                updateMatriz(n,m);
            } else {
                IO_println("Matriz inexistente");
            }
        }
        void starterMatriz(T value){
            if (this->data != NULL){
                for (this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    for (this->column_index = 0; this->column_index < this->columns; this->column_index = this->column_index + 1){
                        this->data[this->row_index][this->column_index] = value;
                    }
                }
            } else {
                IO_println("Matriz inexistente");
            }
        }
        void setRandomMatriz(){
            if(this->data != NULL){
                for (this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    for (this->column_index = 0; this->column_index < this->columns; this->column_index = this->column_index + 1){
                        this->data[this->row_index][this->column_index] = IO_random(1,100);
                    }
                }
            } else {
                IO_println("Matriz inexistente");
            }
        }
        void setMatriz(int n,int m,T value){
            if(this->data != NULL){
                if(n >= 0 && m >= 0 && n <= this->rows && m <= this->columns){
                    this->data[n][m] = value;
                } else {
                    IO_println("Indices invalidos");
                }
            } else {
                IO_println("Matriz inexistente");
            }
        }
        void getValue(int n,int m){
            T retorno;
            if(this->data != NULL){
                if(n >= 0 && m >= 0 && n <= this->rows && m <= this->columns){
                    retorno = this->data[n][m];
                } else {
                    IO_println("Indices invalidos");
                }
            } else {
                IO_println("Matriz inexistente");
            }
            return retorno;
        }
        void getRows(){
            int retorno = 0;
            if(this->data != NULL){
                retorno =  this->rows;
            }
            return retorno;
        }
        void getColumns(){
            int retorno = 0;
            if(this->data != NULL){
                retorno =  this->columns;
            }
            return retorno;
        }
        void indexMatriz(){
            if(this->data != NULL){
                for (this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    for (this->column_index = 0; this->column_index < this->columns; this->column_index = this->column_index + 1){
                        cout << this->data[this->row_index][this->column_index] << " ";
                    }
                    cout << endl;
                }
            } else {
                IO_println("Matriz inexistente");
            }
        }
}