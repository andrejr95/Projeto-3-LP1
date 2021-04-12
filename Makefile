#Makefile para Projeto 3 LP1 - UFRN
#Autor: André Luis Gurgel de Faria Junior


CC = g++
CFLAGS  = -std=c++11 -Iinclude -Wall -fsanitize=address -pedantic -g


default: concordo_exec


concordo_exec: bin/concordo.o bin/usuario.o bin/servidor.o bin/canal.o bin/executor.o bin/mensagem.o bin/sistema.o
	$(CC) $(CFLAGS) -o concordo_exec bin/concordo.o bin/usuario.o bin/servidor.o bin/canal.o bin/executor.o bin/mensagem.o bin/sistema.o


bin/concordo.o:  src/concordo.cpp include/sistema.h include/executor.h
	$(CC) $(CFLAGS) -c src/concordo.cpp -o bin/concordo.o

bin/usuario.o:  src/usuario.cpp include/usuario.h 
	$(CC) $(CFLAGS) -c src/usuario.cpp -o bin/usuario.o

bin/servidor.o:  src/servidor.cpp include/servidor.h include/canal.h include/canaltexto.h include/canalvoz.h
	$(CC) $(CFLAGS) -c src/servidor.cpp -o bin/servidor.o

bin/canal.o:  src/canal.cpp include/canal.h
	$(CC) $(CFLAGS) -c src/canal.cpp -o bin/canal.o

bin/executor.o:  src/executor.cpp include/executor.h include/sistema.h
	$(CC) $(CFLAGS) -c src/executor.cpp -o bin/executor.o

bin/mensagem.o:  src/mensagem.cpp include/mensagem.h
	$(CC) $(CFLAGS) -c src/mensagem.cpp -o bin/mensagem.o

bin/sistema.o:  src/sistema.cpp include/sistema.h include/servidor.h include/usuario.h include/date.h include/canal.h include/canaltexto.h include/canalvoz.h 
	$(CC) $(CFLAGS) -c src/sistema.cpp -o bin/sistema.o



run: default
	./concordo_exec

run_script: default
	./concordo_exec < script_comandos.txt

run_script2: default
	./concordo_exec < script_comandos_parte2.txt	


clean: 
	$(RM) concordo_exec bin/*.o *~



