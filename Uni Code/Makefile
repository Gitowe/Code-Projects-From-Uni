# This makefile is for Windows OS, 
# If you are using Linux, you need to change the del command to rm and remove the .exe extension from the OUT variable name.

OBJS	= main.o ItemToPurchase.o ShoppingCart.o
SOURCE	= main.cpp ItemToPurchase.cpp ShoppingCart.cpp
HEADER	= ItemToPurchase.h ShoppingCart.h
OUT		= market.exe
CC		= g++
FLAGS	= -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

ItemToPurchase.o: ItemToPurchase.cpp
	$(CC) $(FLAGS) ItemToPurchase.cpp

ShoppingCart.o: ShoppingCart.cpp
	$(CC) $(FLAGS) ShoppingCart.cpp  


clean:
	del $(OBJS) $(OUT)