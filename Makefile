SUBDIRS = src lib 
OBJECTS = main.o enter_data.o

vpath %.c src:lib
vpath %.h include
vpath %.o src:lib

CC:=gcc
CFLAGS+= -O2 -Wall -pedantic -ansi
LDFLAGS+= -ldl -lncurses

.PHONY: subdirs $(SUBDIRS)

all: $(OBJECTS)
		$(CC) -o calculator $^ $(LDFLAGS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
		$(MAKE) -C $@

src: lib

