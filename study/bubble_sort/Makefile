CC = gcc
CFLAGS = -g -O0 -c -W -Wall
LIB_DIRS = -L/usr/lib
INCLUDE_DIRS := -I. -I../common
SRC+=./bubble_sort.c
INC := 
OUT_NAME=bubble_sort.o

.PHONY : clean

$(OUT_NAME): $(SRC) 
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC) $(INC) $(INCLUDE_DIRS)
clean :
	rm -f *.o
	rm -f *.d
	rm -f $(OUT_NAME)
