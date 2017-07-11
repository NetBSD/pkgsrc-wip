$NetBSD$

--- test/TableGen/UnterminatedComment.td.orig	2017-07-05 18:41:17.000000000 +0000
+++ test/TableGen/UnterminatedComment.td
@@ -1,4 +1,4 @@
-// RUN: not llvm-tblgen < %s >& /dev/null
+// RUN: not llvm-tblgen < %s > /dev/null 2>&1
 
 def x;
 
