#!/bin/bash

for ((i=1; i<=20; i++))
do
touch file${i}.txt
echo file${i} >> file${i}.txt
done
