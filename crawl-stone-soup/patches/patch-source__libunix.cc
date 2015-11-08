$NetBSD$
Resolve conflicts with term.h

--- libunix.cc.orig	2015-10-31 04:31:32.000000000 +0000
+++ libunix.cc
@@ -26,7 +26,6 @@
 #include <cstring>
 #include <cwchar>
 #include <langinfo.h>
-#include <term.h>
 #include <termios.h>
 #include <unistd.h>
 
