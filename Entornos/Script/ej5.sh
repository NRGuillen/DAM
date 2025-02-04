#!/bin/bash


for archivo in *.jpg
	
do
  mv "$archivo" "${archivo%.jpg}.old"
done

