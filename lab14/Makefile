targets = main.bin
CC = g++
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/RBTree.cpp

all: run

clean:
	rm -rf dist
prep: clean
	mkdir dist
compile: prep main.bin 

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@ -lm

run: compile
	./dist/main.bin
	
doxygen: prep
	doxygen Doxyfile
