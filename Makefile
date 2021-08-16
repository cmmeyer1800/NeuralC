CC=g++
STD = -std=c++11
CFLAGS = -O3
SOURCES = matrices.cpp neural.cpp
OBJECTS=$(SOURCES: .cpp=.o)
EXECUTABLE = net

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE)