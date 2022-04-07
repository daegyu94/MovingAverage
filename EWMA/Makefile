.SUFFIXES : .c .o

CC = g++
CFLAGS = -g -I -O2
WARNING = -Wall -Wextra -Wconversion -pedantic
INC =
LIBS =

OBJECTS = main.o

TARGET = main.out

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean :
	rm -rf $(OBJECTS) $(TARGET) core

new :
	$(MAKE) clean
	$(MAKE)
