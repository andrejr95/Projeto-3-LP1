#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>
#include <string>
using namespace std;

class Mensagem {
	private:
    	string dataHora;
    	int enviadaPor;
    	string conteudo;

  	public:
  		Mensagem(); // construtor padrão
    	Mensagem (string dataHora_, int enviadaPor_, string conteudo_);
    	~Mensagem(); // destrutor
    	//getters
        string getDataHora()const;
        int getEnviadaPor()const;
        string getConteudo()const;
        //setters
        void setDataHora(string const dataHora_);       
        void setEnviadaPor(int const enviadaPor_);
        void setConteudo(string const conteudo_);
              
};

#endif