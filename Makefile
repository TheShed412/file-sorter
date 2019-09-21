OBJ=build
OUT=bin
SRC=src
CC=g++
CFLAGS= -std=c++11 -g
MKDIR=mkdir -p

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

mkouts:
	$(MKDIR) build bin

main: $(OBJ)/main.o $(OBJ)/ExecCMD.o
	$(CC) $(CFLAGS) -o $(OUT)/sorter $(SRC)/main.cpp $(SRC)/ExecCMD.cpp $(SRC)/MediaInfoCMD.cpp $(SRC)/MediaDate.cpp

clean:
	rm $(OUT)/* $(OBJ)/*