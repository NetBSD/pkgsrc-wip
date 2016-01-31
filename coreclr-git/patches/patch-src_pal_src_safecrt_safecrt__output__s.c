$NetBSD$

--- src/pal/src/safecrt/safecrt_output_s.c.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/safecrt/safecrt_output_s.c
@@ -41,4 +41,5 @@ typedef char        _TCHAR;
 typedef char        TCHAR;
 #define _T(x)       x
 
+#include <stdarg.h>
 #include "output.inl"
