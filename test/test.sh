#!/bin/sh
# in heron shell this would look something like this
# files .c | extract name | for | t a | strip | t b | gcc $a -o $b | t b -l | execute

# Go to the right directory.
cd "${0%/*}"

# Get to work.
for filename in *.c; do
  echo ${filename%%.*}
  gcc $filename -o ${filename%%.*} -g
  ./${filename%%.*}
  #rm ${filename%%.*}
done
