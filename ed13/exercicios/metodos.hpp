using namespace std;

void m1(){
    Usuario* u = new Usuario();

    u->setNome("Digite um nome: ");
    u->indexNome();
}

void m2(){
    Usuario* u = new Usuario();
    
    u->setTelefone("Digite seu telefone: ");
    u->indexTelefone();
}

void m3(){
    Usuario* u = new Usuario();
    
    u->setTelefone("Digite seu telefone: "); // Metodo isValidPhone adicionado
    u->indexTelefone();
}

void m4(){
    Usuario* u = new Usuario();
    string arquivo_nome = "Pessoa1.txt";
    
    readFromFile(u,arquivo_nome);
    u->indexNome();
}

void m5(){
    Usuario* u = new Usuario();
    string arquivo_nome = "Pessoa1.txt";
    
    readFromFile(u,arquivo_nome); // Metodo de verificação adicionado
    u->indexNome();
}

void m6(){
    
}