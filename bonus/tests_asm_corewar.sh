#!/bin/bash

cp ../asm/asm ./asm

./asm ./src/test_file.s
chmod 777 src/test_file.cor
diff src/test_file.cor ./test_file.cor
rm src/test_file.cor

./asm ./src/abel.s
chmod 777 src/abel.cor
diff src/abel.cor ./abel.cor
rm src/abel.cor

./asm ./src/bill.s
chmod 777 src/bill.cor
diff src/bill.cor ./bill.cor
rm src/bill.cor

./asm ./src/pdd.s
chmod 777 src/pdd.cor
diff src/pdd.cor ./pdd.cor
rm src/pdd.cor

./asm ./src/tyron.s
chmod 777 src/tyron.cor
diff src/tyron.cor ./tyron.cor
rm src/tyron.cor

rm ./asm