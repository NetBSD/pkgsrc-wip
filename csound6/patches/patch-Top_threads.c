$NetBSD: patch-Top_threads.c,v 1.2 2014/08/05 05:12:38 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- Top/threads.c.orig	2019-07-12 21:54:19.000000000 +0000
+++ Top/threads.c
@@ -28,7 +28,7 @@
 
 #ifndef HAVE_GETTIMEOFDAY
 #if defined(LINUX)    || defined(__unix)   || defined(__unix__) || \
-    defined(__MACH__) || defined(__HAIKU__)
+    defined(__MACH__) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__)
 #define HAVE_GETTIMEOFDAY 1
 #endif
 #endif
@@ -167,8 +167,7 @@ PUBLIC void csoundSleep(size_t milliseco
 
 #if !defined(HAVE_PTHREAD_BARRIER_INIT)
 #if !defined( __MACH__)&&!defined(__HAIKU__)&&!defined(ANDROID)&& \
-    !defined(NACL)&&!defined(__CYGWIN__)
-
+    !defined(NACL)&&!defined(__CYGWIN__)&&!defined(__NetBSD__)&&!defined(__DragonFly__)
 typedef struct barrier {
     pthread_mutex_t mut;
     pthread_cond_t cond;
