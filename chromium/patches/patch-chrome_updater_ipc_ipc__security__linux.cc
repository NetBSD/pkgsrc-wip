$NetBSD$

--- chrome/updater/ipc/ipc_security_linux.cc.orig	2025-12-12 14:44:01.507108814 +0000
+++ chrome/updater/ipc/ipc_security_linux.cc
@@ -13,7 +13,11 @@ namespace updater {
 
 bool IsConnectionTrusted(
     const named_mojo_ipc_server::ConnectionInfo& connector) {
+#if BUILDFLAG(IS_NETBSD)
+  return connector.credentials.unp_euid == geteuid();
+#else
   return connector.credentials.uid == geteuid();
+#endif
 }
 
 }  // namespace updater
