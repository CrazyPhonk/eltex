#!/bin/bash
count=$(cat "count.txt")
((count-=3))
echo "$count" > "count.txt"
pids=$(ps aux | grep sleep | awk '{print $2}')
kill $pids
