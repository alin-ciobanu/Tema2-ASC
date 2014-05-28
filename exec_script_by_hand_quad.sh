#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

make by_hand -f Makefile_quad &> /dev/null;
if [[ $COMPILER="gcc" ]]; then
	./by_hand_quad 30000
fi
make clean_by_hand -f Makefile_quad &> /dev/null;
