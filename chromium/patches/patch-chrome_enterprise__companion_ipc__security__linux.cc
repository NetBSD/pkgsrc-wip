$NetBSD$

--- chrome/enterprise_companion/ipc_security_linux.cc.orig	2025-12-12 14:50:20.711039985 +0000
+++ chrome/enterprise_companion/ipc_security_linux.cc
@@ -15,7 +15,11 @@ namespace enterprise_companion {
 IpcTrustDecider CreateIpcTrustDecider() {
   return base::BindRepeating(
       [](const named_mojo_ipc_server::ConnectionInfo& connector) {
+#if BUILDFLAG(IS_NETBSD)
+        return connector.credentials.unp_euid == geteuid();
+#else
         return connector.credentials.uid == geteuid();
+#endif
       });
 }
 
