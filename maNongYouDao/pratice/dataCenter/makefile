CC = g++
FLAG = -g

all: crtsurfdata libftp.a demo18 ftpgetfile

libftp.a:ftplib.c
	gcc -c -o libftp.a ftplib.c

demo18:demo18.cpp _ftp.h _ftp.cpp libftp.a
	g++ $(FLAG) -o demo18 demo18.cpp _public.cpp _ftp.cpp libftp.a -lm -lc
	cp demo18 ../bin/

ftpgetfile:ftpgetfile.cpp _ftp.h _ftp.cpp libftp.a
	g++ $(FLAG) -o ftpgetfile ftpgetfile.cpp _public.cpp _ftp.cpp libftp.a -lm -lc
	cp ftpgetfile ../bin/

crtsurfdata:crtsurfdata.cpp _public.cpp
	$(CC) $(FLAG) -o crtsurfdata crtsurfdata.cpp _public.cpp
	cp crtsurfdata ../bin/.

clean:
	rm  crtsurfdata
