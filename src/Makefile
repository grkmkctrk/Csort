# Makefile for the GNU C compiler
# Copyright (C) 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
# 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012 Free Software
# Foundation, Inc.
# This file is part of GNU CC.

TARGET	:= sort
OBJ 	:= main.o sort.o ll.o

CC	:= gcc
CFLAGS 	:= -Wall -Werror


all: clean $(TARGET) run

run:
	@../build/$(TARGET)

sort: $(OBJ)
	@$(CC) $(CFLAGS) -o ../build/$@ ../build/*.o
	@echo "Build complete"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ../build/$@

clean:
	@rm -f ../build/*.o  ../build/$(TARGET) 


