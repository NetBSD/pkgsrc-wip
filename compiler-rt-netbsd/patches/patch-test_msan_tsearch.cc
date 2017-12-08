$NetBSD$

--- test/msan/tsearch.cc.orig	2017-10-17 18:35:26.000000000 +0000
+++ test/msan/tsearch.cc
@@ -1,5 +1,8 @@
 // RUN: %clangxx_msan -O0 -g %s -o %t && %run %t
 
+// tdestroy is a GNU extension
+// UNSUPPORTED: netbsd
+
 #include <assert.h>
 #include <search.h>
 #include <stdlib.h>
