#include <string>
#include "canal.h"
#include "mensagem.h"
#include "canaltexto.h"

using namespace std; 

CanalTexto::CanalTexto(){} // construtor padrão

CanalTexto::~CanalTexto(){ // destrutor
	
} 

CanalTexto::CanalTexto(string nome_ , int  tipo_canal_ ) : Canal(nome_, tipo_canal_){};


void CanalTexto::pushMensagens(Mensagem msg){ 
	this->mensagens.push_back(msg);
}

vector<Mensagem> CanalTexto::getMensagens(){
	return this->mensagens;s
}