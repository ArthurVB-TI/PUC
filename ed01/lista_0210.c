// 999999_AED1
/*
    Feito por: Arthur Victor
    03/03
*/

#include "io.h"

void method_01 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_01\n");

    int x = 10;
    printf("%s%d\n","x=",x);
    x = 15;
    printf("%s%d\n","x=",x);
    x = x + 1;
    printf("%s%d\n","x=",x);

    printf("%s", "Qual o novo valor (x)? ");
    scanf("%d", &x); getchar( );

    printf("%s%d\n","x=",x);
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_02 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_01\n");

    double x = 10.0;
    printf("%s%lf\n","x=",x);
    x = 15.0;
    printf("%s%lf\n","x=",x);
    x = x + 1.0;
    printf("%s%lf\n","x=",x);

    printf("%s", "Qual o novo valor (x)? ");
    scanf("%lf", &x); getchar( );

    printf("%s%lf\n","x=",x);
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_03 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_01\n");

    char x = 48;
    printf("%s%c\n","x=",x);
    x = x + 1;
    printf("%s%c\n","x=",x);
    x = x + '\1';
    printf("%s%c\n","x=",x);

    printf("%s", "Qual o novo valor (x)? ");
    scanf("%c", &x); getchar( );

    printf("%s%c\n","x=",x);
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_04 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_04\n");

    bool x = false;
    int y = 0;
    
    printf("%s%d\n","x=",x);
    x = 1;
    printf("%s%d\n","x=",x);
    x = true;
    printf("%s%d\n","x=",x);

    printf("%s", "Qual o novo valor (x)? ");
    scanf("%d", &y); getchar( );

    x = (y!=0); 

    printf("%s%d\n","x=",x);
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_05 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_05\n");

    char x[80] = "abc";
    char *px = &x[0];

    printf("%s%s\n","x=",x);

    printf("%s", "Qual o novo valor (x)? ");
    scanf("%s", px); getchar( );

    printf ( "%s%s\n", "x = ", px );
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_06 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_06\n");

    int x = 0;
    int y = 0;
    int z = 0;
    int *py = &y;
    
    printf("%s%d\n","x=",x);
    printf("%s%d\n","x=",y);

    printf("%s", "Entrar com outro valor inteiro: ");
    scanf("%d", &x); getchar( );

    printf("%s", "Entrar com outro valor inteiro: ");
    scanf("%i", py); getchar( );

    z = x * y;
    
    printf ( "%s(%i)*(%i) = (%d)\n", "z = ", x, y, z ); 
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_07 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_07\n");

    char x [80] = "abc";
    char y [80] = "def";
    char z [80];
    strcpy ( z, "" );

    printf ( "%s%s (%li)\n", "x = ", x, strlen(x)); 
    printf ( "%s%s (%li)\n", "y = ", y, strlen(y));
    
    printf ( "Entrar com caracteres: " ); 
    scanf ( "%s", x ); getchar ( );

    printf ( "Entrar com outros caracteres: " ); 
    scanf ( "%s", y ); getchar ( );

    strcpy ( z, x );
    strcat ( z, y );

    printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z ); 
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_08 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_08\n");

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    printf ( "%s%lf\n", "x = ", x );
    printf ( "%s%lf\n", "y = ", y );

    printf ( "Entrar com um valor real: " ); 
    scanf ( "%lf", &x ); getchar ( );

    printf ( "Entrar com outro valor real: " ); 
    scanf ( "%lf", &y ); getchar ( );

    z = pow(x,y);

    printf ( "%s(%lf) elevado a (%lf) = (%lf)\n", "z = ", x, y, z );

    x = pow(z,1.0/y);

    printf ( "%s(%lf) elevado a (1/%lf) = (%lf)\n", "z = ", z, y, x ); 

    z = sqrt(x);

    printf ( "%sraiz(%lf) = (%lf)\n", "z = ", x, z ); 
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_09 ( void )
{
    // identificar
    printf("%s\n", "\nMetodo_09\n");

    int x  =  0;
    double y = 3.5;
    char z =  'A';
    bool w = false;
    char s [80] = "";

    printf ( "01. %s%d\n" , "x = ", x );
    printf ( "02. %s%lf\n" , "y = ", y );
    printf ( "03. %s%c\n" , "z = ", z );

    x = (int) z;
    printf ( "04. %s%d -> %c\n" , "x = ", x, z );

    x = (int) y;
    printf ( "05. %s%d -> %lf\n", "x = ", x, y );

    x =  97;
    z = (char) x;
    printf ( "06. %s%c -> %d\n" , "z = ", z, x );

    x = (int)   '0';
    z = (char) x;
    printf ( "07. %s%c -> %d\n" , "z = ", z, x );
    
    x =  w;
    printf ( "08. %s%d -> %d\n" , "x = ", x, w );

    w =  true; 
    x =  w;
    printf ( "09. %s%d -> %d\n" , "x = ", x, w );

    x = (w==false);
    printf ( "10. %s%d -> %d\n" , "x = ", x, w );

    x = !(w==false);
    printf ( "11. %s%d -> %d\n" , "x = ", x, w );

    x = (w!=false);
    printf ( "12. %s%d -> %d\n" , "x = ", x, w );

        w =  (x == 0);   
    printf ( "13. %s%d == %d = %d\n" , "w = ", x, 0, w ); 
 
    w =  (x != 0);   
    printf ( "14. %s%d != %d = %d\n" , "w = ", x, 0, w ); 
 
    w =  (x < y);   
    printf ( "15. %s%d < %lf  = %d\n" , "w = ", x, y, w ); 
 
    w =  (x <= y);   
    printf ( "16. %s%d <= %lf = %d\n" , "w = ", x, y, w ); 
 
    w =  (y > x);   
    printf ( "17. %s%lf > %d  = %d\n" , "w = ", y, x, w ); 
 
    w =  (y >= x);   
    printf ( "18. %s%lf >= %d = %d\n" , "w = ", y, x, w ); 
 
    x = 4; 
    w =  (x % 2 == 0);  
    printf ( "19. %s (%d%%2) ? %d\n" , "e' par ", x, w );
 
    x = 4; 
    w =  (x % 2 != 0);  
    printf ( "20. %s (%d%%2) ? %d\n" , "e' impar ", x, w ); 
 
    z = '5'; 
    w =  ('0'<=z && z<='9'); 
    printf ( "21. %s (%c) ? %d\n" , "e' digito", z, w ); 
 
    z = 'x'; 
    w =  ('a'<=z && z<='z'); 
    printf ( "22. %s (%c) ? %d\n" , "e' minuscula ", z, w ); 
 
    z = 'X'; 
    w =  ( ! ('a'<=z && z<='z' ) ); 
    printf ( "23. %s (%c) ? %d\n" , "nao e' minuscula ", z, w ); 
 
    z = 'x'; 
    w =  ('A'<=z && z<='Z'); 
    printf ( "24. %s (%c) ? %d\n" , "e' maiuscula ", z, w ); 
 
    z = 'X'; 
    w =  ( (z < 'A') || ('Z' < z) ); 
    printf ( "25. %s (%c) ? %d\n" , "nao e' maiuscula ", z, w ); 
 
    z = '0'; 
    w =  ('0'==z || '1'==z);  
    printf ( "26. %s (%c) ? %d\n" , "e' 0 ou 1 ", z, w ); 
 
    strcpy ( s, "zero" );  
    printf ( "27. palavra   = %s\n", s ); 
 
    w = (strcmp ( "zero", s ) == 0); 
    printf ( "28. palavra   == %s ? %d\n", s, w ); 
 
    strcpy ( s, "um e dois" ); 
    printf ( "29. palavras = %s\n", s ); 
 
    w = (strcmp ( "zero", s ) != 0); 
    printf ( "30. palavra   == %s ? %d\n", s, w ); 
    
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
}

void method_10(void)
{
    printf("\nMetodo_10\n");
    
    int x = 5;
    double y = 3.5;
    char z = 'A';
    bool w = true;

    char a[STR_SIZE];
    char b[STR_SIZE];
    char c[STR_SIZE];

    strcpy(a, "abc");
    strcpy(b, "def");

    printf("\na = %s b = %s\n", a, b);

    strcpy(c, a);
    strcat(c, b);
    printf("\nc = [%s]+[%s] = [%s]\n", a, b, c);

    strcpy(a, "c = ");
    strcpy(c, "");

    printf("%s%c\n", a, z);
    printf("x = %d\n", x);
    printf("w = %d\n", w);

    strcpy(b, "");
    print("y = ");
    printf("%lf\n", y);

    z = readchar("char = ");
    printf("%s%c\n", a, z);

    y = readdouble("double = ");
    printf("%s%lf\n", a, y);

    x = readint("int = ");
    printf("%s%d\n", a, x);

    w = readbool("bool = ");
    printf("%s%d\n", a, w);

    strcpy(b, readstring("chars = "));
    printf("%s%s\n", a, b);

    strcpy(b, readln("line = "));
    printf("%s%s\n", a, b);

    pause("Apertar ENTER para terminar");
}

/*
   Acao principal.
*/
int main ( void )
{
    // definir dados
    int opcao = 0;
    // identificar
    printf("\n%s\n\n", "999999_AED1");
    // acoes
       // repetir
       do
       {
        // ler opcao do teclado
        printf ( "%s", "Qual a opcao? " );
        scanf  ( "%d", &opcao ); getchar( );
        // mostrar valor lido
        printf ( "%s%d\n", "opcao = ", opcao );
        // escolher opcao
        switch ( opcao )
        {
           case  0: /* nada */     break;
           case  1: method_01 ( ); break;
           case  2: method_02 ( ); break;
           case  3: method_03 ( ); break;
           case  4: method_04 ( ); break;
           case  5: method_05 ( ); break;
           case  6: method_06 ( ); break;
           case  7: method_07 ( ); break;
           case  8: method_08 ( ); break;
           case  9: method_09 ( ); break;
           case 10: method_10 ( ); break;
           default: printf ( "\n%s\n",
                           "ERRO: Opcao invalida.\n\n" );
            break;
        }
       } while ( opcao != 0 );
    // encerrar
    printf("%s\n", "\nApertar ENTER para terminar\n");
    getchar( );
	return ( 0 );
}