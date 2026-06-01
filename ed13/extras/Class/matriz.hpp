using namespace std;

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
                        delete[] this->data[this->row_index];
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
        void addRows(int position, int qtde, int constante){
            if(this->data != NULL && position >= 0 && position <= this->rows && qtde > 0){
                int new_rows = this->rows + qtde;
                T** new_data = new T*[new_rows];
                this->row_index = 0;
                position = position - 1;
                for(this->row_index = 0; this->row_index < position; this->row_index = this->row_index + 1){
                    new_data[this->row_index] = this->data[this->row_index];
                }
                for(int i = 0; i < qtde; i = i + 1){
                    new_data[position + i] = new T[this->columns];
                    for(this->column_index = 0; this->column_index < this->columns; this->column_index = this->column_index + 1){
                        new_data[position + i][this->column_index] = this->data[0][this->column_index]*((T) constante);
                    }
                }
                for(this->row_index = position; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    new_data[this->row_index + qtde] = this->data[this->row_index];
                }
                delete[] this->data;
                this->data = new_data;
                this->rows = new_rows;
            } else {
                IO_println("Parametros invalidos");
            }
        }
        void subtractRows(int position, int qtde, int constante){
            if(this->data != NULL && position >= 0 && position <= this->rows && qtde > 0){
                int new_rows = this->rows + qtde;
                T** new_data = new T*[new_rows];
                this->row_index = 0;
                position = position - 1;
                for(this->row_index = 0; this->row_index < position; this->row_index = this->row_index + 1){
                    new_data[this->row_index] = this->data[this->row_index];
                }
                for(int i = 0; i < qtde; i = i + 1){
                    new_data[position + i] = new T[this->columns];
                    for(this->column_index = 0; this->column_index < this->columns; this->column_index = this->column_index + 1){
                        new_data[position + i][this->column_index] = intModule(this->data[0][this->column_index] - constante)*((T) constante);
                    }
                }
                for(this->row_index = position; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    new_data[this->row_index + qtde] = this->data[this->row_index];
                }
                delete[] this->data;
                this->data = new_data;
                this->rows = new_rows;
            } else {
                IO_println("Parametros invalidos");
            }
        }
        void setMatrizLength(){
            int n = 0;
            int m = 0;
            IO_readMatriz(&n,&m);
            updateMatriz(n,m);
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
                if(n >= 0 && m >= 0 && n < this->rows && m < this->columns){
                    this->data[n][m] = value;
                } else {
                    IO_println("Indices invalidos");
                }
            } else {
                IO_println("Matriz inexistente");
            }
        }
        T getValue(int n,int m){
            T retorno;
            if(this->data != NULL){
                if(n >= 0 && m >= 0 && n < this->rows && m < this->columns){
                    retorno = this->data[n][m];
                } else {
                    IO_println("Indices invalidos");
                }
            } else {
                IO_println("Matriz inexistente");
            }
            return retorno;
        }
        int getRows(){
            int retorno = 0;
            if(this->data != NULL){
                retorno = this->rows;
            }
            return retorno;
        }
        int getColumns(){
            int retorno = 0;
            if(this->data != NULL){
                retorno = this->columns;
            }
            return retorno;
        }
        void fgetMatriz(std::string arquivo_nome){
            FILE* arquivo = fopen(arquivo_nome.c_str(), "r");
            if(arquivo == NULL){
                IO_println("Arquivo inexistente");
                return;
            }
            int n = 0;
            int m = 0;
            fscanf(arquivo, "%d %d", &n, &m);
            updateMatriz(n, m);
            for(this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                for(this->column_index = 0; this->column_index < this->columns; this->column_index = this->column_index + 1){
                    int valor = 0;
                    fscanf(arquivo, "%d", &valor);
                    this->data[this->row_index][this->column_index] = (T) valor;
                }
            }
            fclose(arquivo);
        }
        void transposta(){
            if(this->data != NULL && this->columns > 0 && this->rows > 0){
                T** new_data = new T*[this->columns];
                for(int i = 0; i < this->rows; i = i + 1){
                    new_data[i] = new T[this->rows];
                }
                for(int i = 0; i < this->rows; i = i + 1){
                    for(int j = 0; j < this->columns; j = j + 1){
                        new_data[j][i] = this->data[i][j];
                    }
                }
                this->data = new_data;
            }
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
        bool searchRow(int value,int *n){
            int retorno = false;
            if(this->data != NULL){
                for(this->row_index = 0; this->row_index < this->rows && !retorno; this->row_index = this->row_index + 1){
                    for(this->column_index = 0; this->column_index < this->columns && !retorno; this->column_index = this->column_index + 1){
                        if(value == this->data[this->row_index][this->column_index]){
                            retorno = true;
                            *n = this->row_index + 1;
                        }
                    }
                }
            }
            return retorno;
        }
        bool searchColumn(int value,int *n){
            int retorno = false;
            *n = -1;
            if(this->data != NULL){
                for(this->row_index = 0; this->row_index < this->rows; this->row_index = this->row_index + 1){
                    for(this->column_index = 0; this->column_index < this->columns; this->column_index = this->column_index + 1){
                        if(value == this->data[this->row_index][this->column_index] && (*n - 1 > this->column_index || !retorno)){
                            retorno = true;
                            *n = this->column_index + 1;
                        }
                    }
                }
            }
            return retorno;
        }
};
