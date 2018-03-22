$NetBSD$

Adding NetBSD-specific macro.
Fixed in the upstream: 
github.com/PurpleI2P/i2pd/commit/30fb0f5a942cc5195c725feae25ab38f88b08436

--- libi2pd/I2PEndian.h	2018-01-30 16:14:29.000000000 +0000
+++ libi2pd/I2PEndian.h
@@ -3,7 +3,7 @@
 #include <inttypes.h>
 #include <string.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
 #include <endian.h>
