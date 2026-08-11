using namespace std;

void m1(){
    Usuario* u = new Usuario();

    u->setNome("Digite um nome: ");
    index_m1(u);
}

void m2(){
    Usuario* u = new Usuario();

    u->setTelefone("Digite seu telefone: ");
    index_m2(u);
}

void m3(){
    Usuario* u = new Usuario();

    u->setTelefone("Digite seu telefone: ");
    index_m3(u);
}

void m4(){
    Usuario* u = new Usuario();
    string arquivo_nome = "Pessoa1.txt";

    readFromFile(u, arquivo_nome);
    index_m4(u);
}

void m5(){
    Usuario* u = new Usuario();
    string arquivo_nome = "Pessoa1.txt";

    readFromFile(u, arquivo_nome);
    index_m5(u);
}

void m6(){
    Usuario* u = new Usuario("nome1", "99999-1111", "98888-2222");

    u->setTelefone("Digite o primeiro telefone: ");
    u->setPhone2a("Digite o segundo telefone: ");
    index_m6(u);
}

void m7(){
    Usuario* u = new Usuario("nome1", "99999-1111", "98888-2222");

    u->setTelefone("Digite o primeiro telefone: ");
    u->setPhone2a("Digite o segundo telefone: ");

    int n = u->phones();
    index_m7(u, n);
}

void m8(){
    Usuario* u = new Usuario();

    u->setTelefone("Digite o primeiro telefone: ");
    u->setPhone2a("Digite o segundo telefone: ");
    index_m8(u);
}

void m9(){
    Usuario* u = new Usuario();

    u->setTelefone("Digite o primeiro telefone: ");
    u->setPhone2b("Digite o segundo telefone: ");
    index_m9(u);
}

void m10(){
    Usuario* u = new Usuario();

    u->setTelefone("Digite o primeiro telefone: ");
    u->setPhone2a("Adicionando segundo telefone: ");
    u->setPhone2c();
    index_m10(u);
}
