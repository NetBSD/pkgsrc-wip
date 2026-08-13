$NetBSD$

Fix prototype

--- platforms/Cross/plugins/PseudoTTYPlugin/PseudoTTYPlugin.h.orig	2026-08-12 10:17:10.525768186 +0000
+++ platforms/Cross/plugins/PseudoTTYPlugin/PseudoTTYPlugin.h
@@ -1,8 +1,8 @@
 #include "../AsynchFilePlugin/AsynchFilePlugin.h"
 
-int ptyInit();
-int ptyShutdown();
-int ptyForkAndExec();
-int ptyClose();
-int ptyWindowSize();
+int ptyInit(void);
+int ptyShutdown(void);
+int ptyForkAndExec(AsyncFile *, int, char *, int, sqInt *, int);
+int ptyClose(AsyncFile *);
+int ptyWindowSize(AsyncFile *, int, int);
 
