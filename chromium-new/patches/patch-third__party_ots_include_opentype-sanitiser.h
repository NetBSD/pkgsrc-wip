$NetBSD$

--- third_party/ots/include/opentype-sanitiser.h.orig	2016-06-24 01:02:48.000000000 +0000
+++ third_party/ots/include/opentype-sanitiser.h
@@ -22,6 +22,7 @@ typedef unsigned __int64 uint64_t;
 #else
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #include <algorithm>
