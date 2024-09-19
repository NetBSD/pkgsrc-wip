$NetBSD$

Improve portability of test usage.  Reported upstream as
https://github.com/genometools/genometools/issues/989.

--- scripts/spmcheck.sh.orig	2021-06-24 14:43:03.000000000 +0000
+++ scripts/spmcheck.sh
@@ -14,7 +14,7 @@ inputfile=$3
 
 env -i bin/gt sequniq -rev $inputfile > tmp.fas
 sfxopt="-pl 2 -dna -lcp -suf -tis -ssp -db tmp.fas"
-if test ${mirrored} == "m"
+if test ${mirrored} = "m"
 then
   idx="sfx-m"
 else
