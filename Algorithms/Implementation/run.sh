#Sample Run Script for C Colutions
#Implementation Subdirectory
#@author : Varun Patel
rm -rf output.txt
gcc -o sockMerchant sockMerchant.c
./sockMerchant < input.txt >> output.txt
open output.txt
