CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = biblioteca.exe
OBJ = main.o def.o orden.o

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

main.o: main.c def.h orden.h
	$(CC) $(CFLAGS) -c main.c -o main.o

def.o: def.c def.h
	$(CC) $(CFLAGS) -c def.c -o def.o

orden.o: orden.c def.h orden.h
	$(CC) $(CFLAGS) -c orden.c -o orden.o

run: $(TARGET)
	@echo 0 | .\$(TARGET)

clean:
	@del /q *.o $(TARGET) 2>NUL || true