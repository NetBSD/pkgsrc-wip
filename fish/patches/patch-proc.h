$NetBSD: patch-proc.h,v 1.1 2012/08/17 13:53:51 mwilhelmy Exp $

Fix missing include

--- proc.h.orig	2009-03-08 14:46:47.000000000 +0000
+++ proc.h
@@ -16,6 +16,8 @@
 #include <unistd.h>
 #include <sys/time.h>
 
+#include <termios.h>
+
 #include "util.h"
 #include "io.h"
 
