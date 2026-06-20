CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o orden.o def.o

PITBULL: $(OBJ)
$(CC) $(CFLAGS) -o PITBULL $(OBJ)
main.o: main.c def.c orden.c orden.h
orden.o: def.c orden.c orden.h
def.o: def.c def.h

clean:
rm -f *.o PITBULL