program: main.o funcoes.o
	gcc -o program main.o funcoes.o
main.o: main.c funcoes.h
	gcc -c  main.c
funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c
clean:
	rm -f program *.o
