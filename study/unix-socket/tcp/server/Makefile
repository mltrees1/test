CC = gcc
CFLAGS = -g -O0 -W -Wall
LIB_DIRS = -L/usr/lib
INCLUDE_DIRS := -I.
SRC_SERVER=tcp_server.c
INC := 
OUT_SERVER=server.out

$(OUT_SERVER): $(SRC_SERVER) 
	$(CC) $(CFLAGS) -o $(OUT_SERVER) $(SRC_SERVER) $(INC) $(INCLUDE_DIRS)
clean :
	rm -f *.o
	rm -f *.d
	rm -f $(OUT_SERVER)
