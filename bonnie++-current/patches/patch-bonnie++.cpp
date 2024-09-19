$NetBSD: patch-bonnie++.cpp,v 1.1.1.1 2012/06/01 15:26:59 hfath Exp $

--- bonnie++.cpp.orig	2012-06-01 14:51:34.000000000 +0000
+++ bonnie++.cpp
@@ -49,6 +49,10 @@
 #include <string.h>
 #include <signal.h>
 
+#ifndef SA_SIGINFO
+#define SA_SIGINFO      0x0040
+#endif
+
 void usage();
 
 class CGlobalItems
