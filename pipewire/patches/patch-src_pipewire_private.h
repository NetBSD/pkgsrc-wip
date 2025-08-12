$NetBSD$

--- src/pipewire/private.h.orig	2024-09-27 10:02:20.000000000 +0000
+++ src/pipewire/private.h
@@ -11,6 +11,8 @@
 extern "C" {
 #endif
 
+#include <pthread.h>
+#include <sys/time.h>
 #include <sys/socket.h>
 #include <sys/types.h> /* for pthread_t */
 
@@ -24,7 +26,7 @@ extern "C" {
 #include <spa/utils/result.h>
 #include <spa/utils/type-info.h>
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__) || defined(__NetBSD__)
 struct ucred {
 };
 #endif
