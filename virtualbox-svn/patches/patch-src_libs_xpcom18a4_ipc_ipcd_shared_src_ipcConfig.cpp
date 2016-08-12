$NetBSD$

--- src/libs/xpcom18a4/ipc/ipcd/shared/src/ipcConfig.cpp.orig	2016-08-05 16:18:14.000000000 +0000
+++ src/libs/xpcom18a4/ipc/ipcd/shared/src/ipcConfig.cpp
@@ -39,7 +39,7 @@
 #elif defined(XP_OS2) && defined(XP_OS2_NATIVEIPC)
 #else
 #include <string.h>
-#ifdef XP_UNIX
+#if defined(XP_UNIX) || defined(__NetBSD__) // XXX
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
