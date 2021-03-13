
tokenizer.o:tokenizer.h tokenizer.c  cc -c tokenizer.c

interface.o: tokenizer.h interface.c  cc -c interface.c

main: interface.o  tokenizer.o  cc -o ftest  tokenizer.o interface.o

clean: rm -f dtest *.o *# ~*
