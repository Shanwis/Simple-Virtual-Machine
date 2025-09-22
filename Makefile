SRC = src/virtualMachine.c src/main.c
CC = gcc
CFLAG = -Iinclude
OBJ = $(SRC:.c=.o)
TARGET = virtualMachine

.PHONY: all clean run

all:$(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:$(TRAGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)