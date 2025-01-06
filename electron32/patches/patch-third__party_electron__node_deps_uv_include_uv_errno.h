$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/include/uv/errno.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/uv/include/uv/errno.h
@@ -456,18 +456,6 @@
 # define UV__ESOCKTNOSUPPORT (-4025)
 #endif
 
-/* FreeBSD defines ENODATA in /usr/include/c++/v1/errno.h which is only visible
- * if C++ is being used. Define it directly to avoid problems when integrating
- * libuv in a C++ project.
- */
-#if defined(ENODATA) && !defined(_WIN32)
-# define UV__ENODATA UV__ERR(ENODATA)
-#elif defined(__FreeBSD__)
-# define UV__ENODATA (-9919)
-#else
-# define UV__ENODATA (-4024)
-#endif
-
 #if defined(EUNATCH) && !defined(_WIN32)
 # define UV__EUNATCH UV__ERR(EUNATCH)
 #else
