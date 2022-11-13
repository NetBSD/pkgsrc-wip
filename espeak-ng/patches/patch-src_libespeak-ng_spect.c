$NetBSD$

Fix endian.h inclusion on NetBSD

--- src/libespeak-ng/spect.c.orig	2022-04-02 19:24:41.000000000 +0000
+++ src/libespeak-ng/spect.c
@@ -25,7 +25,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+
+#ifdef OS_NETBSD
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 #include <espeak-ng/espeak_ng.h>
 #include <espeak-ng/speak_lib.h>
