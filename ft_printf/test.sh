#!/bin/sh
make
cc -Wall -Wextra -Werror tests/main.c -lftprintf -L. -o test -I .
python3 tests/test.py
