$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/ipc.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/ipc.d
@@ -115,6 +115,32 @@ else version( FreeBSD )
 
     key_t ftok(in char*, int);
 }
+else version( NetBSD )
+{
+
+    struct ipc_perm
+    {
+        uid_t   cuid;
+        gid_t   cgid;
+        uid_t   uid;
+        gid_t   gid;
+        mode_t  mode;
+        ushort  seq;
+        key_t   key;
+    }
+
+    enum IPC_CREAT      = 0x0100; // 01000
+    enum IPC_EXCL       = 0x0200; // 02000
+    enum IPC_NOWAIT     = 0x0400; // 04000
+
+    enum key_t IPC_PRIVATE = 0;
+
+    enum IPC_RMID       = 0;
+    enum IPC_SET        = 1;
+    enum IPC_STAT       = 2;
+
+    key_t ftok(in char*, int);
+}
 else version( CRuntime_Bionic )
 {
     // All except ftok are from the linux kernel headers.
