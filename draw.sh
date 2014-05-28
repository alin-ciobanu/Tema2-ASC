if [ $(cat ./out/*.o* | wc -w) == 9 ]; then

	echo "Title By_Hand Atlas Optimized" > data.out;
	echo -n "Nehalem " >> data.out;
	echo $(cat ./out/*nehalem.o*) >> data.out;
	echo -n "Opteron " >> data.out;
	echo $(cat ./out/*opteron.o*) >> data.out;
	echo -n "Quad " >> data.out;
	echo $(cat ./out/*quad.o*) >> data.out;

	gnuplot plot.gp;

	rm -r ./out;

else
	echo "Results are not available yet. Please wait until jobs finish.";
fi