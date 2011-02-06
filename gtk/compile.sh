#!/bin/bash
gcc -g -Wall `pkg-config --cflags --libs gtk+-2.0` -c gtkpasswordentry.c
gcc -g -Wall `pkg-config --cflags --libs gtk+-2.0` -o gpe_test gpe_test.c gtkpasswordentry.o
