$NetBSD$

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- qemu_mode/qemu/audio/audio.c.orig	2017-05-31 22:53:05.000000000 +0000
+++ qemu_mode/qemu/audio/audio.c
@@ -1173,7 +1173,7 @@ int AUD_read (SWVoiceIn *sw, void *buf, 
         return 0;
     }
 
-    bytes = sw->hw->pcm_ops->read (sw, buf, size);
+    bytes = (*sw->hw->pcm_ops->read )(sw, buf, size);
     return bytes;
 }
 
