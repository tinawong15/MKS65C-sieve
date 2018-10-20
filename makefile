all: sieve.o main.o
	gcc sieve.o main.o -lm

sieve.o: sieve.c sieve.h
	gcc -c -g sieve.c

main.o: main.c sieve.h
	gcc -c -g main.c

run:
	./a.out $(args)

clean:
	rm *.o
