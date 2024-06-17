$NetBSD$

--- gcc/system.h.orig	2023-05-08 12:14:40.077167427 +0000
+++ gcc/system.h
@@ -194,27 +194,8 @@ extern int fprintf_unlocked (FILE *, con
 #undef fread_unlocked
 #undef fwrite_unlocked
 
-/* Include <string> before "safe-ctype.h" to avoid GCC poisoning
-   the ctype macros through safe-ctype.h */
-
-#ifdef __cplusplus
-#ifdef INCLUDE_STRING
-# include <string>
-#endif
-#endif
-
-/* There are an extraordinary number of issues with <ctype.h>.
-   The last straw is that it varies with the locale.  Use libiberty's
-   replacement instead.  */
-#include "safe-ctype.h"
-
-#include <sys/types.h>
-
-#include <errno.h>
-
-#if !defined (errno) && defined (HAVE_DECL_ERRNO) && !HAVE_DECL_ERRNO
-extern int errno;
-#endif
+/* Include C++ standard headers before "safe-ctype.h" to avoid GCC
+   poisoning the ctype macros through safe-ctype.h */
 
 #ifdef __cplusplus
 #if defined (INCLUDE_ALGORITHM) || !defined (HAVE_SWAP_IN_UTILITY)
@@ -229,6 +210,9 @@ extern int errno;
 #ifdef INCLUDE_SET
 # include <set>
 #endif
+#ifdef INCLUDE_STRING
+# include <string>
+#endif
 #ifdef INCLUDE_VECTOR
 # include <vector>
 #endif
@@ -245,6 +229,19 @@ extern int errno;
 # include <type_traits>
 #endif
 
+/* There are an extraordinary number of issues with <ctype.h>.
+   The last straw is that it varies with the locale.  Use libiberty's
+   replacement instead.  */
+#include "safe-ctype.h"
+
+#include <sys/types.h>
+
+#include <errno.h>
+
+#if !defined (errno) && defined (HAVE_DECL_ERRNO) && !HAVE_DECL_ERRNO
+extern int errno;
+#endif
+
 /* Some of glibc's string inlines cause warnings.  Plus we'd rather
    rely on (and therefore test) GCC's string builtins.  */
 #define __NO_STRING_INLINES
@@ -270,9 +267,11 @@ extern int errno;
    that it is processed before we poison "malloc"; otherwise, if a source
    file uses a standard library header that includes <cstdlib>, we will get
    an error about 'using std::malloc'.  */
+/*
 #ifdef __cplusplus
 #include <cstdlib>
 #endif
+*/
 
 /* Undef vec_free from AIX stdlib.h header which conflicts with vec.h.  */
 #undef vec_free
