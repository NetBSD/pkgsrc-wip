$NetBSD$

Fix build with non-Linux systems. __NR_inotify_init isn't used anyway.

--- inotify-cxx.h.orig	2012-04-06 22:19:27.000000000 +0000
+++ inotify-cxx.h
@@ -35,11 +35,6 @@
 #include <sys/syscall.h>
 #include <sys/inotify.h>
 
-// Use this if syscalls not defined
-#ifndef __NR_inotify_init
-#include <sys/inotify-syscalls.h>
-#endif // __NR_inotify_init
-
 /// Event struct size
 #define INOTIFY_EVENT_SIZE (sizeof(struct inotify_event))
 
