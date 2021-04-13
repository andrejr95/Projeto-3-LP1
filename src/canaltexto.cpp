#include <string>
#include <vector>
#include "canal.h"
#include "mensagem.h"
#include "canaltexto.h"

using namespace std; 

CanalTexto::CanalTexto(){} // construtor padrão

CanalTexto::~CanalTexto(){ // destrutor
	
} 

CanalTexto::CanalTexto(string nome_ , int  tipo_canal_ ) : Canal(nome_, tipo_canal_){

}


void CanalTexto::inserirUltimaMensagem(Mensagem msg){ 
	mensagens.push_back(msg);
}

vector<Mensagem> CanalTexto::getMensagens(){
	for(size_t j = 0; j < mensagens.size(); j++){
  	cout << mensagens[j].getEnviadaPor() << " - " << mensagens[j].getDataHora() << " - " << mensagens[j].getConteudo()<< endl; 
  	} 
	return mensagens;
}

/*
string Servidor::getVoz() const{       //percorre o vetor canais e imprime os canais de voz (Tipo_canal = 2)

  for(size_t j = 0; j < mensagens.size(); j++){
  	cout << mensagens[j].getEnviadaPor() << " - " << mensagens[j].getDataHora() << " - " << mensagens[j].getConteudo()<< endl; 
    
  }  
return "#Fim das mensagens de texto!";
}*/