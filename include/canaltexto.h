#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <iostream>
#include <string>
#include <vector>
#include "mensagem.h"
#include "canal.h"   

using namespace std;

class CanalTexto : public Canal{
	private:
		vector <Mensagem> mensagens;

	public:
        CanalTexto();
        CanalTexto(string nome_ , int  tipo_canal_ );
        ~CanalTexto();
        virtual void inserirUltimaMensagem(Mensagem msg);
        virtual void getMensagens();
        virtual bool isMensagemVazia();

};

#endif