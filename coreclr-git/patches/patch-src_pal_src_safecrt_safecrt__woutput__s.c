$NetBSD$

--- src/pal/src/safecrt/safecrt_woutput_s.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/safecrt/safecrt_woutput_s.c
@@ -54,5 +54,5 @@ typedef wchar_t     _TCHAR;
 typedef wchar_t     TCHAR;
 #define _T(x)       L##x
 
+#include <stdarg.h>
 #include "output.inl"
-
