CC=g++
CFLAGS=-c -Wall -g
FLAGS=-o
INCLUDE=-I../inc/

OBJ=../obj/
SRC=../src/
BIN=../bin/


$(BIN)sse_rel1: $(OBJ)main.o $(OBJ)calculator.o  
	$(CC) $(FLAGS) $(BIN)sse_rel1  $(OBJ)main.o $(OBJ)calculator.o $(INCLUDE) 
	printf "\n"

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) $(FLAGS) $(OBJ)main.o  $(CFLAGS) $(SRC)main.cpp $(INCLUDE)
	printf "\n"

$(OBJ)calculator.o: $(SRC)calculator.cpp 
	$(CC) $(FLAGS) $(OBJ)calculator.o $(CFLAGS)  $(SRC)calculator.cpp $(INCLUDE)
	printf "\n"

clean:
	rm  $(OBJ)*

	
