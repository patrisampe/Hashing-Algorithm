#!/bin/bash
make clean
make
for pow in {2..6}
do
	for v in 2 3 4
	do
		for p in 50 70 90 100
		do
			n=$((10**$pow))
			echo ./cercaDicotomica.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt
			./cercaDicotomica.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt 1 >> resultatsQuicksort.txt
			./cercaDicotomica.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt 2 >> resultatsRadix.txt
		done
	done
done
cp resultatsQuicksort.txt resultatsQuicksort.csv
sed -i '1itempsCreacio,tempsHit,tempsMiss,tempsConsulta,compsHit,compsMiss,compsConsulta' resultatsQuicksort.csv
cp resultatsRadix.txt resultatsRadix.csv
sed -i '1itempsCreacio,tempsHit,tempsMiss,tempsConsulta,compsHit,compsMiss,compsConsulta' resultatsRadix.csv