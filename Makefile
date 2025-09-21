SRC_FILE = virtualMachine.c
CC = gcc

all:
	${CC} ${SRC_FILE} -o virtualMachine
	./virtualMachine