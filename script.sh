#! /bin/bash

LIST=$(ls $1)
for i in $LIST ; do
	echo ">> $i"
done
