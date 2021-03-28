#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <string>
#include <vector>
#include "canal.h"
#include "canaltexto.h"
#include "canalvoz.h"

using namespace std;

class Servidor {
	private:
		int usuarioDonoId;
		string nome;
		string descricao;
		string codigoConvite;
		vector<Canal> canais;
		vector<int> participantesIds; // (lista de IDs de usuários que já estão no servidor)
	public: 
		Servidor();
		~Servidor();     
		Servidor (int usuarioDonoId_, string nome_); // construtor para criar um servidor sem descrição e codigo convite
		//getters
        int getUsuarioDonoId();
        string getNome() const;
        string getDescricao() const;
        string getCodigoConvite() const;
        long unsigned int getSize() const;
        int getId(int i) const;
        //setters
        void setNome(string const nome_);
        void setDescricao(string const descricao_);
        void setCodigoConvite(string const codigoConvite_);

        void pushId(int Id);
        void pushCanal(Canal canaldata);
        bool isUsuarioLogado(int id);
        void removeId(int i);      
};

#endif