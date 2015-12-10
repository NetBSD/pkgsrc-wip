$NetBSD: patch-src_tests_mult-s16-test.c,v 1.1 2014/06/09 13:08:19 ryoon Exp $

Define glibc-specific (?) __WORDSIZE.

--- src/tests/mult-s16-test.c.orig	2015-12-07 11:45:13.000000000 +0000
+++ src/tests/mult-s16-test.c
@@ -23,6 +23,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <math.h>
+#include <limits.h>
 
 #include <pulse/rtclock.h>
 #include <pulsecore/random.h>
@@ -93,9 +94,9 @@ int main(int argc, char *argv[]) {
     if (!getenv("MAKE_CHECK"))
         pa_log_set_level(PA_LOG_DEBUG);
 
-#if __WORDSIZE == 64 || ((ULONG_MAX) > (UINT_MAX))
+#if (SIZEOF_VOIDP * CHAR_BIT) == 64
     pa_log_debug("This seems to be 64-bit code.");
-#elif  __WORDSIZE == 32
+#elif (SIZEOF_VOIDP * CHAR_BIT) == 32
     pa_log_debug("This seems to be 32-bit code.");
 #else
     pa_log_debug("Don't know if this is 32- or 64-bit code.");
