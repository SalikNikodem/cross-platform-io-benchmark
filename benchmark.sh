#!/bin/bash

PROGRAM=$1
MODE=$2
IN1="big_file1.bin"
IN2="big_file2.bin"
OUT="output_bench.bin"

if [ -z "$PROGRAM" ] || [ -z "$MODE" ]; then
    echo "Użycie: $0 <nazwa_programu> <tryb_mode>"
    exit 1
fi

echo "Uruchamiam 10 pomiarów dla $PROGRAM w trybie (Mode $MODE)..."
for i in {1..10}
do
    rm -f $OUT
    
    (time ./$PROGRAM $MODE $IN1 $IN2 $OUT) 2>&1 | grep -E 'real|user|sys'
done