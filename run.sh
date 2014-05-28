#!/bin/bash

rm -r ./out

mprun.sh --job-name exec2_atlas_nehalem --queue ibm-nehalem.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-nehalem" \
	--script exec_script_atlas_nehalem.sh --show-qsub --show-script --batch-job
mprun.sh --job-name exec1_by_hand_nehalem --queue ibm-nehalem.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-nehalem" \
	--script exec_script_by_hand_nehalem.sh --show-qsub --show-script --batch-job
mprun.sh --job-name exec3_optim_nehalem --queue ibm-nehalem.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-nehalem" \
	--script exec_script_optim_nehalem.sh --show-qsub --show-script --batch-job

mprun.sh --job-name exec3_optim_opteron --queue ibm-opteron.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-opteron" \
	--script exec_script_optim_opteron.sh --show-qsub --show-script --batch-job
mprun.sh --job-name exec1_by_hand_opteron --queue ibm-opteron.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-opteron" \
	--script exec_script_by_hand_opteron.sh --show-qsub --show-script --batch-job
mprun.sh --job-name exec2_atlas_opteron --queue ibm-opteron.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-opteron" \
	--script exec_script_atlas_opteron.sh --show-qsub --show-script --batch-job

mprun.sh --job-name exec3_optim_quad --queue ibm-quad.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-quad" \
	--script exec_script_optim_quad.sh --show-qsub --show-script --batch-job
mprun.sh --job-name exec1_by_hand_quad --queue ibm-quad.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-quad" \
	--script exec_script_by_hand_quad.sh --show-qsub --show-script --batch-job
mprun.sh --job-name exec2_atlas_quad --queue ibm-quad.q \
	--modules "libraries/atlas-3.10.1-gcc-4.4.6-quad" \
	--script exec_script_atlas_quad.sh --show-qsub --show-script --batch-job
