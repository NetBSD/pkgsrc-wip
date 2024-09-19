$NetBSD: patch-tctool.cpp,v 1.1 2012/04/12 18:06:32 gschwarz Exp $

--- tctool.cpp.orig	2012-04-12 19:51:41.000000000 +0200
+++ tctool.cpp	2012-04-12 19:53:40.000000000 +0200
@@ -33,6 +33,9 @@
 #include <string.h>
 #include <unistd.h>
 #include <signal.h>
+#ifdef CSTDLIB
+#include <cstdlib>
+#endif
 
 std::string                      options = "I:m:i:r:t:p:c:MUdsSCRh";
 std::string                      ethDev  = "eth0";
