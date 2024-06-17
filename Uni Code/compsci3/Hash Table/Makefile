# This makefile is for Windows OS, 
# If you are using Linux, you need to change the del command to rm and remove the .exe extension from the OUT variable name.

# Also, the object files are removed after the executable is created.
# If you want to stop this from happening, remove the del $(OBJS) line under "all".

OBJS	= Main.o Hash.o
SOURCE	= Main.cpp Hash.cpp 
HEADER	= Hash.h
OUT		= hashtable.exe
CC		= g++
FLAGS	= -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	del $(OBJS)

Main.o: Main.cpp
	$(CC) $(FLAGS) Main.cpp 

Hash.o: Hash.cpp
	$(CC) $(FLAGS) Hash.cpp 


clean:
	del $(OBJS) $(OUT)