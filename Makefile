 make main
cc     main.c   -o main
ld: Undefined symbols:
  _count_characters, referenced from:
      _main in main-a2044f.o
  _count_lines, referenced from:
      _main in main-a2044f.o
  _count_words, referenced from:
      _main in main-a2044f.o
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [main] Error 1