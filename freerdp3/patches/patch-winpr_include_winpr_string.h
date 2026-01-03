$NetBSD$

include <stdarg.h> for 'va_list'

--- winpr/include/winpr/string.h.orig	2025-04-14 13:11:41.000000000 +0000
+++ winpr/include/winpr/string.h
@@ -24,6 +24,7 @@
 #include <wchar.h>
 #include <stdio.h>
 #include <string.h>
+#include <stdarg.h>
 #include <winpr/config.h>
 #include <winpr/winpr.h>
 #include <winpr/wtypes.h>
