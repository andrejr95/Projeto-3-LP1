#include <string>
#include "canal.h"
#include "mensagem.h"

using namespace std; 

Canal::Canal(){} // construtor padrão

Canal::~Canal(){} // destrutor

Canal::Canal (string nome_) : nome(nome_) {}


void Canal::setNome(string nome_){
    nome = nome_;
}


string Canal::getNome()const{
    return nome;
}