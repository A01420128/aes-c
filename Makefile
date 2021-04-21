main: main.o aes.o
	gcc -o main main.o aes.o

main.o: main.c tiny-AES-c/aes.h
	gcc -c main.c

aes.o: tiny-AES-c/aes.c tiny-AES-c/aes.h
	gcc -c tiny-AES-c/aes.c

