$NetBSD$

Use the appropriate C++ header files.

--- Ecc/StdH.h.orig	2022-07-28 19:12:44.000000000 +0000
+++ Ecc/StdH.h
@@ -13,18 +13,18 @@ You should have received a copy of the G
 with this program; if not, write to the Free Software Foundation, Inc.,
 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */
 
-#include <ctype.h>
-#include <assert.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <stdarg.h>
-#include <math.h>
+#include <cctype>
+#include <cassert>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cstdarg>
+#include <cmath>
 
 #ifdef _WIN32
 #include <malloc.h>
 #else
-#include <errno.h>
+#include <cerrno>
 #include <sys/param.h>
 #include <unistd.h>
 #define _fullpath(x, y, z) realpath(y, x)
