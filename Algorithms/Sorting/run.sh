#Sample Run Script for C Colutions
#Sorting Subdirectory
#@author : Varun Patel
rm -rf output.txt
gcc -o theFullCountingSort theFullCountingSort.c
./theFullCountingSort < input.txt >> output.txt
open output.txt
