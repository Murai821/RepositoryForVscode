set terminal png size 500,500
set output 'points.png'
set xrange [0:100]
set yrange [0:100]
set title 'Random Points'
plot 'points.dat' using 1:2 with points pt 7 ps 2 lc rgb 'blue' notitle
