#ifndef CANAL_H
#define CANAL_H
#include <iostream>
#include <string>
using namespace std;

class Canal {
  protected:
    string nome;
    int tipo_canal; // recebera valor 1 para canais de texto e valor 2 para canais de voz
  public:
    Canal(); // construtor padrão
    Canal (string nome_, int tipo_canal_); 
    virtual ~Canal(); // destrutor
    //getters
    virtual string getNomeCanal()const;
    virtual int getTipo_canal()const;       
    //setters
    virtual void setNome(string const nome_);
    virtual void setTipo_canal(int const tipo_canal_);


};

#endif