CC = g++
CPPFLAGS = -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
SRC = main.cpp # enter source files here

all: shadertest

shadertest:
	$(CC) $(SRC) -o $@ $(CPPFLAGS)
