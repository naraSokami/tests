#!/bin/bash
valgrind --leak-check=summary "$@" 2>&1 \
  | awk '/definitely lost:/ {print $4}'