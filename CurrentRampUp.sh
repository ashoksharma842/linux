echo "power module[16] Current ramp up from 0 to 750 in steps of 50V "
echo
i=0
volt=700
mV=$((volt*1000))
current=0
mA=$((current*1000))
HmV=$(printf "%08X" $mV)
HmA=$(printf "%08X" $mA)
echo "Volt   ="$volt"V ="$mV"mV : "$HmV
echo "Current="$current"I = "$mA"mA : "$HmA
command="cansend can1 "
ID="1307C090#"
sendcmd=$command$ID$HmA$HmV

echo $sendcmd
eval $sendcmd

# Module 16 start
cansend can1 1307C090#0200000000000055
#wait to set power module to 200

while [ $i -lt 10 ];
do
        cansend can1 1307C090#0100000000000000
        i=$((i+1))
        sleep 1s
        echo $i
done

i=0
echo "volt: $volt"

while [ $current -lt 28 ];
#while :
do
# set the volt and current of module 16
        if [ $i -gt 20 ]
        then
                current=$((current+10))
				power=$((current*volt))
				echo "current: $current, power: $power"
				if [ $power -ge 20000]
				then
					current=0
					volt=$((volt-50))
						if [ $volt -lt 200 ]
						then
							break
						fi
					mV=$((volt*1000))
					echo "set: $volt V"
					HmV=$(prinf "%08X" $mV)
				fi
                mA=$((current*1000))
                echo "set: $current A"
                HmA=$(printf "%08X" $mA)
                sendcmd=$command$ID$HmA$HmV
				echo $sendcmd
                eval $sendcmd
                i=0
        fi
# read the status of module 16
        cansend can1 1307C090#0100000000000000
#       cansend can1 1307A090#3100000000000000
        sleep 0.1s
        i=$((i+1))
done
while :
do
        cansend can1 1307C090#0100000000000000
        sleep 1s
done
