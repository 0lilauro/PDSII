CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
INPUT	:= input
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main
INPUTFILE	:= test2


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

test: clean all
	clear
	./$(BIN)/$(EXECUTABLE)  < ./$(INPUT)/$(INPUTFILE).txt

clean:
	-rm $(BIN)/*
