$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/utsname.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/utsname.d
@@ -53,6 +53,22 @@ else version(FreeBSD)
 
     int uname(utsname* __name);
 }
+else version(NetBSD)
+{
+    private enum utsNameLength = 256;
+
+    struct utsname
+    {
+        char[utsNameLength] sysname;
+        char[utsNameLength] nodename;
+        char[utsNameLength] release;
+        // The field name is version but version is a keyword in D.
+        char[utsNameLength] update;
+        char[utsNameLength] machine;
+    }
+
+    int uname(utsname* __name);
+}
 else version(CRuntime_Bionic)
 {
     private enum SYS_NMLN = 65;
