#!/bin/bash
output_file="count.txt"
echo "0" > "$output_file"
child_process() {
    sleep 10
    count=$(cat "$output_file")
    ((count++))
    echo "$count" > "$output_file"
}
for i in {1..5}; do
    child_process &
done
wait
sleep 3600
