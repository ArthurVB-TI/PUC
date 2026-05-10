#include "io.h"

/* Representações de classes criadas na biblioteca
 * Linha 317 - 536
 * Classes criadas para facilitar na reutilização e manipulação do texto passado do usuario
 * Possui:
   * Manipulação do texto (show e update)
   * Herança
   * Encapsulamento
   * Abstração
   * Mapeamento
   * Filtragem com intervalo
   * Redução
 */

chars p1(bool execute)
{
    if(execute){
        int qtde = 0;
        double a = 0.0;
        double b = 0.0;
        int count = 0;
        int fora = 0;

        a = IO_readdouble("Escreva o valor do primeiro intervalo: ");

        do{
            b = IO_readdouble("Escreva o valor do segundo intervalo (maior que o primeiro): ");
        }while(a >= b);

        qtde = IO_readint("Escreva uma quantidade inteira: ");
        IO_println("");

        for(int i = 0; i < qtde; i = i + 1){
            IO_printf("%d\t-\t", i+1);
            double value = IO_readdouble("");
            if(value >= a && value <= b){
                count = count + 1;
            }
        }
        
        IO_println("");
        IO_printf("%d valores estão dentro do intervalo e %d valores estão fora\n",count, (qtde - count));
    }
    return "Programa 1";
}

chars p2(bool execute)
{
    if(execute){
        chars texto = IO_new_chars(STR_SIZE);
        int count = 0;
        int i = 0;

        texto = IO_readstring("Escreva seu texto: ");
        int tamanho = strlen(texto);


        IO_println("Letras maiores que 'k' e menor que 'p':");
        IO_println("");
        
        while(i < tamanho){
            if(texto[i] > 'k' && texto[i] < 'p'){
                IO_printf("%d   -   %c\n",i+1,texto[i]);
                count = count + 1;
            }
            i = i + 1;
        }
        
        IO_println("");
        IO_printf("count  -  %d/%d\n",count,tamanho);
    }
    return "Programa 2";
}

chars p3(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C.Contar_OpenRage_filter(&C,'k','p');
        C.Contar_map(&C);
        
        IO_printf("Count: %d/%d\n\n",C.Contar_count(&C),M.Modificacoes_count(&M));
    }
    return "Programa 3";
}

chars p4(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C.Contar_OpenRage_filter(&C,'k','p');
        C.Contar_map(&C);
        
        IO_printf("\nTexto: %s\n\n",C.new_text);
        IO_printf("Count: %d/%d\n\n",C.Contar_count(&C),M.Modificacoes_count(&M));
    }
    return "Programa 4";
}

chars p5(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        Contar_Service C_S = create_Contar_Service(&C);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C_S.Contar_Service_OpenRage_double_filter(&C_S,'k','p','K','P');
        C_S.Contar_Service_map(&C_S);
        
        IO_printf("Count: %d/%d\n\n",C_S.Contar_Service_count(&C_S),M.Modificacoes_count(&M));
    }
    return "Programa 5";
}

chars p6(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        Contar_Service C_S = create_Contar_Service(&C);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C_S.Contar_Service_OpenRage_double_filter(&C_S,'k','p','K','P');
        C_S.Contar_Service_map(&C_S);
        
        IO_printf("\nTexto: %s\n",C_S.new_text);
        IO_printf("Count: %d/%d\n\n",C_S.Contar_Service_count(&C_S),M.Modificacoes_count(&M));
    }
    return "Programa 6";
}

chars p7(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        Contar_Service C_S = create_Contar_Service(&C);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C_S.Contar_Service_Nums_Impar_Filter(&C_S);
        C_S.Contar_Service_map(&C_S);
        
        IO_printf("\nTexto: %s\n",C_S.new_text);
        IO_printf("Count: %d/%d\n\n",C_S.Contar_Service_count(&C_S),M.Modificacoes_count(&M));
    }
    return "Programa 7";
}

chars p8(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        Contar_Service C_S = create_Contar_Service(&C);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C_S.Contar_Service_Alphanumeric_Filter(&C_S);
        C_S.Contar_Service_map_notAlpha(&C_S);
        
        IO_printf("\nTexto: %s\n",C_S.not_alpha);
        IO_printf("Count: %d/%d\n\n",C_S.Contar_Service_count_notAlpha(&C_S),M.Modificacoes_count(&M));
    }
    return "Programa 8";
}

chars p9(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        Contar_Service C_S = create_Contar_Service(&C);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C_S.Contar_Service_Alphanumeric_Filter(&C_S);
        C_S.Contar_Service_map(&C_S);
        
        IO_printf("\nTexto: %s\n",C_S.new_text);
    }
    return "Programa 9";
}

chars p10(bool execute)
{
    if(execute){
        Modificacoes M = create_Modificacoes();
        Contar C = create_Contar(&M);
        Contar_Service C_S = create_Contar_Service(&C);
        
        chars txt = IO_readstring("Escreva um texto: ");
        
        M.Modificacoes_update(&M,txt);
        C_S.Contar_Service_Alphanumeric_Filter(&C_S);
        C_S.Contar_Service_map(&C_S);
        
        IO_printf("\nTexto Alpha numerico: %s\n",C_S.new_text);
        IO_printf("\nTexto não Alpha numerico: %s\n",C_S.not_alpha);
        IO_printf("Count: %d/%d\n\n",C_S.Contar_Service_count(&C_S),M.Modificacoes_count(&M));
    }
    return "Programa 10";
}

int main()
{
    IO_id("Exercicios");
    Metodo metodos[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    IO_execute(10,metodos);
    return(0);
}