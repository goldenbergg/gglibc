TARGET = gglibc_test
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -O3 $(WARNING) $(ERROR)

SRCS = main.c slist.c
LIBS = 
OBJS = $(SRCS:%.c=%.o)

$(TARGET): $(OBJS)
	$(GCC) $(OBJS) $(LIBS) -o $(TARGET)

.c.o:
	$(GCC) -c $*.c

all: $(TARGET)
	./gglibc_test
clean:
	rm -f $(OBJS) $(TARGET)
	