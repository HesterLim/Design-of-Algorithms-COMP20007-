# # # # # # #
# Sample Makefile for compiling a simple multi-module C program
#
# created for COMP20007 Design of Algorithms 2017
# by Matt Farrugia <matt.farrugia@unimelb.edu.au>
#

# Welcome to this sample Makefile. If you're new to make and makefiles, have a
# read through with the comments and follow their instructions.

# VARIABLES - change the values here to match your project setup

# specifying the C Compiler and Compiler Flags for make to use
CC     = gcc
CFLAGS = -Wall

# executable name and a list of object files that make up the program
EXE    = main
OBJ    = main.o list.o

# RULES - these tell make when and how to recompile parts of the project

# the first rule runs by default when you run 'make' ('make rule' for others)
# in our case, we probably want to build the whole project by default, so we
# make our first rule have the executable as its target
#  |
#  v
$(EXE): $(OBJ) # <-- the target is followed by a list of prerequisites
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)
# ^
# and a TAB character, then a shell command (or possibly multiple, 1 line each)
# (it's very important to use a TAB here because that's what make is expecting)

# the way it works is: if any of the prerequisites are missing or need to be
# recompiled, make will sort that out and then run the shell command to refresh
# this target too

# so our first rule says that the executable depends on all of the object files,
# and if any of the object files need to be updated (or created), we should do
# that and then link the executable using the command given

# okay here's another rule, this time to help make create object files
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

# finally, this last rule is a common convention, and a real nice-to-have
# it's a special target that doesn't represent a file (a 'phony' target) and
# just serves as an easy way to clean up the directory by removing all .o files
# and the executable, for a fresh start

clean:
	rm -f $(OBJ) $(EXE)
