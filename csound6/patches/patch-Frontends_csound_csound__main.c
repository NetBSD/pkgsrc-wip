$NetBSD$

Add NetBSD and DragonFlyBSD support.

--- Frontends/csound/csound_main.c.orig	2019-07-12 21:54:19.000000000 +0000
+++ Frontends/csound/csound_main.c
@@ -73,7 +73,8 @@ static void nomsg_callback(CSOUND *csoun
 
 #if defined(ANDROID) || (!defined(LINUX) && !defined(SGI) && \
                          !defined(__HAIKU__) && !defined(__BEOS__) && \
-                         !defined(__MACH__) && !defined(__EMSCRIPTEN__))
+                         !defined(__MACH__) && !defined(__EMSCRIPTEN__) \
+                         && !defined(__NetBSD__) && !defined(__DragonFly__))
 static char *signal_to_string(int sig)
 {
     switch(sig) {
@@ -235,7 +236,7 @@ static void signal_handler(int sig)
 }
 
 static const int sigs[] = {
-#if defined(LINUX) || defined(SGI) || defined(sol) || defined(__MACH__)
+#if defined(LINUX) || defined(SGI) || defined(sol) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
   SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGABRT, SIGIOT, SIGBUS,
   SIGFPE, SIGSEGV, SIGPIPE, SIGTERM, SIGXCPU, SIGXFSZ,
 #elif defined(WIN32)
