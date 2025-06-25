
COMPILER=g++
CFLAGS=-Wall -Wextra -std=c++17
TARGET=main
SOURCEDIR=.
COREDIR=core
DATADIR=data
UIDIR=ui
UTILSDIR=utils

SOURCES=$(wildcard $(SOURCEDIR)/*.cpp) \
        $(wildcard $(COREDIR)/*.cpp) \
        $(wildcard $(DATADIR)/*.cpp) \
        $(wildcard $(UIDIR)/*.cpp) \
        $(wildcard $(UTILSDIR)/*.cpp)

OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(TARGET)-debug: $(SOURCES)
	$(COMPILER) $(CFLAGS) -g $(SOURCES) -o $(TARGET)-debug

clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET)-debug

.PHONY: all clean
