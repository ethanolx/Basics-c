# == CONFIG ==

# Make
.PHONY: clean purge scaffold build run all
.SILENT: clean purge scaffold build run all
.SECONDARY: ${OBJS_FULL}

# Shell
SHELL := pwsh.exe
.SHELLFLAGS := -Command

# Compiler
CC := gcc

# Nomenclature
SRC_DIR := src
BUILD_DIR := build
TARGET := main
EXTENSION := exe

# Mode
OPTIM := true


# == VARIABLES ==

# Generate headers
HEADER := +-----------------------------+

# Generate section directories (e.g. "build/1 build/2")
SECTIONS := ${shell fd --type directory --base-directory ${SRC_DIR} --exact-depth 1}
SECTIONS := ${SECTIONS:.\\%=%}
SECTIONS := ${SECTIONS:%\=%}
SECTIONS_FULL = ${foreach sect,${SECTIONS},${BUILD_DIR}/${sect}/}

# Generate utility files (e.g. "build/util1.o build/util2.o")
UTILS := ${shell fd -g 'util*.c' --base-directory ${SRC_DIR} --exact-depth 1}
UTILS := ${UTILS:.\\%=%}
UTILS := ${UTILS:c=o}
UTILS_FULL := ${foreach util,${UTILS},${BUILD_DIR}/${util}}

# Generate source files (e.g. "build/1/main.c build/1/func.c")
SRCS = ${shell fd -g '*.c' --base-directory src/${1}}
SRCS_CLEAN = ${SRCS:.\\%=%}

# Generate object files (e.g. "build/1/main.o build/1/func.o")
OBJS = ${SRCS_CLEAN:c=o}
OBJS_FULL = ${foreach obj,${call OBJS,${1}},${BUILD_DIR}/${1}/${obj}}

# Generate target files (e.g. "build/1/main.exe build/2/main.exe")
TARGETS := ${foreach sect,${SECTIONS},${BUILD_DIR}/${sect}/${TARGET}.${EXTENSION}}


# == STEPS ==

# all step [default]
# -------------
# Shorthand for build & run
all: build run


# Run step
# -------------
# Run all executables in ascending section order
run: | build
	Foreach ($$Targ in "${TARGETS}".Split()) { Write-Host ${HEADER}`n`| Running $$Targ`... `|`n${HEADER}`n -NoNewLine -ForegroundColor Cyan; iex $$targ; }


# Build step
# -------------
# Build executables using source files in sections
# and linked together with the utility sources
build: scaffold ${TARGETS}

${BUILD_DIR}/%/${TARGET}.${EXTENSION}: ${UTILS_FULL} ${call OBJS_FULL,$*}
ifeq (${OPTIM},true)
	${if ${findstring $*,$?},${CC} ${call OBJS_FULL,$*} ${UTILS_FULL} -o $@,${if ${findstring util,$?},${CC} ${call OBJS_FULL,$*} ${UTILS_FULL} -o $@,}}
else
	${CC} ${call OBJS_FULL,$*} ${UTILS_FULL} -o $@
endif

${BUILD_DIR}/%.o: ${SRC_DIR}/%.c
	${CC} -c $< -o $@


# Scaffold step
# -------------
# Create section directories in the build directory
# if they do not exist
scaffold: ${BUILD_DIR}/ ${SECTIONS_FULL}

${BUILD_DIR}/:
	@If (-Not (Test-Path $@)) { mkdir $@ | Out-Null }

${BUILD_DIR}/%/:
	@If (-Not (Test-Path $@)) { mkdir $@ | Out-Null }


# Purge step
# -------------
# Remove all build objects
purge:
	rm -Recurse ${BUILD_DIR}/**/*.o
	rm -Recurse ${BUILD_DIR}/*.o


# Clean step
# -------------
# Remove the entire build directory
clean:
	rm -Recurse ${BUILD_DIR}
