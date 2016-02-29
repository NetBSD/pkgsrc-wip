$NetBSD: patch-include_sound_asound.h,v 1.2 2016/02/18 15:15:57 wiz Exp $

--- include/sound/asound.h.orig	2016-02-24 08:33:29.000000000 +0000
+++ include/sound/asound.h
@@ -23,8 +23,13 @@
 #ifndef _UAPI__SOUND_ASOUND_H
 #define _UAPI__SOUND_ASOUND_H
 
+#if defined(__linux__)
 #include <linux/types.h>
-
+#else
+#include <sys/ioctl.h>
+#define __bitwise
+typedef uint32_t __u32;
+#endif
 #ifndef __KERNEL__
 #include <stdlib.h>
 #endif
@@ -415,7 +420,7 @@ struct snd_pcm_sw_params {
 
 struct snd_pcm_channel_info {
 	unsigned int channel;
-	__kernel_off_t offset;		/* mmap offset */
+	off_t offset;			/* mmap offset */
 	unsigned int first;		/* offset to first sample in bits */
 	unsigned int step;		/* samples distance in bits */
 };
@@ -884,7 +889,7 @@ struct snd_ctl_elem_info {
 	snd_ctl_elem_type_t type;	/* R: value type - SNDRV_CTL_ELEM_TYPE_* */
 	unsigned int access;		/* R: value access (bitmask) - SNDRV_CTL_ELEM_ACCESS_* */
 	unsigned int count;		/* count of values */
-	__kernel_pid_t owner;		/* owner's PID of this control */
+	pid_t owner;			/* owner's PID of this control */
 	union {
 		struct {
 			long min;		/* R: minimum value */
