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
