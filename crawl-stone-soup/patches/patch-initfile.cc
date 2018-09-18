$NetBSD$

We need unistd for unlink(2), depending on UNIX being defined
(the same approach is used in files.cc).

--- initfile.cc.orig	2018-09-17 02:40:29.000000000 +0000
+++ initfile.cc
@@ -88,6 +88,8 @@ extern char **NXArgv;
 #endif
 #elif defined(TARGET_OS_LINUX) || defined(TARGET_OS_CYGWIN)
 #include <unistd.h>
+#elif defined(UNIX)
+#include <unistd.h>
 #endif
 
 const string game_options::interrupt_prefix = "interrupt_";
