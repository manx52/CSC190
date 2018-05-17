#
# Makefile
#
# Computer Science 50
# Problem Set 5
#


# compiler to use
CC = gcc

# flags to pass compiler
CFLAGS = -ggdb3 -O0 -std=c99 -Wall -Werror -Wno-unused-variable

# name for executable
EXE = speller

# space-separated list of header files
HDRS = dictionary.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l


# space-separated list of source files
SRCS = speller.c dictionary.c

# automatically generated list of object files
#OBJS = $(SRCS:.c=.o)


# default target
$(EXE) : $(SRCS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(SRCS)



# housekeeping
clean:
	del /F /S speller.exe *.o 
