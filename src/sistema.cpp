#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <fstream>
#include "sistema.h"
#include "servidor.h"
#include "usuario.h"
#include "canal.h"
#include "canaltexto.h"
#include "canalvoz.h"
#include "mensagem.h"



using namespace std;

int contadorId_Usuario = 1; // variavel para declarar o ID do usuario a ser criado
char dataHora[40];  // variavel para salvar a data e hora das mensagens enviadas


Sistema::Sistema(){
    usuarioLogadoId = 0;   // id de usuario para salvar quem está conectado - 0 para ninguem 
    nomeServidorConectado = ""; // salvar qual servidor está conectado - vazio para nenhum
    nomeCanalConectado = ""; // salvar qual canal está conectado - vazio para nenhum
}

Sistema::~Sistema(){}



// salva os dados do sistema(root) no txt
void Sistema::salvar() const{
    salvarUsuarios();   // Salva usuários
    salvarServidores(); // Salva servidores
}

// carrega os dados do txt para o sistema(root)
void Sistema::carregar() {
    carregarUsuarios();   // Salva usuários
    carregarServidores(); // Salva servidores
}

// Salva os dados dos usuários no arquivo txt 
void Sistema::carregarUsuarios() {

  // Abre o arquivo txt para salvar os usuarios
  ifstream txt_usuarios("usuarios.txt");

  // Verifica se o arquivo txt abriu com sucesso
  if(txt_usuarios) {

    // Verifica se o arquivo não está vazio
    if(txt_usuarios.peek() != std::ifstream::traits_type::eof()){
      usuarios_root.clear(); // apaga os usuarios para evitar repetição
      string size, id, nome, email, senha;
      getline(txt_usuarios, size);

      // Percorre o vetor de usuarios e salva os dados deles no arquivo txt
      for(int i = 0; i < stoi(size); ++i) {
        getline(txt_usuarios, id);
        getline(txt_usuarios, nome);
        getline(txt_usuarios, email);
        getline(txt_usuarios, senha);

        Usuario aux_usuario(stoi(size), email, senha, nome);
        usuarios_root.push_back(aux_usuario);    
      }
    }

  }else
      cout << "Não foi possivel carregar os usuarios do arquivo txt " << endl;
  
txt_usuarios.close();
}

void Sistema::carregarServidores() {

  std::ifstream txt_servidores("servidores.txt");
  // codigo funcionando mas não aplicado por enquanto para evitar apagar outros dados
/*
  if(txt_servidores){

    // Verifica se o arquivo não está vazio
    if(txt_servidores.peek() != std::ifstream::traits_type::eof()){
      // Apaga todos os servidores para evitar repetição - apaga outros dados do servidor que não foram programados para serem salvos.
      servidores_root.clear(); 

      string size, donoID, nome, descricao, codigo;
      
      getline(txt_servidores, size);

      // Faz a leitura dos dados de cada servidor
      for(int i = 0; i < stoi(size); ++i) {
        getline(txt_servidores, donoID);
        getline(txt_servidores, nome);
        getline(txt_servidores, descricao);
        getline(txt_servidores, codigo);
        
        // Cria e cadastra o novo servidor no sistema
        Servidor aux_servidor(stoi(donoID), nome);
        aux_servidor.setDescricao(descricao);
        aux_servidor.setCodigoConvite(codigo);
        servidores_root.push_back(aux_servidor);
      }
    }    
  }
  else
      cout << "Não foi possivel carregar os servidores do arquivo txt " << endl;  */
  
txt_servidores.close();
}


// Salva os dados dos usuários no arquivo txt 
void Sistema::salvarUsuarios() const{

  // Abre o arquivo txt para salvar os usuarios
  ofstream txt_usuarios("usuarios.txt");

  // Verifica se o arquivo txt abriu com sucesso
  if(txt_usuarios) {

      txt_usuarios << usuarios_root.size() << endl; // grava o numero de usuarios na primeira linha do arquivo txts

      // Percorre o vetor de usuarios e salva os dados deles no arquivo txt
      for(size_t i = 0; i < usuarios_root.size(); i++) {
        txt_usuarios << usuarios_root[i].getId() << endl;
        txt_usuarios << usuarios_root[i].getNome() << endl;
        txt_usuarios << usuarios_root[i].getEmail() << endl;
        txt_usuarios << usuarios_root[i].getSenha() << endl;
      }

  }else
      cout << "Não foi possivel salvar os usuarios no arquivo txt " << endl;
  
txt_usuarios.close();
}

// Salva os dados dos servidores cadastrados no txt
void Sistema::salvarServidores() const{

  // Abre o arquivo txt para salvar os servidores
  ofstream txt_servidores("servidores.txt");

  // Verifica se o arquivo txt abriu com sucesso
  if(txt_servidores){

    // grava o numero de usuarios na primeira linha do arquivo txts
    txt_servidores << servidores_root.size() << endl;

    // Percorre o vetor de servidores e salva os dados deles no arquivo txt
    for(size_t i = 0; i < servidores_root.size(); i++) {

      txt_servidores << servidores_root[i].getUsuarioDonoId() << endl;
      txt_servidores << servidores_root[i].getNome() << endl;
      txt_servidores << servidores_root[i].getDescricao() << endl;
      txt_servidores << servidores_root[i].getCodigoConvite() << endl;      
    }
  }

  else
      cout << "Não foi possivel salvar os servidores no arquivo txt" << endl;

  txt_servidores.close();
}


/* COMANDOS */
string Sistema::quit() {
  carregar();
  salvar();
  return "Saindo do Concordo";
}

string Sistema::create_user (const string email, const string senha, const string nome) {

  carregar();
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

  salvar();
  return "Usuário criado com sucesso";
}


string Sistema::login(const string email, const string senha) {

  carregar();
  for(size_t i = 0; i < usuarios_root.size(); i++){

    if(usuarios_root[i].getEmail() == email){

        if(usuarios_root[i].getSenha() == senha){ // Verifica se a senha para aquele email está correta

            usuarioLogadoId = usuarios_root[i].getId(); // Se p email e a senha forem corretos pega o Id do usuario logado e salva na variavel
            cout << "Logado como: " << usuarios_root[i].getEmail() << " de Id: " << usuarioLogadoId;
            salvar();
            return " !";
        }
    }
  }

  return "Usuário ou Senha não cadastrados";
}


string Sistema::disconnect() {
  carregar();
  // Verifica se algum usuario está logado
  if(usuarioLogadoId != 0){ 
    cout << "Desconectando o usuário de email: " << usuarios_root[usuarioLogadoId - 1].getEmail()<<endl;
    // usuarioLogadoId volta ao valor 0 para indicar que não há usuarios conectados
    usuarioLogadoId = 0;
    salvar();
    return "Desconectando com sucesso "; 
  }

  return "Não há nenhum usuário conectado";
}

string Sistema::create_server(const string nome) {
  carregar();
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
    salvar();
    return " criado com sucesso";
}

  return "Não há usuário conectado, favor realizar login para poder criar um servidor";
}


string Sistema::set_server_desc(const string nome, const string descricao) {
  carregar();
  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      if(servidores_root[i].getNome() == nome){
        if(servidores_root[i].getUsuarioDonoId() == usuarioLogadoId){  // verifica se o Id de quem criou o servidor é igual ao do usuário logado

          servidores_root[i].setDescricao(descricao);
          cout << "Descrição do servidor: " << servidores_root[i].getNome() << " modificada para: " << servidores_root[i].getDescricao();
          salvar();
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

  carregar();
  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      if(servidores_root[i].getNome() == nome){
        if(servidores_root[i].getUsuarioDonoId() == usuarioLogadoId){

          servidores_root[i].setCodigoConvite(codigo);
          if(codigo == ""){
            return "Codigo de convite do servidor removido";
          }
          cout << "Codigo de convite do servidor: " << servidores_root[i].getNome() << " foi modificado para: " << servidores_root[i].getCodigoConvite();
          salvar();
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
  carregar();
  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      cout << servidores_root[i].getNome() << endl;
    }
    return "lista de servidores impressa";
  }
  
  return "Não há usuário conectado, favor realizar login para poder remover um servidor";
}

string Sistema::remove_server(const string nome) {
  carregar();
  if(usuarioLogadoId != 0){ 
    for(size_t i = 0; i < servidores_root.size(); i++){ 
      if(servidores_root[i].getNome() == nome){
        if(servidores_root[i].getUsuarioDonoId() == usuarioLogadoId){

          servidores_root.erase(servidores_root.begin() + i);
          salvar();
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
            salvar();
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
  carregar();
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
      nomeServidorConectado = "";
      nomeCanalConectado = "";
      salvar();
      return "";
    }
    else{
      return "Não há servidor conectado";
    }
  }
  
  return "Não há usuário conectado, favor realizar login para poder remover um servidor";
}

string Sistema::list_participants() {
  carregar();
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
  carregar();
  if(usuarioLogadoId != 0){
    if(nomeServidorConectado != ""){
      for(size_t i = 0; i < servidores_root.size(); i++){
        if(servidores_root[i].getNome() == nomeServidorConectado){
          if(servidores_root[i].getSizeCanais() == 0){
            return "Não há canais no servidor!";
          }
          cout << "#canais de texto" << endl;
          servidores_root[i].getTexto();
          cout << "#canais de voz" << endl;
          servidores_root[i].getVoz();
        }  
      }
      return "#lista de canais impressa";
    }
    return "Não há servidor conectado";
  }
  return "Não há usuário conectado, favor realizar login para poder remover um servidor";
}

string Sistema::create_channel(const string nome, const string tipo) {
  carregar();
  if(tipo != "texto" && tipo != "voz"){
    return "Tipo de canal inválido, favor escolhor texto ou voz";
  }

  if(usuarioLogadoId != 0){
    if(nomeServidorConectado != ""){
      for(size_t i = 0; i < servidores_root.size(); i++){
        if(servidores_root[i].getNome() == nomeServidorConectado){
          for(size_t j = 0; j < servidores_root[i].getSizeCanais(); j++){
            if(servidores_root[i].ComparaNomeCanais(nome) == true){
              return "O canal de nome: " + nome + " já existe";
            }
          }
          if(tipo == "texto"){
            CanalTexto *auxTexto = new CanalTexto(nome,1);
            servidores_root[i].pushCanal(auxTexto);
            salvar();
            return "O canal de " + tipo + ": " + nome + " criado com sucesso";
          }
          if(tipo == "voz"){
            CanalVoz *auxVoz = new CanalVoz(nome,2);
            servidores_root[i].pushCanal(auxVoz);
            salvar();
            return "O canal de "+ tipo + ": " + nome + " criado com sucesso";
          }
        }  
      } 
    }
    return "Não há servidor conectado";
  }
  return "Não há usuário conectado, favor realizar login para poder criar um canal";    
  
}
  

string Sistema::enter_channel(const string nome) {
  carregar();
  if(usuarioLogadoId != 0){
    if(nomeServidorConectado != ""){
      for(size_t i = 0; i < servidores_root.size(); i++){
        if(servidores_root[i].getNome() == nomeServidorConectado){
          for(size_t j = 0; j < servidores_root[i].getSizeCanais(); j++){
            if(servidores_root[i].getNomeCanais(j) == nome){
              nomeCanalConectado = nome;
              salvar();
              return "Entrou no canal: " + nome;
            }
          }
        }       
      } 
    }
    return "Não há servidor conectado";
  }
  return "Não há usuário conectado, favor realizar login para poder entrar em um canal";    
}

string Sistema::leave_channel() {
  carregar();
  if(usuarioLogadoId == 0){
    return "Não há usuário conectado";
  }
  if(nomeServidorConectado == ""){
    return "Não há Servidor conectado";
  }
  if(nomeCanalConectado == ""){
    return "Não há canal conectado";
  }
  cout << "Saindo do canal: " << nomeCanalConectado;
  nomeCanalConectado = "";
  salvar();
  return "!";
}

string Sistema::send_message(const string mensagem) {
  carregar();
  time_t auxtempo = time(nullptr); // recebe a data e hora atual
  strftime(dataHora, 40, "%d/%m/%Y - %X", localtime(&auxtempo));  // função da biblioteca ctime que devolve a data e hora em string

  if(usuarioLogadoId == 0){
    return "Não há usuário conectado";
  }
  if(nomeServidorConectado == ""){
    return "Não há Servidor conectado";
  }
  if(nomeCanalConectado == ""){
    return "Não há canal conectado";
  } 

  for(size_t i = 0; i < servidores_root.size(); i++){
    if(servidores_root[i].getNome() == nomeServidorConectado){
      for(size_t j = 0; j < servidores_root[i].getSizeCanais(); j++){
        if(servidores_root[i].getNomeCanais(j) == nomeCanalConectado){
          Mensagem auxMensagem(dataHora, usuarioLogadoId, mensagem);
          servidores_root[i].inserirUltimaMensagem(j, auxMensagem);
          salvar();
          return "Mensagem: " + mensagem + " enviada com sucesso";      
        }
        return "Canal não existe";
      }
    }       
  } 
  return "error!";
}

string Sistema::list_messages() {
  carregar();
  if(usuarioLogadoId == 0){
    return "Não há usuário conectado";
  }
  if(nomeServidorConectado == ""){
    return "Não há Servidor conectado";
  }
  if(nomeCanalConectado == ""){
    return "Não há canal conectado";
  } 

  if(servidores_root.size() == 0){
    return "Não há mensagens no canal conectado";
  } 
  for(size_t i = 0; i < servidores_root.size(); i++){
    if(servidores_root[i].getNome() == nomeServidorConectado){
      for(size_t j = 0; j < servidores_root[i].getSizeCanais(); j++){
        if(servidores_root[i].getNomeCanais(j) == nomeCanalConectado){
            if(servidores_root[i].isMensagemVazia(j) == true){
              return "Sem mensagens para exibir no canal!";
            } 
            servidores_root[i].getMensagens(j);
            return "Mensagens impressas com sucesso";      
        }
      }
    }       
  } 
  return "error!";
  
}
