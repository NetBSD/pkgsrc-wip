$NetBSD$

* Add NetBSD support

--- src/services/pam/conversation.cpp.orig	2026-09-19 13:08:02.129046549 +0000
+++ src/services/pam/conversation.cpp
@@ -8,7 +8,7 @@
 #include <qtmetamacros.h>
 #include <sys/signal.h>
 #include <sys/wait.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 
