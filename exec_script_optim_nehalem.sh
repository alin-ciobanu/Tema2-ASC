#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

make optim -f Makefile_nehalem &> /dev/null;
if [[ $COMPILER="gcc" ]]; then
	./optim_gcc 30000
fi
make clean_optim -f Makefile_nehalem  &> /dev/null;
