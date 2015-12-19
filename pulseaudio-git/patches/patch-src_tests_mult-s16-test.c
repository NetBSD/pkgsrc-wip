$NetBSD$

--- src/tests/mult-s16-test.c.orig	2015-12-05 22:03:14.000000000 +0000
+++ src/tests/mult-s16-test.c
@@ -93,12 +93,10 @@ int main(int argc, char *argv[]) {
     if (!getenv("MAKE_CHECK"))
         pa_log_set_level(PA_LOG_DEBUG);
 
-#if __WORDSIZE == 64 || ((ULONG_MAX) > (UINT_MAX))
-    pa_log_debug("This seems to be 64-bit code.");
-#elif  __WORDSIZE == 32
-    pa_log_debug("This seems to be 32-bit code.");
+#if HAVE_FAST_64BIT_OPERATIONS
+    pa_log_debug("Detected CPU with fast 64-bit operations.");
 #else
-    pa_log_debug("Don't know if this is 32- or 64-bit code.");
+    pa_log_debug("Not detected CPU with fast 64-bit operations.");
 #endif
 
     s = suite_create("Mult-s16");
