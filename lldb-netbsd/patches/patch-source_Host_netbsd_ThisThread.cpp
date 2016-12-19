$NetBSD$

--- source/Host/netbsd/ThisThread.cpp.orig	2016-12-17 10:30:35.000000000 +0000
+++ source/Host/netbsd/ThisThread.cpp
@@ -12,15 +12,15 @@
 
 #include "llvm/ADT/SmallVector.h"
 
-#include <pthread.h>
+#include <lwp.h>
 #include <string.h>
 
 using namespace lldb_private;
 
 void ThisThread::SetName(llvm::StringRef name) {
-  HostNativeThread::SetName(::pthread_self(), name);
+//  HostNativeThread::SetName(_lwp_self(), name);
 }
 
 void ThisThread::GetName(llvm::SmallVectorImpl<char> &name) {
-  HostNativeThread::GetName(::pthread_self(), name);
+  HostNativeThread::GetName(_lwp_self(), name);
 }
