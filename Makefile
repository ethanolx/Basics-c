# Adapted from Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
.PHONY: clean
.SHELLFLAGS := -Command
.SILENT:
BUILD_DIR := build
CC := gcc
SHELL := pwsh.exe
SRC_DIR := src
TARGET_EXEC := main.exe

# Find all the C files we want to compile
SRCS := $(shell fd -g '*.c' --base-directory $(SRC_DIR))

# String substitution for every C file.
# As an example, hello.cpp turns into build/hello.o
OBJS := $(SRCS:.\\%.c=$(BUILD_DIR)/%.o)

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

# Build step for C source
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

# Run step
run: clean $(BUILD_DIR)/$(TARGET_EXEC)
	./$(BUILD_DIR)/$(TARGET_EXEC)

# Clean object files and executable
clean: 
	mkdir -Force $(BUILD_DIR)
	rm $(BUILD_DIR)/*
