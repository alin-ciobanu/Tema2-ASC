#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

make atlas -f Makefile_opteron &> /dev/null;
if [[ $COMPILER="gcc" ]]; then
	./atlas_opteron 30000
fi
make clean_atlas -f Makefile_opteron &> /dev/null;
