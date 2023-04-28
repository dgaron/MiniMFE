CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = external_functions.o

TASKS = v1 readable verbose Nmem tile 
PLAIN_TARGETS = $(TASKS:%=MiniMFE-%)
CHECK_TARGETS = $(PLAIN_TARGETS:%=%.check)
VERIFY_TARGETS = $(PLAIN_TARGETS:%=%.verify)
VERIFY_RAND_TARGETS = $(PLAIN_TARGETS:%=%.verify-rand)

all: bin external_functions.o MiniMFE_verify.o $(PLAIN_TARGETS) $(CHECK_TARGETS) $(VERIFY_TARGETS) $(VERIFY_RAND_TARGETS)

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
MiniMFE-%: MiniMFE-%.o $(OBJS)
	$(CC) MiniMFE-wrapper.c -o bin/$@ $(^:%=bin/%) $(CFLAGS) $(LIBRARIES)

MiniMFE-%.check: MiniMFE-%.o $(OBJS)
	$(CC) MiniMFE-wrapper.c -o bin/$@ $(^:%=bin/%) $(CFLAGS) $(LIBRARIES) -DCHECKING

MiniMFE-%.verify: MiniMFE_verify.o MiniMFE-%.o $(OBJS)
	$(CC) MiniMFE-wrapper.c -o bin/$@ $(^:%=bin/%) $(CFLAGS) $(LIBRARIES) -DVERIFY

MiniMFE-%.verify-rand: MiniMFE_verify.o MiniMFE-%.o $(OBJS)
	$(CC) MiniMFE-wrapper.c -o bin/$@ $(^:%=bin/%) $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

MiniMFE-%.o : MiniMFE-%.c
	$(CC) $< -o bin/$@ $(CFLAGS) $(LIBRARIES) -c

MiniMFE_verify.o : MiniMFE_verify.c
	$(CC) MiniMFE_verify.c -o bin/MiniMFE_verify.o $(CFLAGS) $(LIBRARIES) -c

external_functions.o: external_functions.c
	$(CC) external_functions.c -o bin/external_functions.o $(CFLAGS) $(LIBRARIES) -c

tar:
	tar -cvf MiniMFE.tar *.h *.c

bin:
	mkdir -p bin

clean:
	rm -f bin/*	
	rmdir bin