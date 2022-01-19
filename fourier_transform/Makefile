CC=g++
CFLAGS=-O3 -std=c++17
EXE=run
SRC=tester.cpp

default: $(EXE)

test: $(EXE)
	./$(EXE)

$(EXE):
	$(CC) -o $(EXE) $(FLAGS) $(SRC)

clean:
	rm -f $(EXE)