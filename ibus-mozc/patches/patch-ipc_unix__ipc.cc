$NetBSD: patch-ipc_unix__ipc.cc,v 1.1 2013/01/14 14:00:55 ryo-on Exp $

--- ipc/unix_ipc.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/unix_ipc.cc
@@ -41,7 +41,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/un.h>
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
 #include <sys/ucred.h>
 #endif
 #include <sys/wait.h>
@@ -171,6 +171,22 @@ bool IsPeerValid(int socket, pid_t *pid)
 #endif  // __arm__
 #endif
 
+#if defined(OS_NETBSD)
+  struct uucred peer_cred;
+  int peer_cred_len = sizeof(peer_cred);
+  if (getsockopt(socket, 0, LOCAL_PEEREID,
+                 reinterpret_cast<void *>(&peer_cred),
+                 reinterpret_cast<socklen_t *>(&peer_cred_len)) < 0) {
+    LOG(ERROR) << "cannot get peer credential. Not a Unix socket?";
+    return false;
+  }
+
+  if (peer_cred.cr_uid != ::geteuid()) {
+    LOG(WARNING) << "uid mismatch." << peer_cred.cr_uid << "!=" << ::geteuid();
+    return false;
+  }
+#endif
+
   return true;
 }
 
