$NetBSD: patch-Common_core_endianness.h,v 1.1 2015/08/18 18:47:58 yhardy Exp $

Fix includes for NetBSD.

--- Common/core/endianness.h.orig	2015-07-12 16:14:07.000000000 +0000
+++ Common/core/endianness.h
@@ -18,8 +18,12 @@
 #if !defined (WINDOWS_VERSION)
 
 #if defined (LINUX_VERSION)
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
 #endif
+#endif
 
 // Detect endianess on Linux
 // The logic is inverted on purpose so that it assumes
