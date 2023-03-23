# COMPILER
CC = gcc
WFLAGS = -Wall -Wextra -Werror

# DIRS
DIST = build
BIN = $(DIST)/bin
OBJ = $(DIST)/obj
SOURCE = src
MODULES = $(SOURCE)/modules

# FILES
DEPENDECIES = $(DIST)/ $(patsubst $(MODULES)/%.c, $(OBJ)/%.o, $(wildcard $(MODULES)/*.c)) $(OBJ)/main.o
TARGET = main

$(BIN)/$(TARGET): $(DEPENDECIES)
	@echo "[COMPILING ALL]"

	$(CC) $(WFLAGS) \
	$(OBJ)/*.o \
	-o $(BIN)/$(TARGET)

	@echo

$(DIST)/:
	@echo "[CREATING DIST FOLDERS]"

	mkdir $(DIST)/ $(BIN)/ $(OBJ)/

	@echo


$(OBJ)/%.o: $(MODULES)/%.h $(MODULES)/%.c
	@echo "[COMPILING MODULE] $*"

	$(CC) $(WFLAGS) -c \
	$(MODULES)/$*.c

	mv $*.o \
	$(OBJ)

	@echo

$(OBJ)/main.o: $(SOURCE)/main.c
	@echo "[COMPILING MAIN]"

	$(CC) $(WFLAGS) -c \
	$(SOURCE)/main.c

	mv main.o \
	$(OBJ)

	@echo

clean:
	@echo "[CLEANING OBJECTS]"

	rm -rf \
	$(OBJ)/*.o

	@echo

hardclean:
	@echo "[CLEANING ALL DIST STUFF]"

	rm -r \
	$(DIST)/

	@echo

run: $(BIN)/$(TARGET)
	@echo "[RUNNING $(TARGET)]"
	
	$(BIN)/$(TARGET)

	@echo

test:
	@echo "$(DEPENDECIES)"