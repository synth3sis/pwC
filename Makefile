output: keygen.c
		gcc -w keygen.c -o pwC

clean:
		rm *.o
		chmod u+x pwC
