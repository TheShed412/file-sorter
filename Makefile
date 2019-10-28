OBJ=build
OUT=bin
SRC=src
SYS=$(SRC)/system
TEST=$(SRC)/test
CC=g++
CFLAGS= -std=c++11 -g
MKDIR=mkdir -p
TESTS=$(TEST)/StringUtilsTest.cpp $(SRC)/StringUtils.cpp
OBJS=$(OBJ)/ExecCMD.o $(OBJ)/MediaDate.o
SRCS=$(SRC)/main.cpp $(SRC)/ExecCMD.cpp $(SRC)/MediaInfoCMD.cpp $(SRC)/MediaDate.cpp $(SRC)/StringUtils.cpp $(SRC)/SystemUtils.cpp

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

mkouts:
	$(MKDIR) build bin

main: $(OBJ)/main.o $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT)/sorter $(SRCS)

test: $(OBJ)/StringUtils.o $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT)/tests $(TESTS)

clean:
	rm $(OUT)/* $(OBJ)/*

run_tests:
	./$(OUT)/tests

system:
	cp $(SYS)/sorter.service /etc/systemd/system/sorter.service
	cp $(SYS)/sorter.timer /etc/systemd/system/sorter.timer