$NetBSD$

--- tests/dtls/dtls-stress.c.orig	2015-01-19 17:38:09.000000000 +0000
+++ tests/dtls/dtls-stress.c
@@ -98,6 +98,8 @@
 #include <time.h>
 #include <sys/wait.h>
 
+#undef strerror
+
 #if _POSIX_TIMERS && (_POSIX_TIMERS - 200112L) >= 0
 
 // {{{ types
