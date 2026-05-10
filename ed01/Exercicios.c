/*
    Feito por: Arthur Victor
*/
#include "io.h"

char* p1(bool executar)
{
    if (executar == true){
        long long resultado = 0LL;
        int x = 0;

        printf("\n");
        x = 2 * readint("Digite o valor dos lados de um quadrado: ");
    
        resultado = pow(x,2);
    
        printf("\n%s%lli\n\n","Area: ",resultado);
    }
    
    return "Programa 1";
}

char* p2(bool executar)
{
    if (executar == true){
        double area = 0.0;
        int perimetro = 0;
        double x = 0.0;

        printf("\n");
        x = readdouble("Digite o valor dos lados de um quadrado: ") / 4.0;
        
        area = pow(x,2);
        perimetro = x * 4.0;
    
        printf("\n%s%lf\n%s%d\n\n","Area: ",area,"Perimetro: ",perimetro);
    }
    
    return "Programa 2";
}

char* p3(bool executar)
{
    if (executar == true){
        int l1 = 0;
        int l2 = 0;
        long long resultado = 0LL;

        printf("\n");
        l1 = 4 * readint("Digite o valor do 1 lado de um retangulo: ");
        l2 = 4 * readint("Digite o valor do 2 lado de um retangulo: ");

        resultado = l1 * l2;

        printf("\n%s%lli\n\n","A area do retangulo é: ", resultado);
    }
    
    return "Programa 3";
}

char* p4(bool executar)
{
    if (executar == true){
        double area = 0.0;
        double perimetro = 0.0;
        double l1 = 0.0;
        double l2 = 0.0;

        printf("\n");
        l1 = readdouble("Digite o valor do 1 lado de um retangulo: ") / 3;
        l2 = readdouble("Digite o valor do 2 lado de um retangulo: ") / 3;
        
        area = l1 * l2;
        perimetro = (l1 + l2) * 2;
    
        printf("\n%s%lf\n%s%lf\n\n","Area: ",area,"Perimetro: ",perimetro);
    }
    
    return "Programa 4";
}

char* p5(bool executar)
{
    if (executar == true){
        double area = 0.0;
        double l1 = 0.0;
        double l2 = 0.0;

        printf("\n");
        l1 = readdouble("Digite o valor da altura de um triangulo: ") * 3;
        l2 = readdouble("Digite o valor da base de um triangulo: ") * 3;
        
        area = (l1 * l2) / 2;
    
        printf("\n%s%lf\n\n","Area: ",area);
    }
    
    return "Programa 5";
}

char* p6(bool executar)
{
    if (executar == true){
        double area = 0.0;
        double perimetro = 0.0;
        double altura = 0.0;
        double l1 = 0.0;

        printf("\n");
        l1 = readdouble("Digite o valor do lado de um triangulo equilatero: ") * (3.0/5.0);

        perimetro = l1 * 3;
        altura = sqrt(pow(l1,2) - pow((l1/2.0),2));
        area = pow(l1,altura)/2.0;
    
        printf("\n%s%lf\n%s%lf\n\n","Area: ",area,"Perimetro: ",perimetro);
    }
    
    return "Programa 6";
}

char* p7(bool executar)
{
    if (executar == true){
        double volume = 0.0;
        double l1 = 0.0;

        printf("\n");
        l1 = readdouble("Digite o valor do lado de um cubo: ") * 6;
            
        volume = pow(l1,3);
    
        printf("\n%s%lf\n\n","Volume: ",volume);
    }
    
    return "Programa 7";
}

char* p8(bool executar)
{
    if (executar == true){
        double volume = 0.0;
        double l1 = 0.0;
        double l2 = 0.0;
        double l3 = 0.0;

        printf("\n");
        l1 = readdouble("Digite o valor do comprimento de um cubo: ") * 5;
        l2 = readdouble("Digite o valor da altura de um cubo: ") * 5;
        l3 = readdouble("Digite o valor da largura de um cubo: ") * 5;
            
        volume = l1 * l2 * l3;
    
        printf("\n%s%lf\n\n","Volume: ",volume);
    }
    
    return "Programa 8";
}

char* p9(bool executar)
{
    if (executar == true){
        double area = 0.0;
        double l1 = 0.0;

        printf("\n");
        l1 = readdouble("Digite o valor do raio de um circulo: ") * 10;
            
        area = pow(l1,2) * M_PI;
    
        printf("\n%s%lf\n\n","Area: ",area);
    }
    
    return "Programa 9";
}

char* p10(bool executar)
{
    if (executar == true){
        double volume = 0.0;
        double l1 = 0.0;
        char *erros;

        printf("\n");
        l1 = readdouble("Digite o valor do raio de uma esfera: ") * (5.0/8.0);
            
        volume = pow(l1,3) * M_PI * (4/3);
    
        printf("\n%s%lf\n\n","Volume: ",volume);
    }
    
    return "Programa 10";
}

void main(void)
{
    int qtde_programas = 10;
    
    typedef char* (*Metodo)(bool);
    Metodo metodos[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    
    char* programas[qtde_programas];
    for (int i = 0; i < qtde_programas; i++){
        programas[i] = metodos[i](false);
    }

    printf("%s\n", "PROGRAMAS:");
    for (int i = 0; i < qtde_programas; i++){
        if (programas[i] != NULL){
            int execute;
            printf("\n%s",programas[i]);
            printf("\t-\t%s\n%s\n%s\n", "Deseja executar?","0 - yes","1 - no");
            scanf("%d", &execute); getchar();

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
        } else {
            printf("%s\n","PROGRAMAS NÃO EXECUTADO");
            printf("%s\n","TESTE (ERRO)");
        }
                
        
        getchar();
    }
}