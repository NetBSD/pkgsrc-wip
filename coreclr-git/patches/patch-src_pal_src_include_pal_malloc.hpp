$NetBSD$

--- src/pal/src/include/pal/malloc.hpp.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/src/include/pal/malloc.hpp
@@ -24,10 +24,7 @@ Abstract:
 #include "pal/thread.hpp"
 
 #include <stdarg.h>
-
-#if HAVE_ALLOCA_H
-#include <alloca.h>
-#endif  // HAVE_ALLOCA_H  
+#include <stdlib.h>
 
 extern "C"
 {
