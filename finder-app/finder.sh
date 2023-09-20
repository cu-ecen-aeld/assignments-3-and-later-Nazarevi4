#!/bin/sh
#Author: Ivan Nazarenko


if [ $# -ne 2 ]
then
	echo "Parameters were NOT specified!"
	exit 1
fi

if [ -d $1 ]
then
	FILESDIR=$1
else
	echo "$1 Directory does NOT exist in the file system!"
	exit 1
fi

SEARCHSTR=$2

FILES=$(find $FILESDIR -type f | wc -l)
LINES=$(grep -s -r "${SEARCHSTR}" ${FILESDIR} | wc -l)

echo "The number of files are ${FILES} and the number of matching lines are ${LINES}"
