#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

class Erro
{
private:
    int erro;

public:
    static const std::string NO_ERROR;

    Erro ( ) : erro(0) { }

    ~Erro ( ) { }

    int getErro ( )
    {
        return ( erro );
    }

    bool hasError ( )
    {
        return ( erro != 0 );
    }

    virtual std::string getErroMsg ( )
    {
        return ( NO_ERROR );
    }

protected:
    void setErro ( int codigo )
    {
        erro = codigo;
    }

};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif
