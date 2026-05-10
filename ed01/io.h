// 999999_AED1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define STR_SIZE 80

void  print   ( char *text )
{
    printf    ( "%s"  , text );    
}
void  println ( char *text )
{
    printf    ( "%s\n", text );    
}
void  pause   ( char *text )
{
    printf    ( "%s\n", text );    
    getchar   ( );
}
void  flush   ( void )
{
    char    x = '0';
    do
    {       x = getchar ( );     }
    while ( x != '\n' );
}
int    readint    ( char *text )
{
    int     x = 0;
    printf  ( "%s" , text );
    scanf   ( "%d" , &x   );   flush ( );
    return  ( x );
}
double readdouble ( char *text )
{
    double  x = 0.0;
    printf  ( "%s" , text );
    scanf   ( "%lf", &x   );   flush ( );
    return  ( x );
}
bool   readbool   ( char *text )
{
    int     x = 0;
    printf  ( "%s" , text );
    scanf   ( "%d" , &x   );   flush ( );
    return  ( x != 0 );
}
char   readchar   ( char *text )
{
    char    x = '0';
    char    y = '0';
    printf  ( "%s" , text );
    scanf   ( "%c" , &x   );   
    do
    {       y = getchar ( );      }
    while ( y != '\n' );
    return  ( x );
}
char* readstring  ( char *text )
{
    char *buffer = calloc ( STR_SIZE, sizeof(char) );
    printf ( "%s" , text );
    scanf  ( "%s" , buffer );   
    buffer [ STR_SIZE-1 ] = '\0';
    flush  ( );
    return ( buffer );
}
char* readln      ( char *text )
{
    char *buffer = calloc ( STR_SIZE, sizeof(char) );
    int x = STR_SIZE-1;
    printf ( "%s" , text );
    fgets  ( buffer, x, stdin ); 
    buffer [ x ] = '\0';
    while  ( x >= 0 && buffer[x] != '\n' )
    {    x = x - 1;    }
    if ( x >= 0 && buffer [x] == '\n' )
    {    buffer [ x ] = '\0';    }
    return ( buffer );
}