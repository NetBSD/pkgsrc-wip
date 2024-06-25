$NetBSD$

# Xcode 5.3 build failure

--- gcc/system.h.orig	2024-06-25 12:10:19.816843653 +0000
+++ gcc/system.h
@@ -206,6 +206,52 @@ extern int fprintf_unlocked (FILE *, con
 /* There are an extraordinary number of issues with <ctype.h>.
    The last straw is that it varies with the locale.  Use libiberty's
    replacement instead.  */
+#ifdef __APPLE__	// Xcode 5.3 build failure
+
+// Build fails with Xcode 5.3 due to indirect includes
+// Include all system headers before safe-ctype.h
+
+#include <sys/types.h>
+
+#include <errno.h>
+
+#if !defined (errno) && defined (HAVE_DECL_ERRNO) && !HAVE_DECL_ERRNO
+extern int errno;
+#endif
+
+#ifdef __cplusplus
+#if defined (INCLUDE_ALGORITHM) || !defined (HAVE_SWAP_IN_UTILITY)
+# include <algorithm>
+#endif
+#ifdef INCLUDE_LIST
+# include <list>
+#endif
+#ifdef INCLUDE_MAP
+# include <map>
+#endif
+#ifdef INCLUDE_SET
+# include <set>
+#endif
+#ifdef INCLUDE_VECTOR
+# include <vector>
+#endif
+#ifdef INCLUDE_ARRAY
+# include <array>
+#endif
+#ifdef INCLUDE_FUNCTIONAL
+# include <functional>
+#endif
+# include <cstring>
+# include <initializer_list>
+# include <new>
+# include <utility>
+# include <type_traits>
+#endif
+
+#include "safe-ctype.h"
+
+#else	// __APPLE__
+
 #include "safe-ctype.h"
 
 #include <sys/types.h>
@@ -245,6 +291,8 @@ extern int errno;
 # include <type_traits>
 #endif
 
+#endif	// __APPLE__
+
 /* Some of glibc's string inlines cause warnings.  Plus we'd rather
    rely on (and therefore test) GCC's string builtins.  */
 #define __NO_STRING_INLINES
@@ -270,9 +318,11 @@ extern int errno;
    that it is processed before we poison "malloc"; otherwise, if a source
    file uses a standard library header that includes <cstdlib>, we will get
    an error about 'using std::malloc'.  */
+#ifndef __APPLE__	// Xcode 5.3 build failure
 #ifdef __cplusplus
 #include <cstdlib>
 #endif
+#endif
 
 /* Undef vec_free from AIX stdlib.h header which conflicts with vec.h.  */
 #undef vec_free
