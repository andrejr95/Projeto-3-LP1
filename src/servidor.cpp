#include <string>
#include "servidor.h"
#include "mensagem.h"
#include "canal.h" 
#include "canaltexto.h" 

using namespace std;


Servidor::Servidor(){}
Servidor::~Servidor(){
   for(size_t j = 0; j < canais.size(); j++){
    delete canais[j];
   }    
}

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

string Servidor::getNomeCanais(int j) const{
    return canais[j]->getNomeCanal();
}

int Servidor::getTipo_canal(int j) const{
    return canais[j]->getTipo_canal();
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

void Servidor::pushCanal(Canal* canaldata){
  if(canaldata != nullptr){ 
	 canais.push_back(canaldata);
  }
}


bool Servidor::isUsuarioLogado(int id){
  for(size_t j = 0; j < participantesIds.size(); j++){
    if(participantesIds[j] == id){
      return true;
    }
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

long unsigned int Servidor::getSizeCanais() {  // retorna tamanho do vetor canais
  return canais.size();
}

string Servidor::getTexto() const{      //percorre o vetor canais e imprime os canais de texto (Tipo_canal = 1)

  for(size_t j = 0; j < canais.size(); j++){
    if(canais[j]->getTipo_canal() == 1){
    cout << canais[j]->getNomeCanal()<< endl;
    }
  }  
return "#Fim dos canais de texto!";
}


string Servidor::getVoz() const{       //percorre o vetor canais e imprime os canais de voz (Tipo_canal = 2)

  for(size_t j = 0; j < canais.size(); j++){
    if(canais[j]->getTipo_canal() == 2){
    cout << canais[j]->getNomeCanal()<< endl;
    }
  }  
return "#Fim dos canais de voz!";
}

bool Servidor::ComparaNomeCanais(string nome) const{      //percorre o vetor canais e imprime os canais de texto (Tipo_canal = 1)

  for(size_t j = 0; j < canais.size(); j++){
    if(canais[j]->getNomeCanal() == nome){
    return true;
    }
  }  
return false;

}

void Servidor::inserirUltimaMensagem(int j, Mensagem msg) const{
    canais[j]->inserirUltimaMensagem(msg);
}

string Servidor::getMensagens(int j) const{       //percorre o vetor canais e imprime os canais de voz (Tipo_canal = 2)

  canais[j]->getMensagens();
  
  return "#Fim das mensagens!";
}

