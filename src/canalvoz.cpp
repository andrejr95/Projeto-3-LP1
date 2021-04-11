#include <string>
#include "canal.h"
#include "mensagem.h"
#include "canaltexto.h"

using namespace std; 

CanalVoz::CanalVoz(){} // construtor padrão

CanalVoz::~CanalVoz(){ // destrutor
	
} 

CanalVoz::CanalVoz(string nome_ , int  tipo_canal_ ) : Canal(nome_, tipo_canal_){};


void CanalVoz::inserirUltimaMensagem(string dataHora, int enviadaPor, string conteudo){ 
	ultimaMensagem.setDataHora(dataHora);
	ultimaMensagem.setEnviadaPor(enviadaPor);
	ultimaMensagem.setConteudo(conteudo);
}

