# Makefile del proyecto de algoritmos en C++
# Uso:
#   make        -> compila el programa (genera ./algoritmos)
#   make run    -> compila y ejecuta
#   make test   -> compila y ejecuta las pruebas (./pruebas)
#   make clean  -> borra los ejecutables

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = algoritmos
SRC = main.cpp
TEST = pruebas
TEST_SRC = pruebas.cpp
HEADERS = ordenamientos.h busquedas.h estructuras.h grafos.h dinamica.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

$(TEST): $(TEST_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST) $(TEST_SRC)

test: $(TEST)
	./$(TEST)

clean:
	rm -f $(TARGET) $(TEST)

.PHONY: all run test clean
