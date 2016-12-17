$NetBSD$

--- include/lldb/Host/netbsd/Ptrace.h.orig	2016-12-17 13:20:19.546597274 +0000
+++ include/lldb/Host/netbsd/Ptrace.h
@@ -9,8 +9,8 @@
 
 // This file defines ptrace functions & structures
 
-#ifndef liblldb_Host_linux_Ptrace_h_
-#define liblldb_Host_linux_Ptrace_h_
+#ifndef liblldb_Host_netbsd_Ptrace_h_
+#define liblldb_Host_netbsd_Ptrace_h_
 
 #include <sys/ptrace.h>
 
@@ -54,4 +54,4 @@ typedef int __ptrace_request;
 
 #define LLDB_PTRACE_NT_ARM_TLS 0x401 // ARM TLS register
 
-#endif // liblldb_Host_linux_Ptrace_h_
+#endif // liblldb_Host_netbsd_Ptrace_h_
