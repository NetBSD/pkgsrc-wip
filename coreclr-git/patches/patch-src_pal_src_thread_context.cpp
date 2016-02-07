$NetBSD$

--- src/pal/src/thread/context.cpp.orig	2016-02-06 09:37:43.000000000 +0000
+++ src/pal/src/thread/context.cpp
@@ -19,6 +19,8 @@ Abstract:
 
 --*/
 
+#if 0
+
 #include "pal/palinternal.h"
 #include "pal/dbgmsg.h"
 #include "pal/context.h"
@@ -1351,3 +1353,5 @@ DBG_FlushInstructionCache(
 
     return TRUE;
 }
+
+#endif
