#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <string>
#include <vector>
#include "mensagem.h"
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
		vector<Canal*> canais;
		vector<int> participantesIds; // (lista de IDs de usuários que já estão no servidor)
        public: 
		Servidor();
		~Servidor();     
		Servidor (int usuarioDonoId_, string nome_); // construtor para criar um servidor sem descrição e codigo convite
        	//getters
                int getUsuarioDonoId()const;
                string getNome() const;
                string getNomeCanais(int j) const;
                int getTipo_canal(int j) const;
                string getDescricao() const;
                string getCodigoConvite() const;
                long unsigned int getSize() const; // retorna tamanho do vetor participantesIds
                long unsigned int getSizeCanais(); // retorna tamanho do vetor canais
                int getId(int i) const;
                string getTexto() const; //percorre o vetor canais e imprime os canais de voz (Tipo_canal = 2)
                string getVoz() const; //percorre o vetor canais e imprime os canais de texto (Tipo_canal = 1)
                string getMensagens(int j) const; //imprime as mensagens do canal na posição j
                //setters
                void setNome(string const nome_);
                void setDescricao(string const descricao_);
                void setCodigoConvite(string const codigoConvite_);

                void pushId(int Id);
                void pushCanal(Canal* canaldata);
                //bool criaCanal( shared_ptr <Canal> const canal);
                bool isUsuarioLogado(int id);
                void removeId(int i); 
                bool ComparaNomeCanais(string nome) const; 
                void inserirUltimaMensagem(int j, Mensagem msg) const;
                bool isMensagemVazia(int j);
                
};

#endif