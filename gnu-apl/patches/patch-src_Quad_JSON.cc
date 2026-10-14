$NetBSD$

SunOS fix: Add unistd.h and fcntl.h which are needed

--- src/Quad_JSON.cc.orig
+++ src/Quad_JSON.cc
@@ -23,6 +23,8 @@
 
 #include <errno.h>
 #include <string.h>
+#include <unistd.h>
+#include <fcntl.h>
 
 #include <sys/fcntl.h>   // for O_RDONLY
 #include <sys/stat.h>
