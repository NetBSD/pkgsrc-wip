$NetBSD$

Fix PR pkg/59250: lang/gcc12 fails to build on Darwin

--- zlib/zutil.c.orig	2025-04-04 19:41:48.413100010 +0000
+++ zlib/zutil.c
@@ -7,3 +7,2 @@
 
-#include "zutil.h"
 #ifndef Z_SOLO
@@ -11,2 +10,3 @@
 #endif
+#include "zutil.h"
 
