$NetBSD$

--- test/msan/initgroups.cc.orig	2017-06-03 23:53:55.000000000 +0000
+++ test/msan/initgroups.cc
@@ -2,7 +2,7 @@
 
 #include <sys/types.h>
 #include <grp.h>
-#include <unistd.h>  // FreeBSD declares initgroups() here.
+#include <unistd.h>  // FreeBSD/NetBSD declares initgroups() here.
 
 int main(void) {
   initgroups("root", 0);
