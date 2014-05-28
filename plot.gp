set title "Results"
By_Hand = "#99ffff"; Atlas = "#4677dd"; Optimized="#ff00000"
set auto x
set auto y
set style data histogram
set style fill solid border 0
set boxwidth 1
set xtic scale 0
set term png
set output 'graph.png'
plot 'data.out' using 2:xtic(1) ti col, '' u 3 ti col, '' u 4 ti col
