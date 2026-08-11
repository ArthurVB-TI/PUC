#include <stdio.h>     
#include <stddef.h>    
#include <stdlib.h>    
#include <string.h>    
#include <stdarg.h>    
#include <stdbool.h>   
#include <ctype.h>     
#include <math.h>      
#include <time.h>      
#include <wchar.h>     

/**
   IO_lib - v2022-1
   Author: Arthur Victor Alves
 */

#ifndef __IO_REFS__
#define __IO_REFS__

#define nullptr   NULL
#define null      NULL

#define addr(p)  (&(p))
#define ref       *       
#define deref(p) (*(p))

#define val(p)   (*(p))
#define var       &       

#endif

#ifndef _IO_H_
#define _IO_H_
                          
#define  IO_printf        printf
#define  IO_scanf         scanf
#define  IO_fprintf       fprintf
#define  IO_fscanf        fscanf

#define  AND              &&
#define  OR               ||
#define  NOT              !
#define  XOR              ^

const   bool FALSE        = false;  
const   bool TRUE         = true ;  

const   char EOS          = '\0';   
const   char EOL          = '\n';   
const   char ENDL []      = "\n";   

const   char STR_EMPTY [] =  "" ;   
const   int  STR_SIZE     =  80 ;   

typedef char*   chars  ;            
typedef int*    ints   ;            
typedef double* doubles;            
typedef bool*   bools  ;            

static int  IO_error   = 0;                
static bool IO_trace   = true;             

static inline void IO_debugOFF ( )
{
  IO_trace = false;
} 

static inline void IO_debugON ( )
{
  IO_trace = true;
} 

static inline void IO_debug ( bool condition, char *text )
{
  if ( IO_trace && condition )
  {
     IO_printf ( "\nDBG> %s\n", text );
     getchar( );
  } 
} 

static inline void IO_clrscr ( )
{
#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    system ( "cls"   ); 
#elif defined(__linux__)
    system ( "clear" ); 
#elif defined(__APPLE__) && defined(__MACH__)
    system ( "clear" ); 
#elif defined(unix) || defined(__unix__) || defined(__unix)
    system ( "clear" ); 
#else
    #error Unknown_OS
#endif
} 

static inline void IO_flush ( )
{
    char x = '0';

    do { x = getchar( ); } while ( '\n' != x );
} 

static inline chars IO_version ( )
{
    chars x = "v.2022-1";
    return ( x );
} 

static inline void IO_id ( chars text )
{
    IO_printf ( "%s\n", text );
    IO_printf ( "%s\n", "Autor: Arthur Victor Alves" );
    IO_printf ( "\n" );          
} 

static inline int IO_readint ( chars text )
{
    int x = 0;
    IO_printf ( "%s", text );
    IO_scanf  ( "%d", &x );
    getchar   ( );
    return    ( x );
} 

static inline double IO_readdouble ( chars text )
{
    double x = 0.0;
    IO_printf ( "%s", text );
    IO_scanf  ( "%lf", &x );
    getchar   ( );
    return    ( x );
} 

static inline float IO_readfloat ( chars text )
{
    float x = 0.0;
    IO_printf ( "%s", text );
    IO_scanf  ( "%f", &x );
    getchar   ( );
    return    ( x );
} 

static inline bool IO_readbool ( chars text )
{
    int x = 0;
    IO_printf ( "%s", text );
    IO_scanf  ( "%d", &x );
    getchar   ( );
    return    ( x!=0 );
} 

static inline char IO_readchar ( chars text )
{
    char x = '0';
    IO_printf ( "%s", text );
    do { x = getchar( ); } while ( '\n' == x ); 
    getchar ( );
    return ( x );
} 

static inline void IO_pause ( chars text )
{
    char x = '0';
    IO_printf ( "\n%s\n", text );
    do { x = getchar( ); } while ( '\n' != x );
} 

static inline chars IO_new_chars ( int size )
{
    return ( (chars) malloc ( (size+1)*sizeof(char) ) );
} 

static inline ints IO_new_ints ( int size )
{
    return ( (ints) malloc ( (size)*sizeof(int) ) );
} 

static inline doubles IO_new_doubles ( int size )
{
    return ( (doubles) malloc ( (size)*sizeof(double) ) );
} 

static inline bools IO_new_bools ( int size )
{
    return ( (bools) malloc ( (size)*sizeof(bool) ) );
} 

static inline chars IO_concat ( chars text1, chars text2 )
{                               
    chars buffer = IO_new_chars ( strlen(text1)+strlen(text2)+1 );
    strcpy ( buffer, text1 );
    strcat ( buffer, text2 );
    return ( buffer );
} 

static inline chars IO_toString_b ( bool x )
{                               
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%d", x );
    return  ( buffer );
} 

static inline chars IO_toString_c ( char x )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%c", x );
    return  ( buffer );
} 

static inline chars IO_toString_d ( int x )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%d", x );
    return  ( buffer );
} 

static inline chars IO_toString_f ( double x )
{                               
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%lf", x );
    return  ( buffer );
} 

static inline void IO_print ( chars text )
{
    IO_printf ( "%s", text );
} 

static inline void IO_println ( chars text )
{
    IO_printf ( "%s\n", text );

} 

static inline void IO_fprint ( FILE* filePtr, chars text )
{
    IO_fprintf ( filePtr, "%s", text );
} 










static inline bool IO_par( int valor )
{
    bool result = false;
    if(valor % 2 == 0 || valor == 0){ result = true; }
    return result;
}

static inline bool IO_positivo( int valor )
{
    bool result = false;
    if(valor >= 0){ result = true; }
    return result;
}

static inline bool IO_readLetra( char valor )
{
    bool result = false;
    if((valor >= 'a' && valor <= 'z') || (valor >= 'A' && valor <= 'Z')){ result = true; }
    return result;
}

static inline bool IO_readNumero( char valor )
{
    bool result = false;
    if(valor >= '0' && valor <= '9'){ result = true; }
    return result;
}

typedef char* (*Metodo)(bool);

static inline void IO_execute(int qtde_p, Metodo metodos[])
{
    int qtde_programas = qtde_p;

    char* programas[qtde_programas];

    for (int i = 0; i < qtde_programas; i++){
        programas[i] = metodos[i](false);
    }

    printf("PROGRAMAS:\n");

    for (int i = 0; i < qtde_programas; i++){
        if (programas[i] != NULL){

            int execute;

            printf("\n%s", programas[i]);
            printf("\t-\tDeseja executar?\n0 - yes\n1 - no\n");

            scanf("%d", &execute);

            if (execute == 0){
                metodos[i](true);
            }

            printf("TESTE (OK)\n\n");
        }
        else{
            printf("PROGRAMA NÃO EXECUTADO\n");
            printf("TESTE (ERRO)\n");
        }

        getchar();
    }
}

typedef struct Modificacoes Modificacoes;
typedef struct Contar Contar;
typedef struct Contar_Service Contar_Service;
typedef struct Palavras Palavras;

struct Modificacoes{
    chars texto;
    void (*Modificacoes_show)(Modificacoes *);
    void (*Modificacoes_update)(Modificacoes *,chars);
    int (*Modificacoes_count)(Modificacoes *);
};

void Modificacoes_show(Modificacoes *m){ IO_printf("Texto: %s",m->texto); }
void Modificacoes_update(Modificacoes *m,chars new_texto){ strncpy(m->texto, new_texto, STR_SIZE-1); }
int Modificacoes_count(Modificacoes *m){
    chars texto = m->texto;
    int count = 0;
    for(int i = 0; i < strlen(texto); i = i + 1){
        count = count + 1;
    }
    return count;
}

Modificacoes create_Modificacoes(){ 
    chars txt = IO_new_chars(STR_SIZE);
    memset(txt, 0, STR_SIZE);
    
    Modificacoes M = {txt, Modificacoes_show,Modificacoes_update,Modificacoes_count};
    return M;
}

struct Contar{
    Modificacoes *Modif;
    chars new_text;
    void (*Contar_OpenRage_filter)(Contar *,char,char);
    void (*Contar_map)(Contar *);
    int (*Contar_count)(Contar *);
};

void Contar_OpenRage_filter(Contar *c, char v_1, char v_2){
    chars t = c->Modif->texto;
    memset(c->new_text, 0, STR_SIZE);
    int size = strlen(t);
    for(int i = 0; i < size; i = i + 1){
        if(t[i] > v_1 AND t[i] < v_2){
            char temp[2] = {t[i], '\0'};
            strcat(c->new_text, temp);
        }
    }
}
void Contar_map(Contar *c){
    chars texto = c->new_text;
    for(int i = 0; i < strlen(texto); i = i + 1){
        IO_printf("%d\t-\t%c\n",i+1,texto[i]);
    }
}
int Contar_count(Contar *c){
    chars texto = c->new_text;
    int count = 0;
    for(int i = 0; i < strlen(texto); i = i + 1){
        count = count + 1;
    }
    return count;
}

Contar create_Contar(Modificacoes *M){ 
    chars txt = IO_new_chars(STR_SIZE);
    memset(txt, 0, STR_SIZE);
    
    Contar C = {M, txt, Contar_OpenRage_filter,Contar_map,Contar_count};
    return C;
}

struct Contar_Service{
    Contar *Cont;
    chars new_text;
    chars not_alpha;
    void (*Contar_Service_OpenRage_double_filter)(Contar_Service *,char,char,char,char);
    void (*Contar_Service_Nums_Impar_Filter)(Contar_Service *);
    void (*Contar_Service_Alphanumeric_Filter)(Contar_Service *);
    void (*Contar_Service_map)(Contar_Service *);
    void (*Contar_Service_map_notAlpha)(Contar_Service *);
    int (*Contar_Service_count)(Contar_Service *);
    int (*Contar_Service_count_notAlpha)(Contar_Service *);
};

void Contar_Service_OpenRage_double_filter(Contar_Service *c_s, char v_1, char v_2,char v_3, char v_4){
    chars t = c_s->Cont->Modif->texto;
    memset(c_s->new_text, 0, STR_SIZE);
    int size = strlen(t);
    for(int i = 0; i < size; i = i + 1){
        if((t[i] > v_1 AND t[i] < v_2) OR (t[i] > v_3 AND t[i] < v_4)){
            char temp[2] = {t[i], '\0'};
            strcat(c_s->new_text, temp);
        }
    }
}
void Contar_Service_Nums_Impar_Filter(Contar_Service *c_s){
    chars t = c_s->Cont->Modif->texto;
    memset(c_s->new_text, 0, STR_SIZE);
    int size = strlen(t);
    for(int i = 0; i < size; i = i + 1){
        if((int) t[i] % 2 != 0){
            char temp[2] = {t[i], '\0'};
            strcat(c_s->new_text, temp);
        }
    }
}
void Contar_Service_Alphanumeric_Filter(Contar_Service *c_s){
    chars t = c_s->Cont->Modif->texto;
    memset(c_s->new_text, 0, STR_SIZE);
    memset(c_s->not_alpha, 0, STR_SIZE);
    int size = strlen(t);
    for(int i = 0; i < size; i = i + 1){
        if((t[i] >= 'a' AND t[i] <= 'z') OR (t[i] >= 'A' AND t[i] <= 'Z') OR (t[i] >= '0' AND t[i] <= '9')){
            char temp[2] = {t[i], '\0'};
            strcat(c_s->new_text, temp);
        } else {
            char temp[2] = {t[i], '\0'};
            strcat(c_s->not_alpha, temp);
        }
    }
}
void Contar_Service_map(Contar_Service *c_s){
    chars texto = c_s->new_text;
    for(int i = 0; i < strlen(texto); i = i + 1){
        IO_printf("%d\t-\t%c\n",i+1,texto[i]);
    }
}
void Contar_Service_map_notAlpha(Contar_Service *c_s){
    chars texto = c_s->not_alpha;
    for(int i = 0; i < strlen(texto); i = i + 1){
        IO_printf("%d\t-\t%c\n",i+1,texto[i]);
    }
}
int Contar_Service_count(Contar_Service *c_s){
    chars texto = c_s->new_text;
    int count = 0;
    for(int i = 0; i < strlen(texto); i = i + 1){
        count = count + 1;
    }
    return count;
}
int Contar_Service_count_notAlpha(Contar_Service *c_s){
    chars texto = c_s->not_alpha;
    int count = 0;
    for(int i = 0; i < strlen(texto); i = i + 1){
        count = count + 1;
    }
    return count;
}
Contar_Service create_Contar_Service(Contar *C){ 
    chars txt = IO_new_chars(STR_SIZE);
    memset(txt, 0, STR_SIZE);
    chars txt2 = IO_new_chars(STR_SIZE);
    memset(txt2, 0, STR_SIZE);
    
    Contar_Service C_S = {C, txt, txt2, Contar_Service_OpenRage_double_filter, Contar_Service_Nums_Impar_Filter,Contar_Service_Alphanumeric_Filter,Contar_Service_map,Contar_Service_map_notAlpha,Contar_Service_count,Contar_Service_count_notAlpha};
    return C_S;
}

struct Palavras{
    Modificacoes *Modif;
    char **new_text;
    void (*Palavras_Reset)(Palavras *,int);
    void (*Palavras_Words_filter)(Palavras *);
    void (*Palavras_map)(Palavras *);
    int (*Palavras_count)(Palavras *);
};

void Palavras_Reset(Palavras *p,int tamanho){
    p->new_text = malloc((tamanho + 1) * sizeof(char*));

    for(int i = 0; i < tamanho; i++){
        p->new_text[i] = calloc(50, sizeof(char));
    }

    p->new_text[tamanho] = NULL;
}
void Palavras_Words_filter(Palavras *p){
    chars t = p->Modif->texto;

    int size = strlen(t);
    Palavras_Reset(p, (size/2)+1);

    int index = 0;

    for(int i = 0; i < size; i = i + 1){
        if(t[i] != ' ' AND t[i] != '\n'){
            char temp[2] = {t[i], '\0'};
            strcat(p->new_text[index], temp);
        } else {
            if(strlen(p->new_text[index]) > 0){
                index = index + 1;
            }
        }
    }
    p->new_text[index + 1] = NULL;
}
void Palavras_map(Palavras *p){
    char **texto = p->new_text;
    for(int i = 0; texto[i] != NULL; i = i + 1){
        IO_printf("%d\t-\t%s\n",i+1,texto[i]);
    }
}
int Palavras_count(Palavras *p){
    char **texto = p->new_text;
    int count = 0;
    for(int i = 0; texto[i] != NULL; i = i + 1){
        count = count + 1;
    }
    return count;
}

Palavras create_Palavras(Modificacoes *M){ 
    char **txt = NULL;
    
    Palavras P = {M, txt, Palavras_Reset,Palavras_Words_filter,Palavras_map,Palavras_count};
    return P;
}











static inline void IO_fprintln ( FILE* filePtr, chars text )
{
    IO_fprintf ( filePtr, "%s\n", text );
} 

static inline chars IO_fread ( FILE* filePtr )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );

    IO_fscanf ( filePtr, "%s", buffer ); 
    return ( buffer );
} 

static inline chars IO_freadln ( FILE* filePtr )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );

    fgets  ( buffer, STR_SIZE, filePtr ); 
    buffer [ strlen (buffer)-1 ] = EOS;   
    return ( buffer );
} 

static inline chars IO_readstring ( chars text )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    char  x = '0';
    IO_printf ( "%s", text   );
    IO_scanf  ( "%s", buffer );    
    IO_flush  ( );
    return ( buffer );
} 

static inline chars IO_readln ( chars text )
{
    IO_printf ( "%s", text );
    return ( IO_freadln ( stdin ) );
} 

static inline chars IO_boolalpha ( bool value )
{
    if ( value )
       return ( "true"  );
    else
       return ( "false" );
} 

static inline bool IO_check ( void *p1, void *p2, int size )
{
    return ( p1 && p2 && (0==memcmp( p1, p2, size )) );
} 

static inline int IO_length ( char* text )
{
    int x = 0;
    if ( text )
    { x = strlen(text); }
    return ( x );
} 

static inline char IO_charAt ( char* text, unsigned int index )
{
    char x = '\0';
    if ( text && 0 <= index && index < strlen(text) )
    {  x = text [ index ]; }
    return ( x );
} 

static inline char* IO_substring ( char *text, int start, int size )
{
    chars buffer = NULL;
    if ( start >= 0 && size > 0 && (start+size) < strlen(text) )
    {
       buffer = IO_new_chars ( size+1 );
       memcpy ( buffer, text+start, size );
       buffer [size] = '\0';
    }
    return ( buffer );
} 

#endif