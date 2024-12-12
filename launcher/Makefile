CC = g++
CPPFLAGS = -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
LSRC = main.cpp #enter any other source files here
GSRC = game.cpp
BUILD_FILE = ../build

all: launcher gameexample

launcher:
	mkdir -pv $(BUILD_FILE)
	$(CC) $(LSRC) -o $(BUILD_FILE)/$@ $(CPPFLAGS)

gameexample:
	mkdir -pv $(BUILD_FILE)
	$(CC) $(GSRC) -o $(BUILD_FILE)/$@ $(CPPFLAGS)
