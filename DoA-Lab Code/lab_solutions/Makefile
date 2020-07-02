# Makefile for the racecar module and testing program.
#
# Created for COMP20007 Design of Algorithms 2020
# Written by Tobias Edwards <tobias.edwards@unimelb.edu.au>

# The following target is the program's executable file, it requires the
# two c files (racecar.c and racecar_test.c) to have already been compiled into
# their corresponding object files (i.e., .o files). If this hasn't been done
# then make will try to find a target which will do just this (as are defined
# below) and make those targets before this one is run.
#
# racecar_test is the name of the executable which will be created.
racecar_test: racecar_test.o racecar.o
	gcc -Wall -o racecar_test racecar_test.o racecar.o

# The following two rules provide instructions on how to compile the c files
# required for this program.  Note that both rely on racecar.h being present,
# even though we don't use it directly during compilation.

racecar_test.o: racecar_test.c racecar.h
	gcc -Wall -c racecar_test.c

racecar.o: racecar.c racecar.h
	gcc -Wall -c racecar.c

# The following rule doesn't create any files, but rather helps us clean up
# our working environment by deleting the files which result from the
# compilation of this program.
#
# Since nothing is created during this rule, we have to mark it as "phony",
# i.e., it runs the instructions but make doesn't need to expect for there
# to be a file named clean after the rule is run.

.PHONY: clean

clean:
	rm *.o racecar_test
