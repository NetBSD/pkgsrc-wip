$NetBSD: patch-ctypes_CTypes.h,v 1.1 2014/02/06 15:12:18 fhajny Exp $

--- ctypes/CTypes.h.orig	2013-11-19 19:42:43.000000000 +0000
+++ ctypes/CTypes.h
@@ -16,6 +16,23 @@
 
 #include "js/HashTable.h"
 
+#if defined(__NetBSD__)
+#include <stdint.h>
+/* XXX why do we have those funky __ #defines in stdint.h? */
+#warning this is a retarded workaround
+#define uint8_t uint8_t
+#define uint16_t uint16_t
+#define uint32_t uint32_t
+#define uint64_t uint64_t
+#define int8_t int8_t
+#define int16_t int16_t
+#define int32_t int32_t
+#define int64_t int64_t
+#define intptr_t intptr_t
+#define uintptr_t uintptr_t
+#define off_t off_t
+#endif
+
 namespace js {
 namespace ctypes {
 
