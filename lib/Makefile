SOURCES = add.c  mul.c sub.c div.c enter_data.c print_result.c
OBJECTS =$(SOURCES:.c=.o)
LIBS = $(addprefix lib, $(SOURCES:.c=.so))

all:$(LIBS)
			
lib%.so: %.o	
		echo $@ - $<
		gcc -shared $< -o $@

%.o: %.c
		gcc -c $< -fPIC -g

.PHONY: clean

clean:
		rm -rf *.so

