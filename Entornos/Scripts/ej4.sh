#!/bin/bash

for (( i=1; i<=5; i++ ))

do
  
  if (( i == 3 )); then #cuando i tenga el valor de 3, imprimira echo
    echo "Numero 3 saltado."
    continue
  fi

  echo "i = $i"

done
