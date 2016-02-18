$NetBSD$

--- src/pal/inc/pal.h.orig	2016-02-18 21:11:19.000000000 +0000
+++ src/pal/inc/pal.h
@@ -6050,6 +6050,7 @@ CoCreateGuid(OUT GUID * pguid);
 #define _close        PAL__close
 #define _wcstoui64    PAL__wcstoui64
 #define _flushall     PAL__flushall
+#define _vsnprintf    PAL__vsnprintf
 
 #ifdef _AMD64_ 
 #define _mm_getcsr    PAL__mm_getcsr
