$NetBSD$

Improve portability of test usage.  Reported upstream as
https://github.com/genometools/genometools/issues/989.

--- scripts/calltestcase.sh.orig	2021-06-24 14:43:03.000000000 +0000
+++ scripts/calltestcase.sh
@@ -2,7 +2,7 @@
 
 cd testsuite
 
-if test "${TMPDIR}" == ""
+if test "${TMPDIR}" = ""
 then
   TMPDIR="."
 fi
