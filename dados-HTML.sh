#!/bin/bash

while [ 1 ]; do
	wget http://192.168.1.177
	dia=`cat index.html | tail -n2 | head -1 | cut -c 1-2`
	dia=$((dia-10))
	
	hora=`cat index.html | tail -n2 | head -1 | cut -c 4-5`
	hora=$((hora-10))

	minuto=`cat index.html | tail -n2 | head -1 | cut -c 7-8`
	minuto=$((minuto-10))
	
	nivelRio=`cat index.html | tail -n2 | head -1 | cut -c 10`
	if [ $nivelRio = "Z" ]
	then
		nivelRio=0
	elif [ $nivelRio = "B" ]
	then
		nivelRio=1
	elif [ $nivelRio = "X" ]
	then
		nivelRio=2
	fi

	alerta=`cat index.html | tail -n2 | head -1 | cut -c 12`
	if [ $alerta -eq 3 ]
	then
		alerta="S"
	elif [ $alerta -eq 4 ] || [ $alerta -eq 7 ]
	then
		alerta="N"
	fi

	if [ $nivelRio -ge 1 ]
	then
		echo "$dia,$hora:$minuto,$nivelRio,$alerta,---ALERT---" >> Relatorio/relatorio.csv
	else
		echo "$dia,$hora:$minuto,$nivelRio,$alerta" >> Relatorio/relatorio.csv
	fi

	rm index.html

	sleep 5
done
