#ifndef CANAL_H
#define CANAL_H
#include <iostream>
#include <string>
using namespace std;

class Canal {
  protected:
    string nome;

  public:
    Canal(); // construtor padrão
    Canal (string nome_); 
    ~Canal(); // destrutor
    //getters
    string getNome()const;     
    //setters
    void setNome(string nome_);

};

#endif