#!/bin/bash

rm fail_soustraction
touch fail_soustraction
for i in `seq 1 500`; do
    nbr1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nbr2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nbr3=$(echo "$nbr1 -$nbr2" | bc)
    nbr4=$(./infin_add $nbr1 -$nbr2)
    echo $nbr3 > comp1
    echo $nbr4 > comp2
    diff=$(diff comp1 comp2)
    if [ "$diff" == "" ]
    then
	echo -e "\e[32mOK\e[0m: GOT: $nbr4"
    else
	echo -e "\e[31mFailed\e[0m: GOT: $nbr4, but exepted: $nbr3 for $nbr1 -$nbr2"
	echo -e "\e[31mFailed\e[0m: GOT: $nbr4, but exepted: $nbr3 for $nbr1 -$nbr2" >> fail_soustraction
    fi
done
for z in `seq 1 500`; do
    nbr1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nbr2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nbr3=$(echo "-$nbr1 + $nbr2" | bc)
    nbr4=$(./infin_add -$nbr1 $nbr2)
    echo $nbr3 > comp1
    echo $nbr4 > comp2
    diff=$(diff comp1 comp2)
    if [ "$diff" == "" ]
    then
        echo -e "\e[32mOK\e[0m: GOT: $nbr4"
    else
        echo -e "\e[31mFailed\e[0m: GOT: $nbr4, but exepted: $nbr3 for -$nbr1 + $nbr2"
	echo -e "\e[31mFailed\e[0m: GOT: $nbr4, but exepted: $nbr3 for -$nbr1 + $nbr2" >> fail_soustraction
    fi
done
for y in `seq 1 500`; do
    nbr1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nbr2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nbr3=$(echo "-$nbr1 + -$nbr2" | bc)
    nbr4=$(./infin_add -$nbr1 -$nbr2)
    echo $nbr3 > comp1
    echo $nbr4 > comp2
    diff=$(diff comp1 comp2)
    if [ "$diff" == "" ]
    then
        echo -e "\e[32mOK\e[0m: GOT: $nbr4"
    else
        echo -e "\e[31mFailed\e[0m: GOT: $nbr4, but exepted: $nbr3 for -$nbr1 + -$nbr2"
	echo -e "\e[31mFailed\e[0m: GOT: $nbr4, but exepted: $nbr3 for -$nbr1 + -$nbr2" >> fail_soustraction
    fi
done
rm comp1 comp2