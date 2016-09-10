$NetBSD$

Is byteswap.h needed (on Linux)? Breaks build on NetBSD.

--- jack/pcm_jack.c.orig	2013-04-11 11:43:08.000000000 +0000
+++ jack/pcm_jack.c
@@ -20,7 +20,6 @@
  *
  */
 
-#include <byteswap.h>
 #include <sys/shm.h>
 #include <sys/types.h>
 #include <sys/socket.h>
