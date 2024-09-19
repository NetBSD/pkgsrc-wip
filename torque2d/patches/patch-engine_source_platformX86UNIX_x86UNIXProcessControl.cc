$NetBSD$

--- engine/source/platformX86UNIX/x86UNIXProcessControl.cc.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platformX86UNIX/x86UNIXProcessControl.cc
@@ -145,7 +145,7 @@ void ProcessControlInit()
 
    // we're not interested in the exit status of child processes, so this 
    // prevents zombies from accumulating.
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
    signal(SIGCHLD, SIG_IGN);
 #else
    signal(SIGCLD, SIG_IGN);
