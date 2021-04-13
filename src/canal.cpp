#include <string>
#include <vector>
#include "canal.h"
#include "mensagem.h"

using namespace std; 

Canal::Canal(){} // construtor padrão

Canal::~Canal(){ // destrutor
	
} 

Canal::Canal (string const nome_ , int const tipo_canal_ ){
    nome = nome_;
    tipo_canal = tipo_canal_;
}


void Canal::setNome(string nome_){
    nome = nome_;
}


string Canal::getNomeCanal()const{
    return nome;
}

void Canal::setTipo_canal(int tipo_canal_){
    tipo_canal = tipo_canal_;
}


int Canal::getTipo_canal()const{
    return tipo_canal;
}



