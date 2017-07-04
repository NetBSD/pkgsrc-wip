$NetBSD$
* make header self contained
--- fpxlib.h.orig	2017-07-04 10:24:56.000000000 +0000
+++ fpxlib.h
@@ -12,6 +12,7 @@
 extern "C" {
 #endif
 #include <inttypes.h>
+#include <stddef.h>
 
   typedef struct IStream IStream;
   typedef struct IStorage IStorage;
