#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>

using namespace std;

class Usuario {
	private:
		int id;
		string nome;
		string email;
		string senha;
	public:
		Usuario(); // construtor padrão
		Usuario (int id_, string email_ , string senha_ , string nome_);
		~Usuario(); // destrutor
		//getters
		int getId ()const; // não necessario o set já que o ID deve ser atribuido automaticamente
		string getNome()const;
		string getEmail()const;
		string getSenha()const;
		//setters
        void setNome(string const nome_);
        void setEmail(string const email_);
        void setSenha(string const senha_);
              
};

#endif