#!/bin/bash

#wc -l = contar as linha
#tamanho = linhas totais do arquivo
	#tamanho=`cat Dados.txt | wc -l`

#tail -n(numero da linha de baixo para cima)
#head -n 1 pega só uma linha
#d recebe o conteudo de toda a linha
	#d=`cat Dados.txt | tail -n1 | head -n 1`

#cut corta a informação, nessa caso pega só o primeiro e segundo caractere
#dia recebe d(linha total) e corta ela com o cut
	#dia=`echo $d | cut -c 1-2`

#echo escreve
	#echo $dia


while [ 1 ]; do
	wget http://192.168.1.177
	dia=`cat index.html | tail -n2 | head -1 | cut -c 1-2`
	dia=$((dia-10))
	
	hora=`cat index.html | tail -n2 | head -1 | cut -c 4-5`
	hora=$((hora-10))

	minuto=`cat index.html | tail -n2 | head -1 | cut -c 7-8`
	minuto=$((minuto-10))
	
	nivelRio=`cat index.html | tail -n2 | head -1 | cut -c 10`
	alerta=`cat index.html | tail -n2 | head -1 | cut -c 12`

	if [ alerta -ge 1 ]
	then
		echo "$dia,$hora:$minuto,$nivelRio,$alerta,---ALERT---" >> relatorio.csv
	else
		echo "$dia,$hora:$minuto,$nivelRio,$alerta" >> relatorio.csv
	fi

	rm index.html

	sleep 5
done
