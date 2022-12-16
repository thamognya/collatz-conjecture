
# ------------------------------------------------
# Makefile for collatz
#
# Author: Thamognya Kodi <contact@thamognya.com>
#
# ------------------------------------------------

# Variables

OPTIONS= -W -Wall -Werror -Wextra -Weffc++ -pedantic -std=c++2b
CXX = g++
TARGET = ./src/main.cpp
SOURCE = ./bin/collatz

$(TARGET): $(SOURCE)
	${CXX} ${OPTIONS} ${TARGET} -o ${SOURCE}
