CC = g++
CPPFLAGS = -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
SRC = #insert source files here
BUILD_FILE = ../build

all: rps

rps:
	mkdir -pv $(BUILD_FILE)
	$(CC) $(SRC) -o $(BUILD_FILE)/$@ $(CPPFLAGS)
