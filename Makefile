TARGET = gglibc_test
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -O3 $(WARNING) $(ERROR)

SRCS = main.c bstree.c slist.c 
LIBS = 
OBJS = $(SRCS:%.c=%.o)

$(TARGET): $(OBJS)
	$(GCC) $(OBJS) $(LIBS) -o $(TARGET)

.c.o:
	$(GCC) -c $*.c

all: $(TARGET)
	./gglibc_test > out.txt
clean:
	rm -f $(OBJS) $(TARGET) out.txt
