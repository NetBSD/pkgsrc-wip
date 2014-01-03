$NetBSD: patch-dat.h,v 1.1 2014/01/03 05:31:52 othyro Exp $

Don't redefine int8_t, uint8_t, int32_t, uint32_t, int64_t, uint64_t.

--- dat.h.orig	2013-04-14 17:19:41.000000000 +0000
+++ dat.h
@@ -10,12 +10,24 @@ typedef uint32_t      uint32;
 typedef int64_t       int64;
 typedef uint64_t      uint64;
 
+#ifndef int8_t
 #define int8_t   do_not_use_int8_t
+#endif
+#ifndef uint8_t
 #define uint8_t  do_not_use_uint8_t
+#endif
+#ifndef int32_t
 #define int32_t  do_not_use_int32_t
+#endif
+#ifndef uint32_t
 #define uint32_t do_not_use_uint32_t
+#endif
+#ifndef int64_t
 #define int64_t  do_not_use_int64_t
+#endif
+#ifndef uint64_t
 #define uint64_t do_not_use_uint64_t
+#endif
 
 typedef struct ms     *ms;
 typedef struct job    *job;
