#makefile for producing a3.out
/* To compile in the terminal, simply type: make a3.out */

CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

a3.out : main.o admin.o user.o
		 $(C) $(CFLAGS) -o a3.out main.o admin.o user.o

main.o : main.c ass3.h
         $(C) $(CFLAGS) -c -o main.o main.c

admin.o : admin.c ass3.h
         $(C) $(CFLAGS) -c -o admin.o admin.c

user.o : user.c ass3.h
         $(C) $(CFLAGS) -c -o user.o user.c

clean: 
rm a3.out main.o admin.o user.o    /* 'make clean' typed in the terminal will delete object files */
