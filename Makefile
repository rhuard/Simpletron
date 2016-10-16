CC=gcc
OBJECTS= main.c Operations.c simpletron.c assemble.c

all:
	$(CC) $(OBJECTS) -o run

build:
	docker build -t rhuard/simpletron .
