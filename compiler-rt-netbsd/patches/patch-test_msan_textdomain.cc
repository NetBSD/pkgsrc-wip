$NetBSD$

--- test/msan/textdomain.cc.orig	2017-10-17 18:35:26.000000000 +0000
+++ test/msan/textdomain.cc
@@ -1,4 +1,4 @@
-// RUN: %clangxx_msan -O0 -g %s -o %t && %run %t
+// RUN: %clangxx_msan -lintl -O0 -g %s -o %t && %run %t
 
 #include <libintl.h>
 #include <stdio.h>
