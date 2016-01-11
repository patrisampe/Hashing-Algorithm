#!/bin/bash
make clean
make
for pow in {2..5}
do
	for v in 2 3 4
	do
		for p in 50 70 90 100
		do
			n=$((10**$pow))
			echo ./hash.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt
			./hash.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt $n $v $p>> resultatshmv3.txt
		done
	done
done
cp resultatshmv3.txt resultatsmv3.csv
sed -i '1itempsCreacio,tempsbuscar,encerts,fallos,compbo,compdolent,tempscomp,tempshash' resultatsmv3.csv