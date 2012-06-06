$NetBSD: patch-audio_audio.c,v 1.1 2012/06/06 21:23:41 ryo-on Exp $

--- /usr/tmp/wip/qemu/work/qemu-1.1.0/audio/audio.c.orig	2012-06-06 21:16:21.000000000 +0000
+++ /usr/tmp/wip/qemu/work/qemu-1.1.0/audio/audio.c
@@ -1170,7 +1170,7 @@ int AUD_read (SWVoiceIn *sw, void *buf, 
         return 0;
     }
 
-    bytes = sw->hw->pcm_ops->read (sw, buf, size);
+    bytes = (*sw->hw->pcm_ops->read) (sw, buf, size);
     return bytes;
 }
 
