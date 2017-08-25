#Sample Run Script for C Colutions
#Warmup Subdirectory
#@author : Varun Patel
rm -rf output.txt
gcc -o staircase staircase.c
./staircase < input.txt >> output.txt
open output.txt
