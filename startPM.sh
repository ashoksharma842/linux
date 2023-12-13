#!/bin/bash
echo "power module test script"
echo
# Module 1 sets the output of 700V, 20A
# 700V = 700*1000 = 700000mV = 0xAAE60
# 20A = 20*1000 = 20000mA = 0x4E20
cansend can1 1307C090#00004E20000AAE60

# Module 1 start
cansend can1 1307C090#0200000000000055

while :
do
# read the status of module 1
        cansend can1 1307C090#0100000000000000
        sleep 1s
done
