using namespace std;

class Usuario {
    private:
        string nome;

    protected:
        static const int MAX_PHONES = 10;
        int qtde;
        telefone* telf;
    public:
        void init_usuario(){
            this->qtde = 0;
            this->telf = new telefone[MAX_PHONES];
            this->nome = "";
        }
        void init_usuario(string n, string tel1){
            this->qtde = 1;
            this->nome = n;
            this->telf = new telefone[MAX_PHONES];
        }
        void init_usuario(string n, string tel1, string tel2){
            this->qtde = 2;
            this->nome = n;
            this->telf = new telefone[MAX_PHONES];
        }
        Usuario(){ init_usuario(); }
        Usuario(string n, string tel1){ init_usuario(n, tel1); }
        Usuario(string n, string tel1, string tel2){ init_usuario(n, tel1, tel2); }

        string getNome(){ return this->nome; }
        void updateNome(string n){ this->nome = n; }

        bool verificarNome(string n){
            bool v = true;
            for(int i = 0; i < n.length() && v; i = i + 1){
                if(n[i] != ' ' && !((n[i] >= 'A' && n[i] <= 'Z') || (n[i] >= 'a' && n[i] <= 'z'))){
                    v = false;
                }
            }
            return v;
        }
        void setNome(string text){
            string new_nome;
            do{
                cout << text;
                cin >> new_nome;
            }while(!verificarNome(new_nome));
            updateNome(new_nome);
        }

        int phones(){ return this->qtde; }

        void addPhone(string text){
            if(this->qtde >= MAX_PHONES){
                IO_error = 1;
                return;
            }
            cout << text << endl;
            this->telf[this->qtde].set_fullNumber();
            this->qtde = this->qtde + 1;
        }

        void removePhone(int index){
            if(index < 0 || index >= this->qtde){
                IO_error = 1;
                return;
            }
            for(int i = index; i < this->qtde - 1; i = i + 1){
                this->telf[i] = this->telf[i + 1];
            }
            this->telf[this->qtde - 1] = telefone();
            this->qtde = this->qtde - 1;
        }

        void indexNome(){
            cout << "Nome: " << getNome() << endl;
        }
        void indexTelefones(){
            for(int i = 0; i < this->qtde; i = i + 1){
                cout << "Telefone " << (i + 1) << ": " << this->telf[i].get_fullNumber() << endl;
            }
        }
};

class UsuarioE2 : public Usuario {
    private:
        string endResidencial;
        string endProfissional;
    public:
        UsuarioE2() : Usuario(){
            this->endResidencial = "";
            this->endProfissional = "";
        }
        UsuarioE2(string n, string tel1) : Usuario(n, tel1){
            this->endResidencial = "";
            this->endProfissional = "";
        }

        void setEndResidencial(string text){
            cout << text;
            cin.ignore();
            getline(cin, this->endResidencial);
        }
        void setEndProfissional(string text){
            cout << text;
            getline(cin, this->endProfissional);
        }

        string getEndResidencial(){ return this->endResidencial; }
        string getEndProfissional(){ return this->endProfissional; }

        void indexEnderecos(){
            cout << "End. Residencial: " << this->endResidencial << endl;
            cout << "End. Profissional: " << this->endProfissional << endl;
        }
};
