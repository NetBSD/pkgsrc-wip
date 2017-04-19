$NetBSD$

--- source/Host/common/TCPSocket.cpp.orig	2017-04-19 03:59:22.000000000 +0000
+++ source/Host/common/TCPSocket.cpp
@@ -17,7 +17,7 @@
 #include "lldb/Host/MainLoop.h"
 #include "lldb/Utility/Log.h"
 
-#include "llvm/Config/config.h"
+#include "llvm/Config/llvm-config.h"
 #include "llvm/Support/raw_ostream.h"
 
 #ifndef LLDB_DISABLE_POSIX
