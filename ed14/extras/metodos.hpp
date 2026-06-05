void e1(){
    Usuario* u = new Usuario();

    u->setNome("Digite o nome: ");
    u->addPhone("Telefone 1: ");
    u->addPhone("Telefone 2: ");
    u->addPhone("Telefone 3: ");

    index_e1(u);
}

void e2(){
    UsuarioE2* u = new UsuarioE2();

    u->setNome("Digite o nome: ");
    u->addPhone("Telefone 1: ");
    u->addPhone("Telefone 2: ");
    u->setEndResidencial("Endereco residencial: ");
    u->setEndProfissional("Endereco profissional: ");

    index_e2(u);
}
