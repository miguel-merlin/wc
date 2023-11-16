CC=gcc
CFLAGS=-Iinclude
DEPS = include/count.h
OBJ = src/main.o src/count.o
TEST_OBJ = tests/test_count.o src/count.o

src/%.o: src/%.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

tests/%.o: tests/%.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

test_count: $(TEST_OBJ)
    $(CC) -o $@ $^ $(CFLAGS) -lcriterion

.PHONY: clean

clean:
    rm -f src/*.o tests/*.o main test_count