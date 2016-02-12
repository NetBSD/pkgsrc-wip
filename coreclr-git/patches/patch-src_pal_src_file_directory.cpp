$NetBSD$

--- src/pal/src/file/directory.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/file/directory.cpp
@@ -25,9 +25,7 @@ Revision History:
 #include "pal/file.h"
 #include "pal/stackstring.hpp"
 
-#if HAVE_ALLOCA_H
-#include <alloca.h>
-#endif  // HAVE_ALLOCA_H
+#include <stdlib.h>
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
