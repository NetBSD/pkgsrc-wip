$NetBSD$

jemalloc(3) provides malloc_usable_size().
It would be better to find a more portable solution!

--- mem/mem.cpp.orig	2024-08-24 19:59:36.438438241 +0000
+++ mem/mem.cpp
@@ -194,6 +194,8 @@
 #if defined(MACOSX)
 
 #include <malloc/malloc.h>
+#elseif defined(__FreeBSD__) || defined(__NetBSD__)
+#include <jemalloc/jemalloc.h>
 #else
 #include <malloc.h>
 #endif
