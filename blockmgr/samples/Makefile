CC      := gcc
CFLAGS  := -fPIC -g -I../include -Werror=implicit-function-declaration
LDFLAGS := -L../libs

all:disklist

%.o: %.c Makefile
	$(CC) -c -o $@ $< $(CFLAGS) $(CLIBFLAGS) -O2


disklist: diskList.o 
	$(CC) -o disklist diskList.o $(LDFLAGS) -lblockmgr -lpthread

clean:
	rm -f *.o
	rm -f disklist
