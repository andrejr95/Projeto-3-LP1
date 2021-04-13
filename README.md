README - Projeto 3 da disciplina: IMD0030 - LINGUAGEM DE PROGRAMAÇÃO I - T02 (2020.2)

Professor: Renan Cipriano Moioli

Aluno: André Luis Gurgel de Faria Junior - Matrícula: 20190045378

Para compilar e rodar o programa basta abrir um terminal Linux(foi usado Ubuntu 20.04 no caso), na pasta contendo os arquivos.

## Para compilar
abra o console na pasta contendo os arquivos, nesse caso projeto3-concordo-parte1
```console
make
```

## Para executar
Você pode rodar o sistema pelo console aberto na pasta dos arquivos digitando os comandos seguidos de ENTER
```console
./concordo
```
ou por esses comandos:
```console
make run
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < script_comandos.txt
```
ou

```console
make run_script
```
Para limpar os arquivos .o e o executável criado pelo make basta digitar no console:

```console
make clean
```
Parte 2:
Um exemplo para rodar o programa já está disponivel no documento script_comandos_parte2.txt

para compilalo basta usar o comando
```console
./concordo < script_comandos_parte2.txt

```
ou

```console
make run_script2
```

Dentre as dificuldades, as principais foram acessar as informação da classe filha, em parte devido ao fato da classe pai estar sendo usada como ponteiro no vetor.
Na função list-messages não consegui fazer que seja exibido o nome de quem enviou apenas seu ID.

segue o roteiro do script_comandos_parte2.txt

// testes das funções sem usuario logado
list-channels
create-channel casa-de-mae-joana texto
create-channel casa-de-mae-joana2 voz
enter-channel casa-de-mae-joana
leave-channel

create-user teste1@imd.ufrn.br 123 nome1
create-user teste2@imd.ufrn.br 123 nome2
login teste1@imd.ufrn.br 123
create-server server1
create-server server2

//testes das funções sem servidor logado
list-channels
create-channel casa-de-mae-joana texto
create-channel casa-de-mae-joana2 voz
enter-channel casa-de-mae-joana
leave-channel
enter-server server1

//testes das funções sem canal logado
list-channels
create-channel casa-de-mae-joana texto
create-channel casa-de-mae-joana2 voz
create-channel casa-de-mae-joana2 texto
create-channel casa-de-mae-joana3 texto
create-channel casa-de-mae-joana4 voz
list-channels
enter-channel casa-de-mae-joana
leave-channel
enter-channel casa-de-mae-joana2
enter-channel casa-de-mae-joana7

//testes das funções em outro servidor usando os mesmos nomes
enter-server server2
list-channels
create-channel casa-de-mae-joana texto
create-channel casa-de-mae-joana2 voz
create-channel casa-de-mae-joana2 texto
create-channel casa-de-mae-joana3 texto
create-channel casa-de-mae-joana4 voz
list-channels
enter-channel casa-de-mae-joana
leave-channel
enter-channel casa-de-mae-joana2
enter-channel casa-de-mae-joana8
enter-channel casa-de-mae-joana
list-messages // teste para mostrar a mensagem de que "Não há mensagens no canal conectado"

// para melhor observar a diferença nos horarios realizar esses testes manualmente no Terminal

send-message Oi pessoal querem TC?
send-message teste de mensagem 2
send-message teste de mensagem 3
login teste2@imd.ufrn.br 123
send-message teste de mensagem 4
send-message teste de mensagem 5
login teste1@imd.ufrn.br 123
send-message teste de mensagem 6
send-message teste de mensagem 7
list-messages
quit
create-user naodeveprocessar@imd.ufrn.br naodevechegaraqui Não deve chegar aqui



Parte 1:
Um exemplo para rodar o programa já está disponivel no documento script_comandos.txt

Outro exemplo disponivel:

./concordo_exec

create-user teste1 123 nome1
Tentando criar o usuário: nome1 Com email: teste1
Usuário criado com sucesso
create-user teste2 1234 nome2
Tentando criar o usuário: nome2 Com email: teste2
Usuário criado com sucesso
create-user teste1 12345 nome11
Tentando criar o usuário: nome11 Com email: teste1
Usuário já cadastrado, favor usar outro email
login teste1 123
Logado como: teste1 de Id: 1 !
login teste2 1234
Logado como: teste2 de Id: 2 !
login teste3 123
Usuário ou Senha não cadastrados
login teste1 123
Logado como: teste1 de Id: 1 !
create-server server1
Servidor de nome: server1 criado com sucesso
create-server server2
Servidor de nome: server2 criado com sucesso
create-server server3
Servidor de nome: server3 criado com sucesso
create-server server1 
Esse servidor já existe, favor escolher outro nome
disconnect
Desconectando o usuário de email: teste1
Desconectando com sucesso 
create-server server4
Não há usuário conectado, favor realizar login para poder criar um servidor
disconnect
Não há nenhum usuário conectado
set-server-desc server1 teste1
Não há usuário conectado, favor realizar login para poder mudar a descrição de um servidor
login teste2 1234
Logado como: teste2 de Id: 2 !
set-server-desc server1 descrição teste
Você não pode alterar a descrição de um servidorque não foicriado por você
login teste1 123
Logado como: teste1 de Id: 1 !
set-server-desc server5 descrição teste
Servidor: server5 não existe
set-server-desc server1 descrição teste
Descrição do servidor: server1 modificada para: descrição teste
set-server-invite-code server1 123
Codigo de convite do servidor: server1 foi modificado para: 123
set-server-invite-code server1
Codigo de convite do servidor removido
set-server-invite-code server2 12345
Codigo de convite do servidor: server2 foi modificado para: 12345
set-server-invite-code server5
Nome do servidor não encontrado
login teste2 1234
Logado como: teste2 de Id: 2 !
set-server-invite-code server1 123
Você não pode alterar a descrição de um servidor que não foi criado por você
list-servers
server1
server2
server3
lista de servidores impressa
remove-server server1
Id do usuario não compativel com o dono do servidor
login teste1 123
Logado como: teste1 de Id: 1 !
remove-server server5
Nome do servidor não encontrado
remove-server server2
 Servidor: server2 foi removido com sucesso
list-servers
server1
server3
lista de servidores impressa
enter-server server1
Usuario já está no servidor - Servidor conectado
set-server-invite-code server1 12345
Codigo de convite do servidor: server1 foi modificado para: 12345
login teste2 1234
Logado como: teste2 de Id: 2 !
enter-server server1
Servidor requer código de convite ou código de convite inválidos 
enter-server server1 12345
Entrou no servidor com sucesso
list-participants
nome1
nome2
lista de participantes impressa
leave-server
Saindo do servidor: server1
login teste1 123
Logado como: teste1 de Id: 1 !
enter-server server1
Servidor requer código de convite ou código de convite inválidos 
enter-server server1 123
Servidor requer código de convite ou código de convite inválidos 
enter-server server1 12345
Usuario já está no servidor - Servidor conectado
list-participants
nome1
lista de participantes impressa
quit 
Saindo do Concordo

