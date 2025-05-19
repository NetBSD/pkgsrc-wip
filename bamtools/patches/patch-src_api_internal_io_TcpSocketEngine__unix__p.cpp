$NetBSD$

# Portability

--- src/api/internal/io/TcpSocketEngine_unix_p.cpp.orig	2025-05-19 21:34:43.789320412 +0000
+++ src/api/internal/io/TcpSocketEngine_unix_p.cpp
@@ -7,6 +7,7 @@
 // Provides low-level implementation of TCP I/O for all UNIX-like systems
 // ***************************************************************************
 
+#include <netinet/in.h>
 #include "api/internal/io/NetUnix_p.h"
 #include "api/internal/io/TcpSocketEngine_p.h"
 using namespace BamTools;
