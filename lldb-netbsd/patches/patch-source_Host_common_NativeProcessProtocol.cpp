$NetBSD$

--- source/Host/common/NativeProcessProtocol.cpp.orig	2016-12-17 10:30:38.000000000 +0000
+++ source/Host/common/NativeProcessProtocol.cpp
@@ -411,6 +411,7 @@ Error NativeProcessProtocol::ResolveProc
 }
 
 #ifndef __linux__
+#if !defined(__NetBSD__)
 // These need to be implemented to support lldb-gdb-server on a given platform.
 // Stubs are
 // provided to make the rest of the code link on non-supported platforms.
@@ -430,3 +431,4 @@ Error NativeProcessProtocol::Attach(lldb
 }
 
 #endif
+#endif
