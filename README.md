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

