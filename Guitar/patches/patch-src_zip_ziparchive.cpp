$NetBSD$

For read() etc.

--- src/zip/ziparchive.cpp.orig	2025-07-21 19:41:18.048472674 +0000
+++ src/zip/ziparchive.cpp
@@ -2,6 +2,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <time.h>
+#include <unistd.h>
 
 #include "zipinternal.h"
 #include "zlib.h"
