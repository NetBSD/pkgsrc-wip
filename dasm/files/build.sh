#!/bin/sh

WRKSRC="$1"
CC="$2"

cd ${WRKSRC}

for obj in mne6502 mne6303 mne6811 mne68705 ops globals main symbols exp ; do 
   echo "compile object: $obj.c -> $obj.o"
   ${CC} -g -O2 -c -o $obj.o $obj.c ; done

echo "compile mne6502.o mne6303.o mne6811.o mne68705.o ops.o globals.o main.o symbols.o exp. -> dasm"
${CC} -g -O2 -o dasm mne6502.o mne6303.o mne6811.o mne68705.o ops.o globals.o main.o symbols.o exp.o
