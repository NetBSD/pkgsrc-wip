$NetBSD$

--- src/pal/inc/pal.h.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/inc/pal.h
@@ -6027,6 +6027,7 @@ CoCreateGuid(OUT GUID * pguid);
 #define localtime     PAL_localtime
 #define mktime        PAL_mktime
 #define rand          PAL_rand
+#define time          PAL_time
 #define getenv        PAL_getenv
 #define fgets         PAL_fgets
 #define fgetws        PAL_fgetws
