
# Compiler and linker settings
NAME=Battleship
CC = gcc
NASM = nasm
CFLAGS = -Wall -Wextra -lncurses
NASMFLAGS = -f elf64 
LDFLAGS = -nostartfiles -lncurses -pie
# Source files
ASSEMBLY_SOURCE = src/backend/main.asm
ASSEMBLY_INCLUDE = src/backend/helpers.inc
C_SOURCE = src/ui/uimain.c

# Object files
ASSEMBLY_OBJ = $(ASSEMBLY_SOURCE:.asm=.o)
C_OBJ = $(C_SOURCE:.c=.o)

# Executable
EXECUTABLE = /usr/bin/$(NAME)

# Default target
all: $(EXECUTABLE)

# Linking step
$(EXECUTABLE): $(ASSEMBLY_OBJ) $(C_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compilation steps
$(ASSEMBLY_OBJ): $(ASSEMBLY_SOURCE) $(ASSEMBLY_INCLUDE)
	$(NASM) $(NASMFLAGS) -I src/backend/ -o $@ $<

$(C_OBJ): $(C_SOURCE) $(ASSEMBLY_INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -f $(ASSEMBLY_OBJ) $(C_OBJ) 	

