GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
VAL = valgrind --tool=memcheck --log-file=valgrind.log --leak-check=full --show-reachable=yes --verbose  --track-origins=yes
TESTFLAGS = -DTEST_MAIN
SRCS = sorting.c pa5.c #UPDATE WITH MORE FILES
OBJS = $(SRCS:%.c=%.o)

PA5: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o pa5

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

VAL: pa5
	$(VAL) ./pa5 -m examples/5.b 5.out

clean:
	rm -f *.o *.txt *.b valgrind.log pa5
	clear
