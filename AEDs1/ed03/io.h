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