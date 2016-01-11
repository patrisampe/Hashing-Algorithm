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
			echo ./cercaTotal.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt
			./cercaTotal.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt 1 $n $v $p>> resultatsQuicksort.txt
			./cercaTotal.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt 2 $n $v $p>> resultatsRadix.txt
		done
	done
done
cp resultatsQuicksort.txt resultatsQuicksortv2.csv
sed -i '1in,v,t,tempsCreacio,tempsConsulta,compsConsulta' resultatsQuicksort.csv
cp resultatsRadix.txt resultatsRadixv2.csv
sed -i '1in,v,t,tempsCreacio,tempsConsulta,compsConsulta' resultatsRadix.csv
