CC = gcc
CFLAGS = -g -O0 -W -Wall
LIB_DIRS = -L/usr/lib
INCLUDE_DIRS := -I.
INCLUDE_DIRS+=-I../common
SRC+=../common/common.c
SRC+=../common/queue.c
SRC+=main.c
SRC+=floyd-warshall.c
INC := 
OUT_NAME=aa.out

$(OUT_NAME): $(SRC) 
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC) $(INC) $(INCLUDE_DIRS)
clean :
	rm -f *.o
	rm -f *.d
	rm -f $(OUT_NAME)
