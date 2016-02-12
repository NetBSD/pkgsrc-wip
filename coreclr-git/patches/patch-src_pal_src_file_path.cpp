$NetBSD$

--- src/pal/src/file/path.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/file/path.cpp
@@ -30,9 +30,7 @@ Revision History:
 #include <errno.h>
 
 #include <unistd.h>
-#if HAVE_ALLOCA_H
-#include <alloca.h>
-#endif  // HAVE_ALLOCA_H
+#include <stdlib.h>
 
 SET_DEFAULT_DEBUG_CHANNEL(FILE);
 
