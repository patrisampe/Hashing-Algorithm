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
			echo ./bloom.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt
			./bloom.exe ../Generador/dict-$n-$v-$p.txt ../Generador/text-$n-$v-$p.txt $n $v $p>> resultatbloomsensemv2.txt
		done
	done
done
cp resultatbloomsensemv2.txt resultatbloomsensemv2.csv
sed -i '1itempsCreacio,tempsbuscar,encerts,fallos,comp,h1,h2,h3' resultatbloomsensemv2.csv