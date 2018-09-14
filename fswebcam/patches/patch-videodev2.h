$NetBSD$

Avoid possible Linux-isms.

In part inspired from <sys/videoio.h> and OpenBSD port trying to
be less intrusive as possible though.

--- videodev2.h.orig	2014-01-13 18:47:15.000000000 +0000
+++ videodev2.h
@@ -58,8 +58,17 @@
 
 #include <sys/time.h>
 
-#include <linux/ioctl.h>
-#include <linux/types.h>
+#define __u64	uint64_t
+#define __u32	uint32_t
+#define __u16	uint16_t
+#define __u8	uint8_t
+#define __s64	int64_t
+#define __s32	int32_t
+#define __s16	int16_t
+#define __s8	int8_t
+#define __le32	uint32_t
+
+#include <stdint.h>
 
 /*
  * Common stuff for both V4L1 and V4L2
