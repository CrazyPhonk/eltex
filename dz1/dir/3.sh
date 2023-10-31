#!/bin/bash
echo "Enter folder count"
read count
for ((i=1; i<=3; i++))
do
for ((j=1; j<=${count}; j++))
do
mkdir ${i}
cd ${i}
done
touch file${i}.txt
ln -sf file${i}.txt /home/egor/eltex/dz1/dir/link_file${i}.txt
for ((k=1; k<=${count}; k++))
do
cd ../
done
done

