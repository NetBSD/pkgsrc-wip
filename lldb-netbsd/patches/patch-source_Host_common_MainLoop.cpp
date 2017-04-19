$NetBSD$

--- source/Host/common/MainLoop.cpp.orig	2017-04-19 03:59:22.000000000 +0000
+++ source/Host/common/MainLoop.cpp
@@ -7,7 +7,7 @@
 //
 //===----------------------------------------------------------------------===//
 
-#include "llvm/Config/config.h"
+#include "llvm/Config/llvm-config.h"
 
 #include "lldb/Host/MainLoop.h"
 #include "lldb/Utility/Error.h"
