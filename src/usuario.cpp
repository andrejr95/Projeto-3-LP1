#include <string>
#include "usuario.h"  

using namespace std;

Usuario::Usuario(){}
Usuario::~Usuario(){}


Usuario::Usuario(int id_,string email_,string senha_,string nome_){ 
    id = id_;
    email = email_;
    senha = senha_;
    nome = nome_;   
}

//getters
int Usuario::getId()const {
    return id;
}

string Usuario::getNome()const {
    return nome;
}

string Usuario::getEmail()const {
    return email;
}

string Usuario::getSenha()const {
    return senha;
}
//setters
void Usuario::setNome(string const nome_){
    nome = nome_;
}

void Usuario::setEmail(string const email_){
    email = email_;
}

void Usuario::setSenha(string const senha_){
    senha = senha_;
}
