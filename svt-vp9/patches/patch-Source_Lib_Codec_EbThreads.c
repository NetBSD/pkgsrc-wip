$NetBSD$

avoid platform whitelist

--- Source/Lib/Codec/EbThreads.c.orig	2020-10-30 01:51:10.000000000 +0000
+++ Source/Lib/Codec/EbThreads.c
@@ -21,13 +21,11 @@
  ****************************************/
 #ifdef _WIN32
 #include <windows.h>
-#elif __linux__
+#else
 #include <pthread.h>
 #include <semaphore.h>
 #include <time.h>
 #include <errno.h>
-#else
-#error OS/Platform not supported.
 #endif // _WIN32
 #if PRINTF_TIME
 #ifdef _WIN32
