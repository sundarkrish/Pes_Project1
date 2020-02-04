# -*- Makefile -*-

DIR1 = ./program1/
DIR2 = ./program2/
DIR3 = ./program3/

# Path variable for locating the dependencies that have no target
VPATH =  $(DIR1)data/ $(DIR1)inc $(DIR1)src  \
		 $(DIR2)data/ $(DIR2)inc $(DIR2)src \
		 $(DIR3)data/ $(DIR3)inc $(DIR3)src \
		 ./exec/ ./obj/

# To build all three programs at once
all: one two three

# Targets for dependency tree for program 1
one: one.o conversions.o 
	gcc -o ./exec/one ./obj/one.o ./obj/conversions.o  -Werror -lm

one.o: one.c conversions.h
	gcc -c $(DIR1)data/one.c -o ./obj/one.o  -I$(DIR1)inc/ -Werror

conversions.o: conversions.c conversions.h
	gcc -c $(DIR1)src/conversions.c -o ./obj/conversions.o -I$(DIR1)inc/ -Werror


# Targets for dependency tree for program 2
two: two.o asciiclassifier.o
	gcc ./obj/two.o ./obj/asciiclassifier.o -o ./exec/two -Werror

two.o: two.c asciiclassifier.h
	gcc -c $(DIR2)data/two.c -o ./obj/two.o -I$(DIR2)inc/ -Werror

asciiclassifier.o: asciiclassifier.c asciiclassifier.h
	gcc -c $(DIR2)src/asciiclassifier.c -o ./obj/asciiclassifier.o -I$(DIR2)inc/ -Werror 

# Targets for dependency tree for program 3
three: three.o operations.o
	gcc ./obj/three.o ./obj/operations.o -o ./exec/three -Werror

three.o: three.c operations.h
	gcc -c $(DIR3)data/three.c -o ./obj/three.o -I$(DIR3)inc/ -Werror

operations.o: operations.c operations.h
	gcc -c $(DIR3)src/operations.c -o ./obj/operations.o -I$(DIR3)inc/ -Werror 

# Removes all the newly created object and executable files
clean: 
	find . -type f -name "*.o" -exec rm -f {} \;
	rm -f ./exec/*

