#include <string>
#include "mensagem.h" 

using namespace std;

Mensagem::Mensagem(){} 

Mensagem::~Mensagem(){} 


Mensagem::Mensagem (string dataHora_, int enviadaPor_, string conteudo_){ 
    dataHora = dataHora_;
    enviadaPor = enviadaPor_;
    conteudo = conteudo_;
}

//getters
string Mensagem::getDataHora()const{
    return dataHora;
}

string Mensagem::getConteudo() const{
    return conteudo;
}

int Mensagem::getEnviadaPor() const{
    return enviadaPor;
}
//setters
void Mensagem::setDataHora(string const dataHora_){
    dataHora = dataHora_;
}

void Mensagem::setConteudo(string const conteudo_){
    conteudo = conteudo_;
}

void Mensagem::setEnviadaPor(int const enviadaPor_){
    enviadaPor = enviadaPor_;
}


