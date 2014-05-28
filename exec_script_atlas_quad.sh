#!/bin/bash

[[ -z $COMPILER ]] && COMPILER="gcc"

make atlas -f Makefile_quad &> /dev/null;
if [[ $COMPILER="gcc" ]]; then
	./atlas_quad 30000
fi
make clean_atlas -f Makefile_quad &> /dev/null;
