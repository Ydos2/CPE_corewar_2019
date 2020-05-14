#!/bin/bash

cp ../asm/asm ./asm

./asm ./src/test_file.s
chmod 777 src/test_file.cor
diff -s src/test_file.cor ./test_file.cor
rm src/test_file.cor

./asm ./src/abel.s
chmod 777 src/abel.cor
diff -s src/abel.cor ./abel.cor
rm src/abel.cor

./asm ./src/bill.s
chmod 777 src/bill.cor
diff -s src/bill.cor ./bill.cor
rm src/bill.cor

./asm ./src/pdd.s
chmod 777 src/pdd.cor
diff -s src/pdd.cor ./pdd.cor
rm src/pdd.cor

./asm ./src/tyron.s
chmod 777 src/tyron.cor
diff -s src/tyron.cor ./tyron.cor
rm src/tyron.cor

rm ./asm