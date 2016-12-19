$NetBSD$

--- include/lldb/Host/netbsd/HostThreadNetBSD.h.orig	2016-12-17 10:34:14.000000000 +0000
+++ include/lldb/Host/netbsd/HostThreadNetBSD.h
@@ -22,8 +22,7 @@ public:
   HostThreadNetBSD();
   HostThreadNetBSD(lldb::thread_t thread);
 
-  static void SetName(lldb::thread_t tid, llvm::StringRef &name);
-  static void GetName(lldb::thread_t tid, llvm::SmallVectorImpl<char> &name);
+  static void GetName(lldb::tid_t tid, llvm::SmallVectorImpl<char> &name);
 };
 }
 
