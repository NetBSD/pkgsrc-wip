$NetBSD$

--- src/Native/System.Native/pal_console.cpp.orig	2016-05-03 12:05:51.000000000 +0000
+++ src/Native/System.Native/pal_console.cpp
@@ -463,7 +463,7 @@ static bool InitializeSignalHandling()
     int rv;
 
     // Hook up signal handlers for use with ctrl-C / ctrl-Break handling
-    newAction.sa_sigaction = &TransferSignalToHandlerLoop,
+    newAction.sa_sigaction = &TransferSignalToHandlerLoop;
     rv = sigaction(SIGINT, &newAction, &g_origSigIntHandler);
     assert(rv == 0);
     rv = sigaction(SIGQUIT, &newAction, &g_origSigQuitHandler);
