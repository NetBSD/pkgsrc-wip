$NetBSD$

Use the appropriate C++ header files.

--- Ecc/StdH.h.orig	2020-08-26 21:54:20.806586674 +0000
+++ Ecc/StdH.h
@@ -14,19 +14,19 @@ with this program; if not, write to the 
 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */
 
 #include <ctype.h>
-#include <assert.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <stdarg.h>
-#include <math.h>
+#include <cassert>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cstdarg>
+#include <cmath>
 
 #ifdef PLATFORM_WIN32
-#include <malloc.h>
+#include <cmalloc>
 #endif
 
 #ifdef PLATFORM_UNIX
-#include <errno.h>
+#include <cerrno>
 #include <sys/param.h>
 #include <unistd.h>
 #define _fullpath(x, y, z) realpath(y, x)
