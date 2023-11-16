CC=gcc
CFLAGS=-I.
DEPS = count.h
OBJ = main.o count.o
TEST_OBJ = test_count.o count.o

%.o: %.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

test_count: $(TEST_OBJ)
    $(CC) -o $@ $^ $(CFLAGS) -lcriterion

.PHONY: clean

clean:
    rm -f *.o main test_count