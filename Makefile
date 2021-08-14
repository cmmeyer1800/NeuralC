CC=gcc
dev_flags = -Wall -Wextra -Og
prod_flags = -O3
std = -std=c11

net: net.c net.h
	$(CC) $(std) $(prod_flags) -o net net.c net.h

clean:
	rm net

test:
	$(CC) $(std) $(dev_flags) -o net net.c net.h