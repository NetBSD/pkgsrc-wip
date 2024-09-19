$NetBSD$

Run script directly so python version is correct.

--- test/runXMV.sh.orig	2020-10-27 18:34:34.000000000 +0000
+++ test/runXMV.sh
@@ -9,5 +9,5 @@ if [ $# -ne 8 ]; then
 fi
 
 # source PATH-TO-SOURCE (IF NEEDED)
-python3 ../xmatchview.py -x $1 -s $3 -q $2 -a $4 -m $5 -b 10 -r 1 -c $6 -f png -y $7 -e $8 -p ../../tarballs/fonts
+xmatchview.py -x $1 -s $3 -q $2 -a $4 -m $5 -b 10 -r 1 -c $6 -f png -y $7 -e $8 -p ../../tarballs/fonts
 
