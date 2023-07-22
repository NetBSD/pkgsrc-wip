$NetBSD$

alloca is in stdlib.h on NetBSD.

--- jfaudiolib/src/driver_alsa.c.orig	2023-03-21 20:06:34.000000000 +0000
+++ jfaudiolib/src/driver_alsa.c
@@ -33,7 +33,11 @@
 #include <alsa/asoundlib.h>
 #include <unistd.h>
 #include <math.h>
+#if defined(__linux)
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 
 enum {
    ALSAErr_Warning = -2,
