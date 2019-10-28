CC=g++
FLAG=-g

all: book1 book46 book113 book242 book245 book246 book247 book248 book249 book81 book255 book260 book236\
     tcpserver tcpclient

book1:book1.c
	$(CC) $(FLAG) -o book1 book1.c

book81:book81.c
	$(CC) $(FLAG) -o book81 book81.c

book46:book46.c _public.h _public.c
	$(CC) $(FLAG) -o book46 book46.c _public.c

book113:book113.c
	$(CC) $(FLAG) -o book113 book113.c

book242:book242.cpp
	$(CC) $(FLAG) -o book242 book242.cpp

book241:book241.cpp
	$(CC) $(FLAG) -o book241 book241.cpp

book245:book245.cpp
	$(CC) $(FLAG) -o book245 book245.cpp

book246:book246.cpp
	$(CC) $(FLAG) -o book246 book246.cpp

book247:book247.cpp
	$(CC) $(FLAG) -o book247 book247.cpp

book248:book248.cpp
	$(CC) $(FLAG) -o book248 book248.cpp

book249:book249.cpp
	$(CC) $(FLAG) -o book249 book249.cpp

book255:book255.cpp
	$(CC) $(FLAG) -o book255 book255.cpp

book260:book260.cpp
	$(CC) $(FLAG) -o book260 book260.cpp -lpthread

book261:book261.cpp
	$(CC) $(FLAG) -o book261 book261.cpp -lpthread

book210:book210.cpp
	$(CC) $(FLAG) -o book210 book210.cpp 

book236:book236.cpp
	$(CC) $(FLAG) -o book236 book236.cpp 

tcpserver:tcpserver.cpp
	$(CC) $(FLAG) -o tcpserver tcpserver.cpp 

tcpclient:tcpclient.cpp
	$(CC) $(FLAG) -o tcpclient tcpclient.cpp 

clean:
	rm  -f book1 book46



