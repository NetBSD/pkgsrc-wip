$NetBSD: patch-Source_Core_Core_Src_HW_BBA-TAP_TAP__Unix.cpp,v 1.1 2013/05/08 02:42:59 othyro Exp $

Only enable this function on Linux, as it is not very portable otherwise.

--- Source/Core/Core/Src/HW/BBA-TAP/TAP_Unix.cpp.orig	2012-12-24 20:29:24.000000000 +0000
+++ Source/Core/Core/Src/HW/BBA-TAP/TAP_Unix.cpp
@@ -119,6 +119,7 @@ bool CEXIETHERNET::SendFrame(u8* frame, 
 #endif
 }
 
+#if defined(__linux__)
 void ReadThreadHandler(CEXIETHERNET* self)
 {
 	while (true)
@@ -149,6 +150,7 @@ void ReadThreadHandler(CEXIETHERNET* sel
 		}
 	}
 }
+#endif
 
 bool CEXIETHERNET::RecvInit()
 {
