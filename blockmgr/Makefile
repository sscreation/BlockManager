CC      := gcc
CFLAGS  := -fPIC -g -I../ -Werror=implicit-function-declaration -O2

LOCAL_CFLAGS := $(CFLAGS) -I../

all:libblockmgr.a libblockmgr.so

SRC:=fileops.c blockmgr.c transact.c hash.c platformops.c morphdb.c btreekeyops.c skiplist.o

HDRS:=$(ls *.h)
OBJS:=$(patsubst %.c,%.o,$(SRC))

TGTDIR := /usr/local

ifdef INSTALLDIR 
	TGTDIR=$(INSTALLDIR)
endif


%.o: %.c Makefile $(HDRS)
	$(CC) -c -o $@ $< $(LOCAL_CFLAGS) $(CLIBFLAGS)


libblockmgr.a:$(OBJS) $(HDRS)
	ar rcs libblockmgr.a $(OBJS)
	cp libblockmgr.a libs

libblockmgr.so:$(OBJS)
	gcc -shared -o libblockmgr.so $(OBJS)
	cp libblockmgr.so libs

hdrs:
	cp blockmgr.h blockmgrerror.h stringutil.h include/

install:libblockmgr.a libblockmgr.so hdrs
	mkdir -p $(TGTDIR)/include/blockmgr
	mkdir -p $(TGTDIR)/libs/
	cp ./libs/* $(TGTDIR)/libs
	cp ./include/* $(TGTDIR)/include/blockmgr
	

clean:
	rm -f *.a
	rm -f *.o
	rm -f *~
	rm -f *.so
