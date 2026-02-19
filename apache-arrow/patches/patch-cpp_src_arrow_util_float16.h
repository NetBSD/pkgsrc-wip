$NetBSD$

--- cpp/src/arrow/util/float16.h.orig	2025-07-31 02:41:59.174274792 +0000
+++ cpp/src/arrow/util/float16.h
@@ -29,6 +29,12 @@
 #include "arrow/util/ubsan.h"
 #include "arrow/util/visibility.h"
 
+#ifdef __NetBSD__
+#ifdef signbit
+#undef signbit
+#endif
+#endif
+
 namespace arrow {
 namespace util {
 
