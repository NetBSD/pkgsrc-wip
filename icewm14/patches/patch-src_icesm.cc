$NetBSD$

--- src/icesm.cc.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/icesm.cc
@@ -9,6 +9,8 @@
 #include <wordexp.h>
 #endif
 
+#include <signal.h>
+
 char const *ApplicationName = ICESMEXE;
 
 class SessionManager: public YApplication {
