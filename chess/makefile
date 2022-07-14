#RULES
CC = g++
CFLAGS = -std=c++98 -c
LFLAGS = -g -std=c++98
TARGET = chessgame
OBJECTS = Llist.o piece.o queen.o bishop.o knight.o rook.o pawn.o king.o stack.o board.o game.o main.o

#linking the object code
all: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)

#partial compilation of files into object code
pawn.o: gamepieces/pieces/pawn/pawn.cpp gamepieces/pieces/pawn/pawn.h
	$(CC) $(CFLAGS) gamepieces/pieces/pawn/pawn.cpp

rook.o: gamepieces/pieces/rook/rook.cpp gamepieces/pieces/rook/rook.h
	$(CC) $(CFLAGS) gamepieces/pieces/rook/rook.cpp

knight.o: gamepieces/pieces/knight/knight.cpp gamepieces/pieces/knight/knight.h
	$(CC) $(CFLAGS) gamepieces/pieces/knight/knight.cpp

bishop.o: gamepieces/pieces/bishop/bishop.cpp gamepieces/pieces/bishop/bishop.h
	$(CC) $(CFLAGS) gamepieces/pieces/bishop/bishop.cpp

queen.o: gamepieces/pieces/queen/queen.cpp gamepieces/pieces/queen/queen.h
	$(CC) $(CFLAGS) gamepieces/pieces/queen/queen.cpp

king.o:	gamepieces/pieces/king/king.cpp gamepieces/pieces/king/king.h \
		gamepieces/pieces/pawn/pawn.h gamepieces/pieces/rook/rook.h \
		gamepieces/pieces/knight/knight.h gamepieces/pieces/bishop/bishop.h \
		gamepieces/pieces/queen/queen.h
	$(CC) $(CFLAGS) gamepieces/pieces/king/king.cpp

piece.o: gamepieces/pieces/piece.cpp gamepieces/pieces/piece.h \
         gamepieces/linkedlist/Llist.h
	$(CC) $(CFLAGS) gamepieces/pieces/piece.cpp

Llist.o: gamepieces/linkedlist/Llist.cpp gamepieces/linkedlist/Llist.h
	$(CC) $(CFLAGS) gamepieces/linkedlist/Llist.cpp

board.o: board/board.cpp board/board.h board/stack.h gamepieces/pieces/piece.h gamepieces/pieces/pawn/pawn.h \
		 gamepieces/pieces/rook/rook.h gamepieces/pieces/knight/knight.h \
		 gamepieces/pieces/bishop/bishop.h gamepieces/pieces/queen/queen.h \
		 gamepieces/pieces/king/king.h
	$(CC) $(CFLAGS) board/board.cpp

stack.o: board/stack.cpp board/stack.h
	$(CC) $(CFLAGS) board/stack.cpp

game.o: game.cpp board/board.h
	$(CC) $(CFLAGS) game.cpp

main.o: main.cpp game.h
	$(CC) $(CFLAGS) main.cpp

#custom commands

#runs the linked object code
run:
	./$(TARGET)

#deletes all object code and tar files whilst using -f to supress any errors
clean:
	rm -f *.o *.tar $(TARGET) 

#invokes valgrind for memory leaks checking purposes
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TARGET)

valgrind_more:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./$(TARGET)

#tars all files except for the object code
tarfile:
	tar -cvz *.cpp *.h pieces/*.cpp pieces/*.h makefile -f chess.tar

#invokes gdb for debugging
debug:
	gdb ./$(TARGET)