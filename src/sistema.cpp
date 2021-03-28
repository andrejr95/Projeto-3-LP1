#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "sistema.h"
#include "servidor.h"
#include "usuario.h"  

using namespace std;

int contadorId_Usuario = 1;

Sistema::Sistema(){
    usuarioLogadoId = 0;   // id de usuario para salvar quem está conectado - 0 para ninguem 
    nomeServidorConectado = ""; // salvar qual servidor está conectado - vazio para nenhum
    nomeCanalConectado = ""; // salvar qual canal está conectado - vazio para nenhum
}

Sistema::~Sistema(){}


/* COMANDOS */
string Sistema::quit() {
  return "Saindo do Concordo";
}

string Sistema::create_user (const string email, const string senha, const string nome) {

  cout << "Tentando criar o usuário: " << nome << " Com email: " << email << endl;
  for(size_t i = 0; i < usuarios_root.size(); i++){ 

    if(usuarios_root[i].getEmail() == email){ // Verifica se o email já está cadastrado
        return "Usuário já cadastrado, favor usar outro email";
    }
  }

  // Insere o usuario no vector
  Usuario aux_usuario(contadorId_Usuario, email, senha, nome);
  usuarios_root.push_back(aux_usuario);
  contadorId_Usuario++;

  return "Usuário criado com sucesso";
}


string Sistema::login(const string email, const string senha) {

  for(size_t i = 0; i < usuarios_root.size(); i++){

    if(usuarios_root[i].getEmail() == email){

        if(usuarios_root[i].getSenha() == senha){ // Verifica se a senha para aquele email está correta

            usuarioLogadoId = usuarios_root[i].getId(); // Se p email e a senha forem corretos pega o Id do usuario logado e salva na variavel
            cout << "“Logado como: " << usuarios_root[i].getEmail() << " de Id: " << usuarioLogadoId;
            return " !";
        }
    }
  }

  return "Usuário ou Senha não cadastrados";
}


string Sistema::disconnect() {
  // Verifica se algum usuario está logado
  if(usuarioLogadoId != 0){ 
    cout << "Desconectando o usuário de email: " << usuarios_root[usuarioLogadoId - 1].getEmail()<<endl;
    // usuarioLogadoId volta ao valor 0 para indicar que não há usuarios conectados
    usuarioLogadoId = 0;
    return "Desconectando com sucesso "; 
  }

  return "Não há nenhum usuário conectado";
}

string Sistema::create_server(const string nome) {

  if(usuarioLogadoId != 0){ 

    for(size_t i = 0; i < servidores_root.size(); i++){  //percorre o vetor de servudires
      // Verifica se o servidor já foi cadastrado
      if(servidores_root[i].getNome() == nome){ 
          return "Esse servidor já existe, favor escolher outro nome";
      }            
    }

    Servidor aux_servidor(usuarioLogadoId, nome);
    aux_servidor.pushId(usuarioLogadoId);
    servidores_root.push_back(aux_servidor);
    cout << "Servidor de nome: " << nome;
    return " criado com sucesso";
}

  return "Não há usuário conectado, favor realizar login para poder criar um servidor";
}


string Sistema::set_server_desc(const string nome, const string descricao) {

  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      if(servidores_root[i].getNome() == nome){
        if(servidores_root[i].getUsuarioDonoId() == usuarioLogadoId){  // verifica se o Id de quem criou o servidor é igual ao do usuário logado

          servidores_root[i].setDescricao(descricao);
          cout << "Descrição do servidor: " << servidores_root[i].getNome() << " modificada para: " << servidores_root[i].getDescricao();
          return "";
        }
        else{
          return "Você não pode alterar a descrição de um servidorque não foicriado por você";
        }    
      }            
    }

    return "Servidor: " + nome + " não existe";
  }
  
  return "Não há usuário conectado, favor realizar login para poder mudar a descrição de um servidor";
}

string Sistema::set_server_invite_code(const string nome, const string codigo) {

  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      if(servidores_root[i].getNome() == nome){
        if(servidores_root[i].getUsuarioDonoId() == usuarioLogadoId){

          servidores_root[i].setCodigoConvite(codigo);
          if(codigo == ""){
            return "Codigo de convite do servidor removido";
          }
          cout << "Codigo de convite do servidor: " << servidores_root[i].getNome() << " foi modificado para: " << servidores_root[i].getCodigoConvite();
          return "";
        }
        else{
          return "Você não pode alterar a descrição de um servidor que não foi criado por você";
        }    
      }            
    }

    return "Nome do servidor não encontrado";
  }
  
  return "Não há usuário conectado, favor realizar login para poder mudar o codigo de convite de um servidor";
}

string Sistema::list_servers(){

  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      cout << servidores_root[i].getNome() << endl;
    }
  }
  return "";
}

string Sistema::remove_server(const string nome) {

  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      if(servidores_root[i].getNome() == nome){
        if(servidores_root[i].getUsuarioDonoId() == usuarioLogadoId){

          servidores_root.erase(servidores_root.begin() + i);
          return " Servidor: " + nome + " foi removido com sucesso";
        }
        else{
          return "Id do usuario não compativel com o dono do servidor";
        }    
      }            
    }

    return "Nome do servidor não encontrado";
  }
  
  return "Não há usuário conectado, favor realizar login para poder remover um servidor";
}



string Sistema::enter_server(const string nome, const string codigo) {

  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      if(servidores_root[i].getNome() == nome){
        if(servidores_root[i].getCodigoConvite() == codigo){

          nomeServidorConectado = servidores_root[i].getNome();
          if(servidores_root[i].isUsuarioLogado(usuarioLogadoId)==true){
            return "Usuario já está no servidor - Servidor conectado";
          }
            servidores_root[i].pushId(usuarioLogadoId);
            return "Entrou no servidor com sucesso";
        }
        else{
          return "Servidor requer código de convite ou código de convite inválidos ";

        }    
      }            
    }

    return "Nome do servidor não encontrado";
  }
  
  return "Não há usuário conectado, favor realizar login para poder remover um servidor";

}

string Sistema::leave_server() {

  if(usuarioLogadoId != 0){
    if(nomeServidorConectado != ""){ 
      cout <<"Saindo do servidor: " << nomeServidorConectado;
      for(size_t i = 0; i < servidores_root.size(); i++){
        if(servidores_root[i].getNome() == nomeServidorConectado){
          for(size_t j = 0; j < servidores_root[i].getSize(); j++){
            if(servidores_root[i].getId(j) == usuarioLogadoId){
              servidores_root[i].removeId(j);
            }           
          }
        }  
      }
      nomeServidorConectado ="";
      return "";
    }
    else{
      return "Não há servidor conectado";
    }
  }
  
  return "Não há usuário conectado, favor realizar login para poder remover um servidor";
}

string Sistema::list_participants() {

  if(usuarioLogadoId != 0){
    if(nomeServidorConectado != ""){
      for(size_t i = 0; i < servidores_root.size(); i++){
        if(servidores_root[i].getNome() == nomeServidorConectado){
          for(size_t j = 0; j < servidores_root[i].getSize(); j++){
            int auxiliar =0;
            auxiliar = servidores_root[i].getId(j);
              for(size_t ji = 0; ji < usuarios_root.size(); ji++){
                if(usuarios_root[ji].getId() == auxiliar){
                  cout << usuarios_root[ji].getNome() << endl;
                }
              }
              
          }
        }  
      }
      return "lista de participantes impressa";
    }
    else{
      return "Não há servidor conectado";
    }
  }
  return "Não há usuário conectado, favor realizar login para poder remover um servidor";
}


string Sistema::list_channels() {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(const string nome, const string tipo) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel() {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
  return "list_messages NÃO IMPLEMENTADO";
}


