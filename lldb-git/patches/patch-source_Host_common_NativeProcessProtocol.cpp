$NetBSD$

--- source/Host/common/NativeProcessProtocol.cpp.orig	2017-03-20 15:16:01.000000000 +0000
+++ source/Host/common/NativeProcessProtocol.cpp
@@ -504,7 +504,7 @@ Error NativeProcessProtocol::ResolveProc
     return Error("failed to retrieve a valid architecture from the exe module");
 }
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
 // These need to be implemented to support lldb-gdb-server on a given platform.
 // Stubs are
 // provided to make the rest of the code link on non-supported platforms.
