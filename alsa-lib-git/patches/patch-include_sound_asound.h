$NetBSD: patch-include_sound_asound.h,v 1.2 2016/02/18 15:15:57 wiz Exp $

--- include/sound/asound.h.orig	2016-02-24 08:33:29.000000000 +0000
+++ include/sound/asound.h
@@ -23,7 +23,12 @@
 #ifndef _UAPI__SOUND_ASOUND_H
 #define _UAPI__SOUND_ASOUND_H
 
+#if defined(__linux__)
 #include <linux/types.h>
+#else
+#include <sys/ioctl.h>
+#define __bitwise
+#endif
 
 #ifndef __KERNEL__
 #include <stdlib.h>
