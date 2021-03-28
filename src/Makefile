#Makefile para Projeto 3 LP1 - UFRN
#Autor: André Luis Gurgel de Faria Junior


CC = g++
CFLAGS  = -std=c++11  -Wall -fsanitize=address -pedantic -g

default: concordo_exec

concordo_exec: concordo.o usuario.o servidor.o canal.o executor.o mensagem.o sistema.o
	$(CC) $(CFLAGS) -o concordo_exec concordo.o usuario.o servidor.o canal.o executor.o mensagem.o sistema.o


concordo.o:  concordo.cpp sistema.h executor.h
	$(CC) $(CFLAGS) -c concordo.cpp

usuario.o:  usuario.cpp usuario.h 
	$(CC) $(CFLAGS) -c usuario.cpp

servidor.o:  servidor.cpp servidor.h canal.h canaltexto.h canalvoz.h
	$(CC) $(CFLAGS) -c servidor.cpp

canal.o:  canal.cpp canal.h
	$(CC) $(CFLAGS) -c canal.cpp

executor.o:  executor.cpp executor.h sistema.h
	$(CC) $(CFLAGS) -c executor.cpp

mensagem.o:  mensagem.cpp mensagem.h
	$(CC) $(CFLAGS) -c mensagem.cpp

sistema.o:  sistema.cpp sistema.h servidor.h usuario.h
	$(CC) $(CFLAGS) -c sistema.cpp


run: default
	./concordo_exec

run_script: default
	./concordo_exec < script_comandos.txt	


clean: 
	$(RM) concordo_exec *.o *~



