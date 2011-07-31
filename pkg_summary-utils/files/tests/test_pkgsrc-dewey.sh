# pkgsrc-dewey.awk
AWKPATH=`pwd`/.. ./pkgsrc-dewey-test < ./pkgsrc-dewey-test.txt 2>&1 |
cmp 'pkgsrc-dewey.awk' ''
