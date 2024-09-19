$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/wait.d.orig	2020-05-07 08:52:17.154678602 +0000
+++ runtime/druntime/src/core/sys/posix/sys/wait.d
@@ -255,6 +255,11 @@ else version (DragonFlyBSD)
     enum WCONTINUED     = 4;
     enum WNOWAIT        = 8;
 }
+else version (NetBSD)
+{
+    enum WSTOPPED       = WUNTRACED;
+    enum WNOWAIT        = 0x0010000;
+}
 else version (Solaris)
 {
     enum WEXITED = 1;
