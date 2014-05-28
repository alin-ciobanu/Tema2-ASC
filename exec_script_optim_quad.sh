#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

make optim -f Makefile_quad &> /dev/null;
if [[ $COMPILER="gcc" ]]; then
	./optim_quad 30000
fi
make clean_optim -f Makefile_quad  &> /dev/null;
