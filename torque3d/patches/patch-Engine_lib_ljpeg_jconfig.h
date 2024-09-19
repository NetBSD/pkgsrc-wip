$NetBSD$

--- Engine/lib/ljpeg/jconfig.h.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/lib/ljpeg/jconfig.h
@@ -24,7 +24,7 @@
    #define JCONFIG_INCLUDED
 #endif
 
-#if (( __GNUC__ >= 2 ) && (defined (__CYGWIN32__) || defined (__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__WIN32__) || defined(SN_TARGET_PS3)) )
+#if (( __GNUC__ >= 2 ) && (defined (__CYGWIN32__) || defined (__linux__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__WIN32__) || defined(SN_TARGET_PS3)) )
    #include "jconfig.gcc.linux.h"
    #define JCONFIG_INCLUDED
 #endif
