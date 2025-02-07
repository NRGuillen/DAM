#!/bin/bash

for archivo in test1/*.txt #bucle for para recorrer todos los archivos

do
	if grep -q '.' "$archivo"; then
		echo "El archivo $archivo NO está vacío."
	else
		echo "El archivo $archivo está vacío."
	fi
done

#grep -> comando para buscar archivos 

#-q -> es una opcion de grep para silenciar los caracteres que encuentra, es decir si 
#encuentra x caracter, sin el -q lo imprimiria en la terminal y con el -q lo silencia apareciendo solo si encontro el archivo

#'.' -> Busca cualquier caracter dentro del archivo, si tiene algun caracter grep devuelve un 0(true)


