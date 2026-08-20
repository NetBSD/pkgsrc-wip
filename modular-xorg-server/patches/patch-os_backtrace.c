$NetBSD: patch-os_backtrace.c,v 1.3 2022/05/22 21:29:58 dholland Exp $

Use standard headers, needed on Solaris.

--- os/backtrace.c.orig	2026-08-20 01:02:10.000000000 +0000
+++ os/backtrace.c
@@ -30,6 +30,7 @@
 
 #include <errno.h>
 #include <string.h>
+#include <unistd.h>
 
 #ifndef WIN32
 #include <sys/wait.h>
