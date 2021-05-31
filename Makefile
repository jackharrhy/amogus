all: clean amogus

amogus:
	gcc -Wall amogus.c `pkg-config fuse --cflags --libs` -g -o amogus

clean:
	-rm ./amogus
