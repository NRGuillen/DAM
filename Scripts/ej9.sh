#!/bin/bash

for SUBDIR in test9/*; 

do

    if [ -d "$SUBDIR" ]; then #si en el for, se encuentra un directorio, -d devuelve un "verdadero"

        for archivo in "$SUBDIR"/*.txt; do

        if [ -f "$archivo" ]; then #el -f verifica que el archvo exista 

            head -n 1 "$archivo" #muestra la primera linea del archivo
        fi

        done

    fi

done