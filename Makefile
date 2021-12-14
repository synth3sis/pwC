CC = gcc

all: pwC numC

pwC: src/keygen.c
	$(CC) src/keygen.c -o bin/pwC

numC: src/numgen.c
	$(CC) src/numgen.c -o bin/numC


clean:
	chmod u+x bin/pwC
	chmod u+x bin/numC
	cp bin/pwC /usr/loca/sbin/pwC
	cp bin/numC /usr/local/sbin/numC
