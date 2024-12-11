CC = g++
CPPFLAGS = -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
SRC = main.cpp # enter source files here
BUILD_FILE = ../build

all: ttt

ttt:
	mkdir -pv $(BUILD_FILE)
	$(CC) $(SRC) -o $(BUILD_FILE)/$@ $(CPPFLAGS)
