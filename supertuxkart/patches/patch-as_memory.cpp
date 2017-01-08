$NetBSD$
Already Upstream
--- lib/angelscript/source/as_memory.cpp.orig	2017-01-06 15:26:31.686744309 +0000
+++ lib/angelscript/source/as_memory.cpp	2017-01-06 15:27:48.560540015 +0000
@@ -38,7 +38,7 @@
 
 #include <stdlib.h>
 
-#if !defined(__APPLE__) && !defined( __SNC__ ) && !defined( __ghs__ ) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined( __SNC__ ) && !defined( __ghs__ ) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #include <malloc.h>
 #endif
 
