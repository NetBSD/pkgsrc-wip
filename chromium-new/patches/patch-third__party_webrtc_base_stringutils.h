$NetBSD$

--- third_party/webrtc/base/stringutils.h.orig	2016-11-10 20:03:05.000000000 +0000
+++ third_party/webrtc/base/stringutils.h
@@ -23,7 +23,7 @@
 #endif  // WEBRTC_WIN 
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#if defined(BSD) || defined(WEBRTC_BSD)
 #include <stdlib.h>
 #else  // BSD
 #include <alloca.h>
