CC = g++
CPPFLAGS = -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
SRC = launcher.cpp #enter any other source files here
BUILD_FILE = ../build

all: launcher

launcher:
	mkdir -pv $(BUILD_FILE)
	$(CC) $(SRC) -o $(BUILD_FILE)/$@ $(CPPFLAGS)
