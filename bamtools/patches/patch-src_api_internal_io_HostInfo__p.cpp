$NetBSD$

# Potability

--- src/api/internal/io/HostInfo_p.cpp.orig	2018-03-12 15:13:26.429616632 +0000
+++ src/api/internal/io/HostInfo_p.cpp
@@ -11,6 +11,8 @@
 using namespace BamTools;
 using namespace BamTools::Internal;
 
+#include <netinet/in.h>
+
 // platorm-specifics
 #ifdef _WIN32
 #include "api/internal/io/NetWin_p.h"
