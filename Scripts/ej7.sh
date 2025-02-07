#!/bin/bash

for archivo in test7/*; 

do

    if [[ "$archivo" == *.conf ]]; then

        sed -i 's/localhost/127.0.0.1/g' "$archivo"

        echo "El archivo $archivo ha sido modificado."
    fi

done

#[[ "$archivo" == *.conf ]] -> comprueba que el archvo tenga la extension que necesitamos, .conf

#sed -i 's/localhost/127.0.0.1/g' "$archivo" 
#sed -> edita texto
#'s/localhost/127.0.0.1/g' sed reemplazara "localhost" por "127.0.0.1".
#-i -> hace que sed edite el archivo directamente, es decir va a modificar el archivo real, sin el -i solo lo mostraria en la terminal pero el archivo no estaria modificado
#/g -> significa reemplazo global en cada linea, no solo en la primera 
