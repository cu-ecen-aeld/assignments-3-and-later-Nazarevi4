#!/bin/bash
#Author: Ivan Nazarenko

if [ $# -ne 2 ]
then
	echo "Arguments were NOT specified!"
	exit 1
fi

WRITE_FILE="$1"
WRITE_STR="$2"

DIRECTORY=$(dirname "$WRITE_FILE")

if [ ! -d  ${DIRECTORY} ]
then
	mkdir -p ${DIRECTORY}
fi

echo ${WRITE_STR} > ${WRITE_FILE}

if [ ! -e ${WRITE_FILE} ]
then
	echo "File could NOT be created!"
	exit 1
fi

