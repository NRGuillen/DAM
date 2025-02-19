#!/bin/bash


ps aux >> processes.txt #guarda toda la lista en el archvo processes.txt


for PROC in $(cat processes.txt)
do

    if ps aux | grep -q "$PROC"; then #ps aux -> nos permite ver todos los procesos, -q sirve para que grep no imprima nada en la salida, solo 0 o 1(verdadero o falso)
        echo "El proceso '$PROC' está en ejecución"
    else
        echo "El proceso '$PROC' no está en ejecución"
    fi
done
