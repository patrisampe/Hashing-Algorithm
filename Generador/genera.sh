#!/bin/bash
make clean
make       
for pow in {2..5}
do
	for V in 2 3 4
	do
		for P in 50 70 90 100
		do
			N=$((10**$pow))
			./generador.exe $N $V $P dict-$N-$V-$P text-$N-$V-$P 1234
		done
	done
done
