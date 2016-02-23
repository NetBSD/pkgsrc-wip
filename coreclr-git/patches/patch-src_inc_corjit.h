$NetBSD$

--- src/inc/corjit.h.orig	2016-02-18 21:11:19.000000000 +0000
+++ src/inc/corjit.h
@@ -30,6 +30,8 @@
 
 #include <corinfo.h>
 
+#include <stdarg.h>
+
 #define CORINFO_STACKPROBE_DEPTH        256*sizeof(UINT_PTR)          // Guaranteed stack until an fcall/unmanaged
                                                     // code can set up a frame. Please make sure
                                                     // this is less than a page. This is due to
