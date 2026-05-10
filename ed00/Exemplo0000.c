/*
    
    Arthur Victor Alves
    Exemplo0000 - v0.0. - 25/02/2026

    Obs: eu ja programei antes, então utilizei alguns comandos ainda não feitos em sala, tambêm utilizei uma logica mais avançada.

*/

#include <stdio.h>
#include <stdbool.h>

// metodo pedido
void method_01( void ){
    printf("Bem vindo ao Metodo 01\n\n");
}

// criando uma função para cada questão
char* E00( bool execute ){
    if (execute == true){
        printf("Não possui nada nessa questão\n");
    }
    return "Exemplo0000 - Programa = v0.0";
}

char* E01( bool execute ){
    if (execute == true){
        printf("Não possui nada nessa questão\n");
    }
    return "Exemplo0001 - Programa = v0.1";
}

char* E02( bool execute ){
    if (execute == true){
        int opcao;
        printf("%s","Opção = ");
        
        scanf("%d\n", &opcao);
        getchar();
        
        printf("%s\t%d\n", "Opção escrita foi: ", opcao);
    }
    return "Exemplo0002 - Programa = v0.2";
}

char* E03( bool execute ){
    if (execute == true){
        printf("%s\n", "Opções:");
        printf("%s\t%s\n","0.","Terminar");
        
        int opcao;
        printf("%s","Opção = ");
        
        scanf("%d\n", &opcao);
        getchar();
        
        printf("%s\t%d\n", "Opção escrita foi: ", opcao);
    }
    return "Exemplo0003 - Programa = v0.3";
}

char* E04( bool execute ){
    if (execute == true){
        printf("%s\n", "Opções:");
        printf("%s\t%s\n","0.","Terminar");
        printf("%s\t%s\n","1.","Metodo 01");
        
        int opcao;
        printf("%s","Opção = ");
        
        scanf("%d\n", &opcao);
        getchar();
        
        printf("%s\t%d\n", "Opção escrita foi: ", opcao);

        switch(opcao){
            case 0:
                break;
            case 1:
                method_01();
            default:
                printf("%s\n","Opção invalida");
                break;
        }
    }
    return "Exemplo0004 - Programa = v0.4";
}

char* E05( bool execute ){
    if (execute == true){
        printf("%s\n", "Opções:");
        printf("%s\t%s\n","0.","Terminar");
        printf("%s\t%s\n","1.","Metodo 01");
        
        int opcao;
        printf("%s","Opção = ");
        
        scanf("%d\n", &opcao);
        getchar();
        
        printf("%s\t%d\n", "Opção escrita foi: ", opcao);

        do
        {
            switch(opcao){
                case 0:
                    break;
                case 1:
                    method_01();
                    printf("\n%s\n","Escolha outra opção");
                    scanf("%d\n",&opcao);
                    break;
                default:
                    printf("%s\n","Opção invalida");
                    printf("\n%s\n","Escolha outra opção");
                    scanf("%d\n",&opcao);
                    break;
            }
        } while (opcao != 0);
    }
    return "Exemplo0005 - Programa = v0.5";
}

// função principal que sera executada
int main( int argc, char* argv[] ){
    // eu
    printf ( "%s\n\n", "Autor: Arthur Victor Alves" );

    // armazenando todos os resultados dentro de um array para mostrar tudos juntos
    int qtde_questoes = 6; // quantidade de questoes

    typedef char* (*Metodo)(bool);
    Metodo metodos[] = {E00,E01,E02,E03,E04,E05}; // metodos armazenados
    
    char* questoes[qtde_questoes];
    for (int i = 0; i < qtde_questoes; i++){
        questoes[i] = metodos[i](false);
    }

    // mostrando todas as questões utilizado um comando de repetição (for), o mesmo mostrado na sala
    printf("%s\n", "QUESTÕES:");
    bool resultados[qtde_questoes]; // armazenando resultados das questões para mostrar no futuro
    for (int i = 0; i < qtde_questoes; i++){ // for executando a mesma quantidade de questões
        if (questoes[i] != NULL){ // caso eu tenha feito o numero da questão
            int execute;
            printf("%s\n",questoes[i]);
            printf("%s\n%s\n%s\n", "Deseja executar?","0 - yes","1 - no");
            scanf("%d", &execute);

            do{
                switch (execute){
                    case 0:
                        metodos[i](true);
                        break;
                    default:
                        break;
                }
            } while (execute != 0 && execute != 1);
            
            printf("%s\n\n","TESTE (OK)");

            // armazenando o resultado
            resultados[i] = true;
        } else {
            // caso eu não tenha feito a questão
            printf("%s\n","QUESTÃO NÃO PASSADA");
            printf("%s\n","TESTE (ERRO)");

            // armazenando o resultado
            resultados[i] = false;
        }
                
        
        getchar();
    }

    // mostrando todos os resultados
    printf("%s\t%s\n","Versao","Teste");
    for (int i = 0; i < qtde_questoes; i++){
        if (resultados[i] == true){
            printf("0.%d\t%s\t%s\n",i,"01.(OK)","identificacao de programa");
        } else {
            printf("0.%d\t%s\t%s\n",i,"01.(ERRO)","identificacao de programa");
        }
    }

    // repetição para mostrar todos os resultados passados dentro do parametro
    printf("\n%s\n","Argumentos passados:");
    for (int i = 0; i < argc; i++) {
        printf("%d%s%s\n", i , " - ", argv[i]);
    }

    // final da função
    printf("\n\nDigite ENTER para sair");
    getchar();
    return 0;
}