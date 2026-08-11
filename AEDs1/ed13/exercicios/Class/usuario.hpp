using namespace std;

class Usuario{
    private:
        string nome;

        int qtde;
        telefone* telf;
    public:
        void init_usuario(){
            this->qtde = 0;
            this->telf = new telefone[2];
            this->nome = "";
        }
        void init_usuario(string n, string tel1){
            this->qtde = 1;
            this->nome = n;
            this->telf = new telefone[2];
        }
        void init_usuario(string n, string tel1, string tel2){
            this->qtde = 2;
            this->nome = n;
            this->telf = new telefone[2];
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

        void setTelefone(string text){
            cout << text << endl;
            this->telf[0].set_fullNumber();
            this->qtde = (this->qtde < 1 ? 1 : this->qtde);
        }

        string getTelefone(){
            return this->telf[0].get_fullNumber();
        }

        int phones(){
            return this->qtde;
        }

        void setPhone2a(string text){
            if(this->qtde < 2){
                int resp = IO_readint("Deseja adicionar um segundo telefone? (1=Sim / 0=Nao): ");
                if(resp != 1) return;
                this->qtde = 2;
            }
            cout << text << endl;
            this->telf[1].set_fullNumber();
        }

        void setPhone2b(string text){
            if(this->qtde < 2){
                IO_error = 1;
                return;
            }
            cout << text << endl;
            this->telf[1].set_fullNumber();
        }

        void setPhone2c(){
            if(this->qtde < 2){
                IO_error = 1;
                return;
            }
            this->telf[1] = telefone();
            this->qtde = 1;
        }

        void indexNome(){
            cout << "Nome: " << getNome() << endl;
        }
        void indexTelefone(){
            cout << "Telefone 1: " << this->telf[0].get_fullNumber() << endl;
            if(this->qtde >= 2)
                cout << "Telefone 2: " << this->telf[1].get_fullNumber() << endl;
        }
};
