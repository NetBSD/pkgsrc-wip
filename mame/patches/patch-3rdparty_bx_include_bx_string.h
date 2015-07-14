$NetBSD: patch-3rdparty_bx_include_bx_string.h,v 1.1 2015/07/14 18:51:45 thomasklausner Exp $

alloca.h is obsolete.

--- 3rdparty/bx/include/bx/string.h.orig	2015-06-24 09:53:24.000000000 +0000
+++ 3rdparty/bx/include/bx/string.h
@@ -7,7 +7,6 @@
 #define BX_STRING_H_HEADER_GUARD
 
 #include "bx.h"
-#include <alloca.h>
 #include <ctype.h>  // tolower
 #include <stdarg.h> // va_list
 #include <stdio.h>  // vsnprintf, vsnwprintf
