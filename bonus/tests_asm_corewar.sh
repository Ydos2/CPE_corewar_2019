#!/bin/bash

cp ../asm/asm ./asm

./asm ./src/test_file.s
diff -s src/test_file.cor ./test_file.cor
rm src/test_file.cor

./asm ./src/abel.s
diff -s src/abel.cor ./abel.cor
rm src/abel.cor

./asm ./src/bill.s
diff -s src/bill.cor ./bill.cor
rm src/bill.cor

./asm ./src/pdd.s
diff -s src/pdd.cor ./pdd.cor
rm src/pdd.cor

./asm ./src/tyron.s
diff -s src/tyron.cor ./tyron.cor
rm src/tyron.cor

rm ./asm