$NetBSD$

# Portability

--- src/vsearch.h.orig	2019-04-30 11:57:32.000000000 +0000
+++ src/vsearch.h
@@ -138,9 +138,7 @@
 #define bswap_32(x) _byteswap_ulong(x)
 #define bswap_64(x) _byteswap_uint64(x)
 
-#else
-
-#ifdef __APPLE__
+#elif defined(__APPLE__)
 
 #define PROG_OS "macos"
 #include <sys/sysctl.h>
@@ -149,20 +147,42 @@
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
 
-#else
+#elif defined(__linux__)
 
-#ifdef __linux__
 #define PROG_OS "linux"
-#else
-#define PROG_OS "unknown"
-#endif
-
 #include <sys/sysinfo.h>
+#include <sys/resource.h>
 #include <byteswap.h>
 
-#endif
+#elif defined(__FreeBSD__)
+
+#define PROG_OS "freebsd"
+#include <sys/sysinfo.h>
+#include <sys/resource.h>
+
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+
+#elif defined(__NetBSD__)
 
+#define PROG_OS "netbsd"
 #include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/bswap.h>
+
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+
+// Alters behavior, but NetBSD 7 does not have this function
+#define getopt_long_only getopt_long
+
+#else
+
+#define PROG_OS "unknown"
+#include <sys/sysinfo.h>
+#include <byteswap.h>
 
 #endif
 
