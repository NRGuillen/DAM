#!/bin/bash

for USUARIO in $(cat test8/usuarios.txt); #Bucle for que recorre todas las lineas

do

    if [ "$USUARIO" == "maria" ]; then #si en una linea el usuario se llama maria, hola maria
        echo "Hola maria"
    else #si no es maria, hola y el nombre del usuario en la linea que este
        echo "Hola, $USUARIO"
    fi

done
 