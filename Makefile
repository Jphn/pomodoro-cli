# Files
TARGET = main

# Flags
WFLAGS = -Wall -Wextra -Werror

all:
	@if [ ! -d "./build/" ]; \
	then mkdir build; \
	mkdir build/bin; \
	mkdir build/obj; fi
	
	make all.o

	gcc $(WFLAGS) \
	build/obj/*.o \
	-o build/bin/$(TARGET)

all.o:
	make clean

	gcc $(WFLAGS) -c \
	src/*.c
	mv *.o build/obj

clean:
	rm -rf build/obj/*.o

hardclean:
	rm -r build/
	
run:
	build/bin/$(TARGET)