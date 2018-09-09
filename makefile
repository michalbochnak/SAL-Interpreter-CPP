CFLAGS = -O
CC = g++ -std=c++11
SRC = main.cpp Command.cpp ADD.cpp DEC.cpp HLT.cpp JMP.cpp JVS.cpp JZS.cpp LDA.cpp LDB.cpp LDI.cpp ST.cpp XCH.cpp Symbol.cpp Computer.cpp
OBJ = $(SRC:.cpp = .o)
mbochn2: $(OBJ)
	$(CC) $(CFLAGS) -o mbochn2 $(OBJ)
clean:
	rm -f core *.o 

run:
	./mbochn2

valgrind:
	valgrind ./mbochn2
