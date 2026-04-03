CC=g++
CXXFLAGS=-std=c++17 -O2 -Wall -fPIC
SRC=lib/MemoryManager.cpp
LIBDIR=lib
LIBNAME=$(LIBDIR)/libMemoryManager.so
TEST_SOURCES=$(wildcard tests/*.cpp)
OUT=mm_test

.PHONY: all lib clean run

all: lib $(OUT)

lib: $(LIBNAME)

$(LIBNAME): $(SRC)
	$(CC) $(CXXFLAGS) -shared -o $(LIBNAME) $(SRC)

$(OUT): $(TEST_SOURCES) $(LIBNAME)
	$(CC) $(CXXFLAGS) -o $(OUT) $(TEST_SOURCES) -L$(LIBDIR) -lMemoryManager -Wl,-rpath,'$$ORIGIN/$(LIBDIR)'

run: $(OUT)
	LD_LIBRARY_PATH=./$(LIBDIR) ./$(OUT)

clean:
	rm -f $(OUT) $(LIBNAME)