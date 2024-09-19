$NetBSD$

Fix
error: 'va_list' has not been declared

--- Libraries/MiKTeX/Util/include/miktex/Util/StringUtil.h.orig	2019-11-16 19:20:48.000000000 +0000
+++ Libraries/MiKTeX/Util/include/miktex/Util/StringUtil.h
@@ -25,6 +25,7 @@
 #define F6BFCB48DCDA42E992057245151CA1D5
 
 #include "config.h"
+#include <stdarg.h>
 
 #include <cstddef>
 #include <cwchar>
