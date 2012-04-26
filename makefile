CC=g++
CFLAGS=-g -Wall

DOBJS=decode.o BitStreams.o
EOBJS=encode.o BitStreams.o

# rule for building the executable
default:  encode

decode: $(DOBJS)
	$(CC) -o decode $(DOBJS)

encode: $(EOBJS)
	$(CC) -o encode $(EOBJS)

all:      encode decode

# list of file dependencies
decode.o:           decode.cpp BitStreams.h LinkedBinaryTree.h
encode.o:           encode.cpp BitStreams.h LinkedBinaryTree.h
BitStreams.o:       BitStreams.h BitStreams.cpp

# the following rule is used to compile .cpp files to .o
.cpp.o:
	$(CC) $(CFLAGS) -c $<


# the following removes all .o files, but leaves the executable
clean:
	rm -f *.o
