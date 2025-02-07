#!/bin/bash

for archivo in test5/*.jpg; do

    mv "$archivo" "${archivo%.jpg}.old"
    echo "Archivo modificado $archivo a ${archivo%.jpg}.old"

done

#${archivo%.jpg} 
#$ -> El dolar elimina la extension .jpg

#"${archivo%.jpg}.old"
#como el $ elimina la extension .jpg, se coloca el .old fuera para reemplazarlo.