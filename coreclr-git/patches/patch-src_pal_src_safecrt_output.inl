$NetBSD$

--- src/pal/src/safecrt/output.inl.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/safecrt/output.inl
@@ -50,7 +50,7 @@ Buffer size required to be passed to _gc
 //#include <stddef.h>
 //#include <crtdefs.h>
 //#include <stdio.h>
-//#include <stdarg.h>
+#include <stdarg.h>
 //#include <cvt.h>
 //#include <conio.h>
 //#include <internal.h>
@@ -1738,4 +1738,3 @@ __inline __int64 __cdecl get_int64_arg (
 #endif  /* _UNICODE */
 
 #endif // __GNUC_VA_LIST
-
