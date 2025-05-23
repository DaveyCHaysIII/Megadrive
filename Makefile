.DEFAULT_GOAL = all # makes all the default

# default target
all: brick_breaker pong text_advent ttt #add individual target rule here and uncomment below
	mkdir -pv ./build

# individual targets
brick_breaker:
	$(MAKE) -C brick_breaker

# launcher:
#	$(MAKE) -C launcher

pong:
	$(MAKE) -C pong

# rps:
#	$(MAKE) -C rps

text_advent:
	$(MAKE) -C text-advent

ttt:
	$(MAKE) -C ttt

# Add individual target to PHONY when adding game/program
.PHONY: brick_breaker launcher pong rps text_advent ttt

# to add games/program add the below format to "individual targets"
#
# <game/program>:
#	$(MAKE) -C <game/program folder>
# 
# Then within the game/program folder have a seperate Makefile that makes program
# the formatting for the game/program Makefile should be:
#
# CC = g++
# CPPFLAGS = -L/usr/local/lib/libraylib.a -lraylib -lGL -lGLU -lm -lpthread -ldl -lrt -lX11
# SRC = <SRC file> # enter any other source files here
# BUILD_FILE = ../build
#
# all: <desired program name>
#
# <desired program name>:
#	mkdir -pv $(BUILD_FILE)
#	$(CC) $(SRC) -o $(BUILD_FILE)/$@ $(CPPFLAGS)
