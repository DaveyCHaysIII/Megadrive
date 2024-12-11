.DEFAULT_GOAL = all # makes all the default

# default target
all: launcher pong rps text_advent ttt
	mkdir -pv ./build

# individual targets
launcher:
	$(MAKE) -C launcher

pong:
	$(MAKE) -C pong

rps:
	$(MAKE) -C rps

text_advent:
	$(MAKE) -C text-advent

ttt:
	$(MAKE) -C ttt

.PHONY: launcher pong rps text_advent ttt
