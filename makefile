DIR_INC = ./inc
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard $(DIR_SRC)/*.c)
OBJ = $(patsubst %c,$(DIR_OBJ)/%.o,$(notdir $(SRC)))

TARGET = data_structure
BIN_TARGET = $(DIR_BIN)/$(TARGET)

CC = gcc
CFLAGS = -I$(DIR_INC) -std=c99 -Wall 

$(BIN_TARGET):$(OBJ)
	$(CC)  $^ -o $@ 

$(DIR_OBJ)/%.o:$(DIR_SRC)/%c
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -rf ./obj/* ./bin/*