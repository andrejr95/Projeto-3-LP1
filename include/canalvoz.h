#ifndef CANALVOZ_H
#define CANALVOZ_H
#include <iostream>
#include <string>
#include "mensagem.h"
#include "canal.h"   

using namespace std;

class CanalVoz : public Canal{
	private:
		Mensagem ultimaMensagem;

};

#endif