CC = gcc
CFLAGS = -g -O0 -W -Wall
LIB_DIRS = -L/usr/lib
INCLUDE_DIRS := -I.
INCLUDE_DIRS+=-I../common
INCLUDE_DIRS+=-I../bubble_sort
INCLUDE_DIRS+=-I../quick_sort
SRC+=../common/common.c
SRC+=../bubble_sort/bubble_sort.c
SRC+=../quick_sort/quick_sort.c
SRC+=dfs_main.c
INC := 
OUT_NAME=dfs.out

$(OUT_NAME): $(SRC) 
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC) $(INC) $(INCLUDE_DIRS)
clean :
	rm -f *.o
	rm -f *.d
	rm -f $(OUT_NAME)
