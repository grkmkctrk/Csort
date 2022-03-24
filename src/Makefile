
CC=gcc
CFLAGS=-Wall -g -std=c11

TARGET=sort
OBJECTS=main.o sort.o ll.o

#run
all: clean ${TARGET} run

#run
run: ${TARGET}
	@echo "Running ${TARGET}...\n"
	@./${TARGET}

# sort build
sort: ${OBJECTS}
	@$(CC) $(CFLAGS) -o $@ ../build/*.o


# compile
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ../build/$@

clean:
	@rm -f ../build/*.o  ../build/$(TARGET) 


