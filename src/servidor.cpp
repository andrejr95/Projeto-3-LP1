#include <string>
#include "servidor.h"  

using namespace std;


Servidor::Servidor(){}
Servidor::~Servidor(){}

Servidor::Servidor(int usuarioDonoId_, string nome_){
    usuarioDonoId = usuarioDonoId_;
    nome = nome_;
}

//getters
int Servidor::getUsuarioDonoId(){
    return usuarioDonoId;
}

string Servidor::getNome() const{
    return nome;
}

string Servidor::getDescricao() const{
    return descricao;
}

string Servidor::getCodigoConvite() const{
    return codigoConvite;
}


//setters
void Servidor::setNome(string const nome_){
    nome = nome_;
}
void Servidor::setDescricao(string const descricao_){
    descricao = descricao_;
}

void Servidor::setCodigoConvite(string const codigoConvite_){
    codigoConvite = codigoConvite_;
}

void Servidor::pushId(int Id){ 
	this->participantesIds.push_back(Id);
}

void Servidor::pushCanal(Canal canaldata){ 
	this->canais.push_back(canaldata);
}

bool Servidor::isUsuarioLogado(int id){
  for(size_t j = 0; j < participantesIds.size(); j++)
    if(participantesIds[j] == id){
      return true;
    }
  return false;
}

long unsigned int Servidor::getSize() const{
	return participantesIds.size();
}

int Servidor::getId(int i) const{
	int aux = 0;
	aux = participantesIds[i];
	return aux;
}

void Servidor::removeId(int j) {
	
	participantesIds.erase(participantesIds.begin() + j);
}

