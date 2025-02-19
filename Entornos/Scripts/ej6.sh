#!/bin/bash

for archivo in test6/*.txt; 

do

    TOTAL_LINEAS=$(grep -c '^' "$archivo")


    if (( TOTAL_LINEAS > 3 )); then
        echo "El archivo $archivo tiene más de 3 líneas"
    else
        echo "El archivo $archivo tiene 3 líneas o menos"
    fi

done

#grep -> comando para buscar texto 

#-c -> indica a grep que cuente las lineas con el patron '^'

#'^' -> cualquier linea que tenga algo al principio.


