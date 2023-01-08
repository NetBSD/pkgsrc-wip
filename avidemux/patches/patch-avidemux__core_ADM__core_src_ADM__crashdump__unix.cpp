$NetBSD$

NetBSD does not implement sighandler_t.

--- avidemux_core/ADM_core/src/ADM_crashdump_unix.cpp.orig	2022-09-17 13:59:17.000000000 +0000
+++ avidemux_core/ADM_core/src/ADM_crashdump_unix.cpp
@@ -40,8 +40,8 @@
 static ADM_saveFunction *mysaveFunction=NULL;
 static ADM_fatalFunction *myFatalFunction=NULL;
 static ADM_sigIntFunction *mySigIntFunction=NULL;
-static sighandler_t      oldSignalHandlerSigInt;
-static sighandler_t      oldSignalHandlerSigSev;
+static void (*oldSignalHandlerSigInt)(int);
+static void (*oldSignalHandlerSigSev)(int);
 void sig_segfault_handler(int signo);
 void sig_sigint_handler(int signo);
 
