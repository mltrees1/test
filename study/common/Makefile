CC = gcc
CFLAGS = -g -O0  -W -Wall
LIB_DIRS = -L/usr/lib
INCLUDE_DIRS := -I. -I../common
SRC+=./common.c ./queue.c
OUT_NAME = common.o queue.o


.PHONY : clean

$(OUT_NAME): $(SRC) 
	$(CC) $(CFLAGS) -c $(SRC) $(INCLUDE_DIRS)

clean :
	rm -f *.o
	rm -f *.d
	rm -f $(OUT_NAME)
