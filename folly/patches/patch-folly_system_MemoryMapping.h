$NetBSD$

NetBSD support.

--- folly/system/MemoryMapping.h.orig	2024-08-19 19:40:08.467927907 +0000
+++ folly/system/MemoryMapping.h
@@ -22,6 +22,10 @@
 #include <folly/Range.h>
 #include <folly/portability/Unistd.h>
 
+#ifndef off64_t
+#define off64_t off_t
+#endif
+
 namespace folly {
 
 /**
