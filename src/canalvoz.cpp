#include <string>
#include <vector>
#include "canal.h"
#include "mensagem.h"
#include "canalvoz.h"

using namespace std; 

CanalVoz::CanalVoz(){} // construtor padrão

CanalVoz::~CanalVoz(){ // destrutor
	
} 

CanalVoz::CanalVoz(string nome_ , int  tipo_canal_ ) : Canal(nome_, tipo_canal_){

}


void CanalVoz::inserirUltimaMensagem(Mensagem msg){ 
	ultimaMensagem.setDataHora(msg.getDataHora());
	ultimaMensagem.setEnviadaPor(msg.getEnviadaPor());
	ultimaMensagem.setConteudo(msg.getConteudo());
}

vector<Mensagem> CanalVoz::getMensagens(){
	vector <Mensagem> aux;
	aux.push_back(ultimaMensagem);
	cout << ultimaMensagem.getEnviadaPor() << " - " << ultimaMensagem.getDataHora() << " - " << ultimaMensagem.getConteudo()<< endl;
	return aux;
}
