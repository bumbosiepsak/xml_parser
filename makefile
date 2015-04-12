#   @b Project: Dacuda
#   @file        makefile
#   @author      Szymon Gutaj (sgutaj) <gutajszymon@interia.com>
#   @brief       Simple makefile for building sample code
#   @date        08-02-2012
#   @version     0.1

.DEFAULT_GOAL:=all

# Please fill this variable with your path to GCC compiler (if you dont have it in PATH environment variable)
PATHS_GCC := 

PATHS_INCL:=includes
FILES_CODE:=main.cpp
FILES_CODE+=$(wildcard sources/middleware/xml/*.cpp)
FILES_CODE+=$(wildcard sources/middleware/xml/impl/*.cpp)

.PHONY: all
all: compile
	@main.exe

compile: $(FILES_CODE)
	@$(PATHS_GCC)g++ -o main.exe -I$(PATHS_INCL) $(FILES_CODE)

.PHONY: tests
tests:
	$(MAKE) -f tests.mk TARGET=Host TOOLCHAIN=gcc UNIT_TESTS=Yes PATHS_CUSTOM=Yes all
