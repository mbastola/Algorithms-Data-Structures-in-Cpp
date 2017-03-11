
OPTS = -Wall

all: decrypt encrypt keyGen codonEncrypt codonDecrypt

codonDecrypt: codonDecrypt.cc numberTheory.o transform.o
	g++ ${OPTS} -o codonDecrypt codonDecrypt.cc numberTheory.o transform.o

codonEncrypt: codonEncrypt.cc numberTheory.o transform.o
	g++ ${OPTS} -o codonEncrypt codonEncrypt.cc numberTheory.o transform.o

transform.o : transform.cc transform.h
	g++ ${OPTS} -c transform.cc


decrypt: decrypt.cc numberTheory.o
	g++ ${OPTS} -o decrypt decrypt.cc numberTheory.o

encrypt: encrypt.cc numberTheory.o
	g++ ${OPTS} -o encrypt encrypt.cc numberTheory.o

keyGen: keyGen.cc numberTheory.o
	g++ ${OPTS} -o keyGen keyGen.cc numberTheory.o

numberTheory.o: numberTheory.cc numberTheory.h
	       g++ ${OPTS} -c numberTheory.cc

final: cleanemacs clean

cleanemacs:
	 rm *~
clean:
	rm *.o
	rm public.txt
	rm private.txt
	rm encrypted.txt
	rm decrypted.txt
	rm codonEncrypted.txt
	rm codonDecrypted.txt

