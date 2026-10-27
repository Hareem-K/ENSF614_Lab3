ENSF 614 Lab 3 — Exercise B followed by Exercise C

Exercise B:
- iterator.cpp contains the templated Vector<T> and nested VectIter.
- Mystring source files are included here; they are the provided starter implementation.
- Comparison support for Mystring and C strings is implemented in iterator.cpp (string-content comparison).
- Test cases for int, Mystring, and C strings are enabled.
Build from the ExerciseB folder:
  g++ -std=c++11 -Wall -Wextra -pedantic iterator.cpp mystring2.cpp -o exerciseB
  ./exerciseB

Exercise C:
- The templated LookupTable and templated helper functions are in lookupTable.h and mainLab3ExC.cpp.
- It reuses the same mystring2.h and mystring2.cpp files from Exercise B (copied unchanged from the provided starter).
- The C program has its own main; do not compile iterator.cpp alongside mainLab3ExC.cpp.
Build from the ExerciseC folder:
  g++ -std=c++11 -Wall -Wextra -pedantic mainLab3ExC.cpp customer.cpp mystring2.cpp -o lab3_exC
  ./lab3_exC

The output.txt files are captured sample runs. No compiled executables are included.
