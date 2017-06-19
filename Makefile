SUBDIRS = src lib 
OBJECTS = calc.o my_complex.o

vpath %.c src:lib
vpath %.h include
vpath %.o src:lib

CC:=gcc
CFLAGS+=
LDFLAGS+=-lncurses

.PHONY: subdirs $(SUBDIRS)

all: $(OBJECTS)
		$(CC) -o calculator $^ $(LDFLAGS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
		$(MAKE) -C $@

src: lib

