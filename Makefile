CC=g++
CFLAGS= -Wall -Wextra -pedantic -O3 -ansi
SOURCES=main.cpp triangle.cpp
OBJECTS=$(SOURCES:.cpp=.o)
.PRECIOUS: test.o $(SOURCES:.cpp=_test.o)
EXECUTABLE=main

all: $(EXECUTABLE)

-include $(SOURCES:.cpp=.d) test.d

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%_test: %_test.o %.o test.o
	$(CC) $(CFLAGS) $*_test.o $*.o test.o -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -MM $< > $*.d

clean:
	rm -f *.o $(EXECUTABLE) *_test *.pyc *.auto *.d
