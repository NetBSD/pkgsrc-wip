$NetBSD$

--- engine/lib/ljpeg/jconfig.h.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/lib/ljpeg/jconfig.h
@@ -24,7 +24,7 @@
    #define JCONFIG_INCLUDED
 #endif
 
-#if (( __GNUC__ >= 2 ) && (defined (__CYGWIN32__) || defined (__linux__) || defined(EMSCRIPTEN) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__WIN32__)) )
+#if (( __GNUC__ >= 2 ) && (defined (__CYGWIN32__) || defined (__linux__) || defined(EMSCRIPTEN) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__WIN32__)) )
    #include "jconfig.gcc.linux.h"
    #define JCONFIG_INCLUDED
 #endif
