all:
	gcc -Wall -std=gnu11 -o teac main.c `pkg-config --cflags --libs libnotify`

install:
	cp teac /usr/bin

