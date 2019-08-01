$NetBSD$

sys/stat.h for S_IRUSR etc.

--- mono/utils/mono-state.c.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/utils/mono-state.c
@@ -17,6 +17,7 @@
 #include <mono/metadata/object-internals.h>
 
 #include <sys/param.h>
+#include <sys/stat.h>
 #include <fcntl.h>
 #include <utils/mono-threads-debug.h>
 
