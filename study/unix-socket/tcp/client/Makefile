CC = gcc
CFLAGS = -g -O0 -W -Wall
LIB_DIRS = -L/usr/lib
INCLUDE_DIRS := -I.
SRC=tcp_client.c
INC := 
OUT_NAME=client.out

$(OUT_NAME): $(SRC) 
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC) $(INC) $(INCLUDE_DIRS)
clean :
	rm -f *.o
	rm -f *.d
	rm -f $(OUT_NAME)
