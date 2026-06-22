#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#ifndef __IO_REFS__
#define __IO_REFS__

#define null NULL

#define addr(p) (&(p))
#define deref(p) (*(p))
#define val(p) (*(p))

#define ref *

#define var &

#endif

#ifndef _IO_HPP_
#define _IO_HPP_

#define IO_printf printf
#define IO_scanf scanf
#define IO_fprintf fprintf
#define IO_fscanf fscanf

#define AND &&
#define OR ||
#define NOT !
#define XOR ^

const bool FALSE = false;
const bool TRUE = true ;

const char EOS = '\0';
const char EOL = '\n';
const char ENDL [] = "\n";
const char STR_EMPTY [] = "" ;
const int STR_SIZE = 80 ;

bool IO_rand_reset = false;

typedef char* chars ;
typedef int* ints ;
typedef double* doubles;
typedef bool* bools ;

typedef unsigned char byte;
typedef unsigned char* bits;

int IO_error = 0;
bool IO_trace = true;

void IO_debugOFF ( )
{
  IO_trace = false;
}

void IO_debugON ( )
{
  IO_trace = true;
}

void IO_debug ( bool condition, const char *text )
{
  if ( IO_trace && condition )
  {
     printf ( "\nDBG> %s\n", text );
     getchar( );
  }
}

void IO_clrscr ( void )
{
#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    system ( "cls" );
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

void IO_flush ( void )
{

    char x = '0';
    do { x = getchar( ); } while ( '\n' != x );

}

std::string IO_version ( void )
{
    std::string x = "v.2026-1";
    return ( x );
}

void IO_id ( std::string text )
{
    std::cout << text << std::endl;
    std::cout << "Autor: Arthur Victor Alves";
    std::cout << std::endl;
}

bool IO_readbool ( std::string text )
{
    int x = 0;
    std::cout << text;
    std::cin >> std::skipws >> x;
    std::cin.clear ( );
    return ( x!=0 );
}

char IO_readchar ( std::string text )
{
    char x = '0';
    std::cout << text;
    do
    {

      std::cin.get ( x );
      std::cin.clear ( );
    }
    while ( x == '\n' );
    return ( x );
}

double IO_readdouble ( std::string text )
{
    double x = 0.0;
    std::cout << text;
    std::cin >> std::skipws >> x;
    std::cin.clear ( );
    return ( x );
}

float IO_readfloat ( std::string text )
{
    float x = 0.0;
    std::cout << text;
    std::cin >> std::skipws >> x;
    std::cin.clear ( );
    return ( x );
}

void IO_pause ( void )
{
    char x = '0';
    do
    {

      x = std::cin.get( );
      std::cin.clear( );
    }
    while ( x != '\n' );
}

void IO_pause ( std::string text )
{
    std::cout << std::endl << text << std::endl;
    IO_pause ( );
}

chars IO_new_chars ( int size )
{
    return ( (chars) malloc ( (size+1)*sizeof(char) ) );
}

ints IO_new_ints ( int size )
{
    return ( (ints) malloc ( (size)*sizeof(int) ) );
}

doubles IO_new_doubles ( int size )
{
    return ( (doubles) malloc ( (size)*sizeof(double) ) );
}

bools IO_new_bools ( int size )
{
    return ( (bools) malloc ( (size)*sizeof(bool) ) );
}

std::string IO_concat ( std::string text1, std::string text2 )
{
  std::string buffer = text1+text2;
  return ( buffer );
}

std::string IO_toString ( bool x )
{
  std::ostringstream buffer;
  buffer << x;
  return ( buffer.str ( ) );
}

std::string IO_toString ( char x )
{
  std::ostringstream buffer;
  buffer << x;
  return ( buffer.str ( ) );
}

std::string IO_toString ( int x )
{
  std::ostringstream buffer;
  buffer << x;
  return ( buffer.str ( ) );
}

std::string IO_toString ( double x )
{
  std::ostringstream buffer;
  buffer << x;
  return ( buffer.str ( ) );
}

std::string IO_toString ( std::string x )
{
  std::ostringstream buffer;
  buffer << x;
  return ( buffer.str ( ) );
}

void IO_print ( std::string text1 )
{
  std::cout << text1;
}

void IO_println ( std::string text1 )
{
  std::cout << text1 << std::endl;
}

void IO_fprint ( FILE* filePtr, std::string text1 )
{
  fprintf ( filePtr, "%s", text1.c_str( ) );
}

void IO_fprintln ( FILE* filePtr, std::string text1 )
{
  fprintf ( filePtr, "%s\n", text1.c_str( ) );
}

chars IO_fread ( FILE* filePtr )
{
  chars buffer = IO_new_chars ( STR_SIZE+1 );

  fscanf ( filePtr, "%s", buffer );
  return ( buffer );
}

std::string IO_freadln ( std::ifstream& filePtr )
{
  std::string buffer;

  std::getline ( filePtr, buffer);
  return ( buffer );
}

char* IO_readstring ( std::string text )
{
  std::string buffer;
  char* tmp = (char*) calloc ( 80+1, sizeof(char) );

  std::cout << text ;
  std::cin >> buffer;
  IO_flush ( ) ;

  strcpy ( tmp, buffer.c_str( ) );
  return ( &(tmp[0]) );
}

char* IO_readln ( std::string text )
{
  std::string buffer;
  char* tmp = (char*) calloc ( 80+1, sizeof(char) );

  std::cout << text ;
  std::getline ( std::cin, buffer, '\n' );

  strcpy ( tmp, buffer.c_str( ) );
  return ( &(tmp[0]) );
}

chars IO_boolalpha ( bool value )
{
  static char tmp [80];

  std::ostringstream buffer;
  buffer << std::boolalpha << value;
  strcpy ( tmp, (buffer.str( )).c_str( ) );
  return ( &(tmp[0]) );
}

bool IO_check ( void *p1, void *p2, int size )
{
  return ( p1 && p2 && (0==memcmp( p1, p2, size )) );
}

std::string IO_next ( std::string text )
{
  std::string buffer;

  std::cout << text ;
  IO_flush ( );
  std::cin >> buffer;

  return ( buffer );
}

std::string IO_nextLine ( std::string text )
{
  std::string buffer;

  std::cout << text ;

  do
  { std::getline ( std::cin, buffer, '\n' ); }
  while ( buffer.length( )==0 );
  return ( buffer );
}

int IO_length ( char* text )
{
    int x = 0;
    if ( text )
    { x = strlen(text); }
    return ( x );
}

char IO_charAt ( char* text, unsigned int index )
{
    char x = '\0';
    if ( text && 0 <= index && index < strlen(text) )
    { x = text [ index ]; }
    return ( x );
}

char* IO_substring ( char *text, int start, int size )
{
    chars buffer = NULL;
    if ( start >= 0 && size > 0 && (start+size) < (int) strlen(text) )
    {
       buffer = IO_new_chars ( size+1 );
       memcpy ( buffer, text+start, size );
       buffer [size] = '\0';
    }
    return ( buffer );
}

int IO_random( int min, int max )
{
    int resultado = 0;
    int random = 0;
    if(!IO_rand_reset){
        srand(time(NULL));
        IO_rand_reset = true;
    }
    if(min < max){
        random = rand();
        resultado = min + (random % (max - min + 1));
    } else {
        return 0;
    }
    return resultado;
}

void IO_readIntervalo(int *a,int *b){
    int v1 = 0;
    int v2 = 0;

    do{
        std::cout << "Digite o valor do primero Intervalo: ";
        std::cin >> v1;
        if(std::cin.fail())
        {
            std::cout << "Valor invalido\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(std::cin.fail());

    do{
        std::cout << "Digite o valor do segundo Intervalo: ";
        std::cin >> v2;
        if(std::cin.fail())
        {
            std::cout << "Valor invalido\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(std::cin.fail());

    *a = v1;
    *b = v2;
}

void IO_readMatriz(int *a,int *b){
    int v1 = 0;
    int v2 = 0;

    do{
        std::cout << "Digite a quantidade de linhas: ";
        std::cin >> v1;
        if(std::cin.fail())
        {
            std::cout << "Valor invalido\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(std::cin.fail());

    do{
        std::cout << "Digite a quantidade de colunas: ";
        std::cin >> v2;
        if(std::cin.fail())
        {
            std::cout << "Valor invalido\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(std::cin.fail());

    *a = v1;
    *b = v2;
}

int IO_readint(std::string text){
    int retorno = 0;

    do{
        std::cout << text;
        std::cin >> retorno;
        if(std::cin.fail())
        {
            std::cout << "Valor invalido!\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(std::cin.fail());

    return retorno;
}

int intModule(int x){
    return (x < 0 ? -x : x);
}

#endif
