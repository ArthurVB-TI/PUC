using namespace std;

class Usuario{
    private:
        string nome;
        telefone* telf; 
        /* 
            Pensei em colocar telf em protected e atribuir uma herança,
            porem achei melhor não
        */
    public:
        void init_usuario(){
            this->telf = new telefone();
            this->nome = "";
        }
        Usuario(){ init_usuario(); }
        string getNome(){ return this->nome; }
        void updateNome(string n){ this->nome = n; }

        bool verificarNome(string n){
            bool v = true;
            for(int i = 0; i <= n.length() && !v; i = i + 1){
                if(n[i] != ' ' && !((n[i] <='A' && n[i] >= 'Z') || (n[i] <= 'a' && n[i] >= 'z'))){
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
            this->telf->set_fullNumber();
        }

        string getTelefone(){
            return this->telf->get_fullNumber();
        }

        void indexNome(){
            cout << "Nome: " << getNome() << endl;
        }
        void indexTelefone(){
            cout << "Telefone: " << getTelefone() << endl;
        }
};