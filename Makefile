# Makefile del proyecto de algoritmos en C++
# Uso:
#   make        -> compila el programa (genera ./algoritmos)
#   make run    -> compila y ejecuta
#   make clean  -> borra el ejecutable

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = algoritmos
SRC = main.cpp
HEADERS = ordenamientos.h busquedas.h estructuras.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
