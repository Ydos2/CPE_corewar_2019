#!/bin/bash

cp ../../../asm/asm ./asm

./asm ./src/test_file.s
diff -s src/test_file.cor ./reference_cor_files/test_file.cor
rm src/test_file.cor
echo " "

./asm ./src/abel.s
diff -s src/abel.cor ./reference_cor_files/abel.cor
rm src/abel.cor
echo " "

./asm ./src/bill.s
diff -s src/bill.cor ./reference_cor_files/bill.cor
rm src/bill.cor
echo " "

./asm ./src/pdd.s
diff -s src/pdd.cor ./reference_cor_files/pdd.cor
rm src/pdd.cor
echo " "

./asm ./src/tyron.s
diff -s src/tyron.cor ./reference_cor_files/tyron.cor
rm src/tyron.cor
echo " "

rm ./asm