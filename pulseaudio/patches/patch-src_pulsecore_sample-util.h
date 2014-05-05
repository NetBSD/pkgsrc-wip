$NetBSD: patch-src_pulsecore_sample-util.h,v 1.1 2014/05/05 23:57:08 ryo-on Exp $

--- src/pulsecore/sample-util.h.orig	2014-01-23 18:57:55.000000000 +0000
+++ src/pulsecore/sample-util.h
@@ -34,6 +34,14 @@
 #include <pulsecore/memblock.h>
 #include <pulsecore/memchunk.h>
 
+#if !defined __WORDSIZE
+# if defined __LP64__
+#  define __WORDSIZE     64
+# else
+#  define __WORDSIZE     32
+# endif
+#endif
+
 typedef struct pa_silence_cache {
     pa_memblock* blocks[PA_SAMPLE_MAX];
 } pa_silence_cache;
