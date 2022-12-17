OPTIONS= -W -Wall -Werror -Wextra -Weffc++ -pedantic -std=c++2b
CXX = g++ $(OPTIONS)
TARGET = ./src/main.cpp
SOURCE = ./bin/collatz
BIN = ./bin/*
RM = rm -rf

$(TARGET): $(SOURCE)
	$(CXX) $(TARGET) -o $(SOURCE)
	@echo "Compile Done"

.PHONY: clean
clean:
	$(RM) $(BIN)
	@echo "Cleanup complete!"

