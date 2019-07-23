OBJ=build
OUT=bin
SRC=src
CC=g++
CFLAGS= -std=c++11 -g -c
MKDIR=mkdir -p

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

mkouts:
	$(MKDIR) build bin

main: mkouts $(OBJ)/main.o
	$(CC) $(CFLAGS) -o $(OUT)/sorter $(SRC)/main.cpp

clean:
	rm $(OUT)/* $(OBJ)/*