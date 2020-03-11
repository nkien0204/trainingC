build: main.o bai1.o bai3.o bai4.o bai5.o bai6.o bai7.o bai8.o bai9.o bai10.o
	gcc -o build main.o bai1.o bai3.o bai4.o bai5.o bai6.o bai7.o bai8.o bai9.o bai10.o -lm
main.o: main.c proj.h
	gcc -c main.c
bai1.o: bai1.c proj.h
	gcc -c bai1.c
bai3.o: bai3.c proj.h
	gcc -c bai3.c
bai4.o: bai4.c proj.h
	gcc -c bai4.c
bai5.o: bai5.c proj.h
	gcc -c bai5.c
bai6.o: bai6.c proj.h
	gcc -c bai6.c
bai7.o: bai7.c proj.h
	gcc -c bai7.c
bai8.o: bai8.c proj.h
	gcc -c bai8.c
bai9.o: bai9.c proj.h
	gcc -c bai9.c
bai10.o: bai10.c proj.h
	gcc -c bai10.c
