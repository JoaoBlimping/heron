#!/bin/sh
# in heron shell this would look something like this
# files .c | extract name | for | t a | strip | t b | gcc $a -o $b | t b -l | execute

# Go to the right directory.
cd "${0%/*}"

# Get to work.
for filename in *.c; do
  echo "\e[0m\e[7m========${filename%%.*}=============\e[0m"
  gcc $filename -o ${filename%%.*} -g
  # the && means that when there is a segmentation fault the file stays in existence so we can use
  # gdb on it, otherwise it is deleted
  ./${filename%%.*} && rm ${filename%%.*}
done
