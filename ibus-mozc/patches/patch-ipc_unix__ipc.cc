$NetBSD: patch-ipc_unix__ipc.cc,v 1.3 2013/01/16 12:35:59 ryo-on Exp $

--- ipc/unix_ipc.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/unix_ipc.cc
@@ -28,7 +28,7 @@
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 // skip all if non-Linux or Android.
-#if defined(OS_LINUX) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_ANDROID)) || defined(OS_NETBSD)
 
 #include "ipc/ipc.h"
 
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
+  if (getsockopt(socket, SOL_SOCKET, LOCAL_PEEREID,
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
 
@@ -435,7 +451,7 @@ IPCServer::IPCServer(const string &name,
                SO_REUSEADDR,
                reinterpret_cast<char *>(&on),
                sizeof(on));
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
   addr.sun_len = SUN_LEN(&addr);
   const size_t sun_len = sizeof(addr);
 #else
@@ -534,4 +550,4 @@ void IPCServer::Terminate() {
 
 };  // namespace mozc
 
-#endif  // OS_LINUX && !OS_ANDROID
+#endif  // (OS_LINUX && !OS_ANDROID) || OS_NETBSD
