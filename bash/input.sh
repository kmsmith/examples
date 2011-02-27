#!/bin/sh

INPUT="$1"  # no spaces around '='
echo "Hello, $INPUT."

printf "What is your name?  "  # printf does not make newline
read NAME
echo "Hello, $NAME."
