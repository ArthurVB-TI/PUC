using namespace std;

class telefone{
    private:
        int* ddi;
        int* ddd;
        int* number;
        int ddi_length;
        int ddd_length;
        int number_length;
        string full;

    private:
        bool isValidPhone(string text){
            bool retorno = true;
            int index = 0;
            // foreach
            if(text.length() <= this->number_length + 1){
                for(int n : text){
                    if(!(n >= '0' && n <= '9')){
                        if(text.length() - 5 == index){
                            if(n != '-') retorno = false;
                        } else {
                            retorno = false;
                        }
                    }
                    index = index + 1;
                }
            } else {
                retorno = false;
            }
            return retorno;
        }
    public:
        void init_telefone(){
            this->ddi_length = 3;
            this->ddd_length = 2;
            this->number_length = 9;
            this->ddi = new int[this->ddi_length];
            this->ddd = new int[this->ddd_length];
            this->number = new int[this->number_length];
        }
        telefone(){ init_telefone(); }

        void set_ddi(string n){
            string new_ddi = "";
            bool v = false;
            int count = 0;
            int* numbers = new int[this->ddi_length];
            
            do{
                cout << n;
                cin >> new_ddi;
                count = 0;
                for(int i = 0; i < new_ddi.length() && count <= 3; i = i + 1){
                    if(new_ddi[i] >= '0' && new_ddi[i] <= '9'){
                        count = count + 1;
                        numbers[count - 1] = (int)new_ddi[i] - 48;
                    }
                }
                if(count > 0 && count <= this->ddi_length){
                    v = true;
                    new_ddi = new_ddi.substr(0, count);
                    if(count < this->ddi_length) numbers[count] = -1;
                }
            }while(!v);

            this->ddi = numbers;
        }
        void set_ddd(string n){
            string new_ddd = "";
            bool v = false;
            int count = 0;
            int* numbers = new int[this->ddd_length];
            
            do{
                cout << n;
                cin >> new_ddd;
                count = 0;
                for(int i = 0; i < new_ddd.length() && count <= 2; i = i + 1){
                    if(new_ddd[i] >= '0' && new_ddd[i] <= '9'){
                        count = count + 1;
                        numbers[count - 1] = (int)new_ddd[i] - 48;
                    }
                }
                if(count > 0 && count <= this->ddd_length){
                    v = true;
                    new_ddd = new_ddd.substr(0, count);
                    if(count < this->ddd_length) numbers[count] = -1;
                }
            }while(!v);

            this->ddd = numbers;
        }
        void set_number(string n){
            string new_number = "";
            bool v = false;
            int count = 0;
            int* numbers = new int[this->number_length];
            
            do{
                cout << n;
                cin >> new_number;
                count = 0;
                if(isValidPhone(new_number)){
                    for(int i = 0; i < new_number.length() && count <= 9; i = i + 1){
                        if(new_number[i] >= '0' && new_number[i] <= '9'){
                            numbers[count] = (int)new_number[i] - 48;
                            count = count + 1;
                        }
                    }
                    if(count == this->number_length - 1 || count == this->number_length){
                        v = true;
                        new_number = new_number.substr(0, count);
                        if(count < this->number_length) numbers[count] = -1;
                    }
                }
            }while(!v);

            this->number = numbers;
        }
        void set_fullNumber(){
            set_ddi("Digite o seu ddi: ");
            set_ddd("Digite o seu ddd: ");
            set_number("Digite o seu número: ");

            string a = "";
            string b = "";
            string c = "";
            for(int i = 0; i <= this->number_length; i = i + 1){
                if(i < this->ddi_length && this->ddi[i] != -1){
                    a = a + to_string(this->ddi[i]);
                }
                if(i < this->ddd_length && this->ddd[i] != -1){
                    b = b + to_string(this->ddd[i]);
                }
                if(i < this->number_length && this->number[i] != -1){
                    c = c + to_string(this->number[i]);
                }
            }
            c.insert(5,"-");
            this->full = ("+" + a) + (" (" + b + ") ") + c;
        }
        int* get_ddi(){ return this->ddi; }
        int* get_ddd(){ return this->ddd; }
        int* get_number(){ return this->number; }
        string get_fullNumber(){ return this->full; }

        void index(){
            cout << "O seu número de telefone é: " << get_fullNumber() << endl;
        }
};