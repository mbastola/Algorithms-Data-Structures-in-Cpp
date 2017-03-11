##Files:

Makefile
codonDecrypt.cc
codonEncrypt.cc
encrypt.cc
decrypt.cc
keyGen.cc
numberTheory.cc
numberTheory.h
transform.cc
transform.h

##Rules in the make file so that the only compiling that
needs to be done is: 

make all

Then you can use:

make clean 

to clean all unnecessary files.
----------------------------------------------
##cmd argumemts:

>>./keyGen {Prime1} {Prime2}
>>./encrypt private.txt {fileToBeEncypted} {encryptedFile}
>>./decrypt public.txt {fileToBeDecypted} {decryptedFile}

In the end  {fileToBeEncypted}=={decryptedFile}
-------------------------------------------------------------------
for CODONS:

>>./keyGen {Prime1} {Prime2}
>>./codonEncrypt private.txt {fileToBeEncypted} {encryptedFile}
>>./codonDecrypt public.txt {fileToBeDecypted} {decryptedFile}

