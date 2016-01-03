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
			echo ./cercaDicotomica.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt
			./cercaDicotomica.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt >> resultats.txt
		done
	done
done
cp resultats.txt resultats.csv
sed -i '1itempsCreacio,tempsHit,tempsMiss,compsHit,compsMiss' resultats.csv