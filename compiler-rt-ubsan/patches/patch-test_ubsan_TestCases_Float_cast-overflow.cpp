$NetBSD$

--- test/ubsan/TestCases/Float/cast-overflow.cpp.orig	2017-07-03 15:33:06.000000000 +0000
+++ test/ubsan/TestCases/Float/cast-overflow.cpp
@@ -18,7 +18,7 @@
 # define BYTE_ORDER __DARWIN_BYTE_ORDER
 # define BIG_ENDIAN __DARWIN_BIG_ENDIAN
 # define LITTLE_ENDIAN __DARWIN_LITTLE_ENDIAN
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 # include <sys/endian.h>
 # define BYTE_ORDER _BYTE_ORDER
 # define BIG_ENDIAN _BIG_ENDIAN
