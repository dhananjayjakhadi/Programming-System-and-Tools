#!/bin/bash
echo " Would you like To create File[Y\N]? "
read ANS;
if [ $ANS = 'Y' ];
then
mkdir -p /home/djakhad1/TRASH/;
echo " File Created "
elif [ $ANS = 'N' ];
then 
echo " File already exists or Missing File "
fi


echo " Would You want to Move File into Directory[Y/N]? "
read ANS
if [ $ANS = 'Y' ];
then
mv /home/djakhad1/sampletest/*  /home/djakhad1/TRASH/;
echo " File Moved "
elif [ $ANS = 'N' ];
then
echo " File Not exist or Already Moved "
fi

echo " The Given file in a directory TRASH will be deleted After one minute "
find /home/djakhad1/TRASH/ -mmin +60 -exec rm {} \;

