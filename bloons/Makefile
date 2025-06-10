CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
LDFLAGS := -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
TARGET := bloons

.PHONY: all clean

all:
	$(CXX) $(CXXFLAGS) *.cpp -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
