OBJ=build
OUT=bin
SRC=src
CC=g++
CFLAGS= -std=c++11 -g
MKDIR=mkdir -p
OBJS=$(OBJ)/ExecCMD.o $(OBJ)/MediaDate.o
SRCS=$(SRC)/main.cpp $(SRC)/ExecCMD.cpp $(SRC)/MediaInfoCMD.cpp $(SRC)/MediaDate.cpp $(SRC)/StringUtils.cpp

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

mkouts:
	$(MKDIR) build bin

main: $(OBJ)/main.o $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT)/sorter $(SRCS)

clean:
	rm $(OUT)/* $(OBJ)/*