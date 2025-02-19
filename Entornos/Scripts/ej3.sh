# Recorre todos los archivos que contengan "log" en su nombre dentro de test3/
for archivo in test3/*.txt
do

  if grep -q "ERROR" "$archivo"; then
    echo "En el log $archivo hay errores"
  else
    echo "En el log $archivo no hay errores"
  fi
done

#grep -> comando para buscar archivos 

#-q -> es una opcion de grep para silenciar los caracteres que encuentra, es decir si 
#encuentra ERROR, sin el -q  imprimiria en la terminal la linea completa y con el -q lo silencia apareciendo solo si tiene errores