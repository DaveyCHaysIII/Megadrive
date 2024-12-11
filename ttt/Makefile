CC = g++
CPPFLAGS = -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
SRC = # enter source files here
BUILD_FILE = ../build

all: tictactoe

tictactoe:
	mkdir -pv $(BUILD_FILE)
	$(CC) $(SRC) -o $(BUILD_FILE)/$@ $(CPPFLAGS)
