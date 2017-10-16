$NetBSD$

--- utils/cmixplay.cpp.orig	2015-10-03 21:09:58.000000000 +0000
+++ utils/cmixplay.cpp
@@ -8,7 +8,7 @@
    rev'd again, for OSX support  -JGG, 12/01.
    rev'd again, to work with Doug's AudioDevice class  -JGG, 6/04.
 */
-#if defined(LINUX) || defined(MACOSX)
+#if defined(LINUX) || defined(MACOSX) || defined(NETBSD)
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -26,13 +26,12 @@
 #include <audio_devices.h>
 #include "../src/rtcmix/Option.h"
 
-
 #define PROGNAME  "cmixplay"
 
 #ifdef LINUX
    #include <values.h>
 #endif
-#ifdef MACOSX
+#if defined(MACOSX) || defined(NETBSD)
    #include <limits.h>
 #endif
 
@@ -1175,4 +1174,4 @@ main(int argc, char *argv[])
    return EXIT_SUCCESS;
 }
 
-#endif /* #if defined(LINUX) || defined(MACOSX) */
+#endif /* #if defined(LINUX) || defined(MACOSX) || defined(NETBSD) */
