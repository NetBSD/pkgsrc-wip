$NetBSD$

--- Engine/source/platformX86UNIX/x86UNIXProcessControl.cpp.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/source/platformX86UNIX/x86UNIXProcessControl.cpp
@@ -128,7 +128,7 @@ void ProcessControlInit()
 
    // we're not interested in the exit status of child processes, so this 
    // prevents zombies from accumulating.
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
    signal(SIGCHLD, SIG_IGN);
 #else
    signal(SIGCLD, SIG_IGN);
