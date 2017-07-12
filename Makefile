ifeq "$(PLATFORM)" ""
PLATFORM := $(shell uname)
endif

ifeq "$(PLATFORM)" "Darwin"
# If you are comiling on Mac Please uncomment the following line
# And install gcc from Macport:
CC=/opt/local/bin/gcc-mp-4.9
else
CC=cc
EXTRA_FLAGS := -lrt
endif

CFLAGS=-c -O2 -Wall 
STD_FLAGS=

all: build_everything 

build_everything: ccpal_example.c 
	$(CC) ccpal_example.c -o ccpal_example $(STD_FLAGS) $(EXTRA_FLAGS) 

clean:
	rm -rf *.o

