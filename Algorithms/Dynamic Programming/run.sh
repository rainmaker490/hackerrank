#Sample Run Script for C Colutions
#Dynamic Programming Subdirectory
#@author : Varun Patel
rm -rf output.txt
gcc -o theLongestIncreasingSubsequence theLongestIncreasingSubsequence.c
./theLongestIncreasingSubsequence < input.txt >> output.txt
open output.txt
