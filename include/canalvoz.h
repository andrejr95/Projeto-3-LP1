#ifndef CANALVOZ_H
#define CANALVOZ_H
#include <iostream>
#include <string>
#include <vector>
#include "mensagem.h"
#include "canal.h"   

using namespace std;

class CanalVoz : public Canal{
	private:
		Mensagem ultimaMensagem;

	public:
        CanalVoz();
        CanalVoz(string  nome_ , int  tipo_canal_ );
        ~CanalVoz();
        
        virtual void inserirUltimaMensagem(Mensagem msg);
        virtual vector <Mensagem> getMensagens();
};


#endif