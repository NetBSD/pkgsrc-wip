$NetBSD$
#add netinit
--- src/api/internal/io/TcpSocketEngine_unix_p.cpp.orig	2018-03-12 15:14:05.061616533 +0000
+++ src/api/internal/io/TcpSocketEngine_unix_p.cpp
@@ -12,6 +12,8 @@
 using namespace BamTools;
 using namespace BamTools::Internal;
 
+#include <netinet/in.h>
+
 #ifdef SUN_OS
 #include <sys/filio.h>
 #endif
