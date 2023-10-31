#!/bin/bash

val1=4
val2=14
for ((i = 1; i <= 20; i++))
do
if [[ $i -ne $val1 ]] && [[ $i -ne $val2 ]]; then
rm file${i}.txt
fi
if [[ $i -eq 14 ]]; then
echo "Something" >> file${i}.txt
fi
done
