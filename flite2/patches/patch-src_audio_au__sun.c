$NetBSD$

--- src/audio/au_sun.c.orig	2009-04-08 13:18:42.000000000 +0000
+++ src/audio/au_sun.c
@@ -45,6 +45,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <sys/ioctl.h>
 #include <sys/filio.h>
 #include <sys/audioio.h>
 #include "cst_string.h"
@@ -76,8 +77,11 @@ cst_audiodev *audio_open_sun(int sps, in
 	    cst_error();
 	}
     }
+#ifdef __OpenBSD__
+    AUDIO_INITINFO(&ainfo);
+#else
     ioctl(fd,AUDIO_GETINFO,&ainfo);
-
+#endif
     switch (fmt)
     {
     case CST_AUDIO_LINEAR16:
