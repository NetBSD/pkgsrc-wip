$NetBSD$

Add missing bits for ossaudio(3) on NetBSD.

--- libsndio/sio_oss.c.orig	2025-11-15 14:07:59.501355746 +0000
+++ libsndio/sio_oss.c
@@ -37,6 +37,26 @@
 	sizeof(DEVPATH_PREFIX) - 1 +	\
 	sizeof(int) * 3)
 
+#ifndef SNDCTL_DSP_LOW_WATER	/* Low water level control */
+#define SNDCTL_DSP_LOW_WATER	_IOW ('P', 34, int)
+#endif
+
+/*
+ * Additional OSS formats definitions.
+ */
+#ifndef AFMT_U32_LE
+#define AFMT_U32_LE 0x00004000	/* Little endian unsigned 32-bit */
+#endif
+#ifndef AFMT_U32_BE
+#define AFMT_U32_BE 0x00008000	/* Big endian unsigned 32-bit */
+#endif
+#ifndef AFMT_U24_LE
+#define AFMT_U24_LE 0x00040000	/* Little endian unsigned 24-bit */
+#endif
+#ifndef AFMT_U24_BE
+#define AFMT_U24_BE 0x00080000	/* Big endian unsigned 24-bit */
+#endif
+
 struct sio_oss_fmt {
 	int fmt;
 	unsigned int bits;
