$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_posix.h.orig	2017-06-12 15:01:29.910328073 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_posix.h
@@ -18,18 +18,31 @@
 #include "sanitizer_internal_defs.h"
 #include "sanitizer_platform.h"
 
+// FreeBSD's and NetBSD's dlopen() returns a pointer to an Obj_Entry structure
+// that incorporates the map structure.
 #if SANITIZER_FREEBSD
-// FreeBSD's dlopen() returns a pointer to an Obj_Entry structure that
-// incorporates the map structure.
 # define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) \
     ((link_map*)((handle) == nullptr ? nullptr : ((char*)(handle) + 544)))
-// Get sys/_types.h, because that tells us whether 64-bit inodes are
-// used in struct dirent below.
-#include <sys/_types.h>
+#elif SANITIZER_NETBSD
+#if defined(__x86_64__)
+# define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) \
+    ((link_map*)((handle) == nullptr ? nullptr : ((char*)(handle) + 608)))
+#elif defined(__i386__)
+# define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) \
+    ((link_map*)((handle) == nullptr ? nullptr : ((char*)(handle) + 324)))
+#else
+#error Port sanitizer_platform_limits_posix.h.
+#endif
 #else
 # define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) ((link_map*)(handle))
 #endif  // !SANITIZER_FREEBSD
 
+#if SANITIZER_FREEBSD
+// Get sys/_types.h, because that tells us whether 64-bit inodes are
+// used in struct dirent below.
+#include <sys/_types.h>
+#endif
+
 #ifndef __GLIBC_PREREQ
 #define __GLIBC_PREREQ(x, y) 0
 #endif
