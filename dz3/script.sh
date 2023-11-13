#!/bin/bash
num_processes=5

for ((i=1; i<=num_processes; i++))
do
  sleep 10 & 
  pid=$!
  echo "PID: $pid"
done

wait
echo $num_processes > processed.txt
sleep 3600
