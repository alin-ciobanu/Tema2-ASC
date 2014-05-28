#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

make atlas -f Makefile_nehalem &> /dev/null;
if [[ $COMPILER="gcc" ]]; then
	./atlas_gcc 30000
fi
make clean_atlas -f Makefile_nehalem &> /dev/null;
