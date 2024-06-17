# This makefile is for Windows OS, 
# If you are using Linux, you need to change the del command to rm and remove the .exe extension from the OUT variable name.

OBJS	= HashingTables.o IntChainHash.o IntLinHash.o IntQuadHash.o
SOURCE	= HashingTables.cpp IntChainHash.cpp IntLinHash.cpp IntQuadHash.cpp
HEADER	= IntChainHash.h IntLinHash.h IntQuadHash.h
OUT		= hashtables.exe
CC		= g++
FLAGS	= -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	del $(OBJS)

HashingTables.o: HashingTables.cpp
	$(CC) $(FLAGS) HashingTables.cpp 

IntChainHash.o: IntChainHash.cpp
	$(CC) $(FLAGS) IntChainHash.cpp 

IntLinHash.o: IntLinHash.cpp
	$(CC) $(FLAGS) IntLinHash.cpp 

IntQuadHash.o: IntQuadHash.cpp
	$(CC) $(FLAGS) IntQuadHash.cpp 


clean:
	del $(OBJS) $(OUT)